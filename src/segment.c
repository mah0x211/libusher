//
//  segment.c
//  libusher
//
//  Created by Masatoshi Teruya on 2014/07/29.
//  Copyright (c) 2014年 Msatoshi Teruya. All rights reserved.
//

#include "usher_private.h"


static inline uint8_t bsearch_child_idx( usher_seg_t **children, uint8_t len,
                                         uint8_t c )
{
    if( len > 2 )
    {
        uint8_t left = 0;
        uint8_t right = len - 1;
        uint8_t mid = 0;
        
        // find middle
        while( left < right )
        {
            mid = ( right + left ) >> 1;
            if( c > *children[mid]->path ){
                left = mid + 1;
            }
            else {
                right = mid;
            }
        }
        
        return left;
    }
    else if( len == 2 && c > *children[0]->path ){
        return 1;
    }
    
    return 0;
}


usher_seg_t *seg_alloc( const usher_t *u, uint8_t *path, uint8_t prev,
                        uintptr_t udata )
{
    usher_seg_t *seg = pcalloc( usher_seg_t );
    
    if( seg )
    {
        size_t len = 0;
        uint8_t *ptr = NULL;
        
        if( *u->delim )
        {
            uint8_t sym_open = u->delim[USHER_DELIM_OPEN];
            uint8_t sym_var = u->delim[USHER_DELIM_VAR];
            uint8_t sym_close = u->delim[USHER_DELIM_CLOSE];
            
            ptr = path;
            // check parametalized segment
            while( *ptr )
            {
                // found variable-delimiter
                if( *ptr == sym_var && ( !prev || prev == sym_open ) )
                {
                    // should try to find close delimiter if ptr is same as path
                    if( ptr == path )
                    {
                        // set type as variable-segment
                        seg->type = USHER_SEG_VAR;
                        ptr++;
                        while( *ptr )
                        {
                            prev = *ptr;
                            if( *ptr == sym_close ){
                                break;
                            }
                            ptr++;
                        }
                    }
                    break;
                }
                prev = *ptr;
                ptr++;
            }
        
            len = (size_t)(ptr - path);
        }
        else {
            len = strlen( path );
        }
        
        if( ( seg->path = pnalloc( len + 1, uint8_t ) ) )
        {
            memcpy( seg->path, path, len );
            seg->path[len] = 0;
            seg->len = len;
            
            // have children
            if( ptr && *ptr )
            {
                if( ( seg->children = pnalloc( 1, usher_seg_t* ) ) )
                {
                    // allocate child-segment with remaining path
                    usher_seg_t *child = seg_alloc( u, ptr, prev, udata );
                    
                    if( child )
                    {
                        seg->nchildren = 1;
                        seg->children[0] = child;
                        child->parent = seg;
                        if( child->type & USHER_SEG_VAR ){
                            seg->varchild = child;
                        }
                        
                        return seg;
                    }
                    // no-mem
                    pdealloc( seg->children );
                }
                // no-mem
                pdealloc( seg->path );
            }
            else {
                seg->udata = udata;
                seg->type |= USHER_SEG_EOS;
                return seg;
            }
        }
        seg = pdealloc( seg );
    }
    
    return seg;
}


void seg_dealloc( usher_seg_t *seg, usher_dealloc_cb callback )
{
    if( seg->children )
    {
        while( seg->nchildren ){
            seg_dealloc( seg->children[--seg->nchildren], callback );
        }
        pdealloc( seg->children );
    }
    // call user defined finalizer
    if( callback && seg->type & USHER_SEG_EOS ){
        callback( (void*)seg->udata );
    }
    
    pdealloc( seg->path );
    pdealloc( seg );
}


static inline int append2child( usher_seg_t *seg, usher_seg_t *child )
{
    usher_seg_t **children = prealloc( seg->children, seg->nchildren + 1, usher_seg_t* );
    
    if( children )
    {
        uint8_t c = *child->path;
        
        seg->children = children;
        seg->nchildren++;
        child->parent = seg;
        if( child->type & USHER_SEG_VAR ){
            seg->varchild = child;
        }
        
        if( seg->nchildren == 1 ){
            children[0] = child;
        }
        else
        {
            uint8_t mid = bsearch_child_idx( children, seg->nchildren, c );
            
            if( seg->nchildren == 2 ){
                children[1-mid] = children[0];
                children[mid] = child;
            }
            else
            {
                uint8_t right = seg->nchildren - 1;
                
                // move to right
                for(; right > mid; right-- ){
                    children[right] = children[right-1];
                }
                // insert at middle position
                children[right] = child;
            }
        }
        
        return 0;
    }
    
    // no-mem
    return -1;
}


usher_seg_t *seg_getchild_idx( usher_seg_t *seg, uint8_t k, uint8_t *idx )
{
    usher_seg_t *child = NULL;
    
    // check children
    if( seg->children )
    {
        uint8_t mid = bsearch_child_idx( seg->children, seg->nchildren, k );
        
        if( *seg->children[mid]->path == k )
        {
            child = seg->children[mid];
            if( idx ){
                *idx = mid;
            }
        }
    }
    
    return child;
}


static inline int segment2edge( const usher_t *u, usher_seg_t *seg, size_t pos,
                                usher_seg_t *sibling )
{
    usher_seg_t *branch = seg_alloc( u, seg->path + pos, *(seg->path + pos - 1), 0 );
    
    if( branch )
    {
        branch->type = seg->type;
        branch->varchild = seg->varchild;
        branch->children = seg->children;
        branch->nchildren = seg->nchildren;
        branch->udata = seg->udata;
        // create new children
        if( ( seg->children = prealloc( NULL, 2, usher_seg_t* ) ) )
        {
            uint8_t i = 0;
            
            seg->len -= branch->len;
            // TODO: should release unused memory
            seg->path[seg->len] = 0;
            seg->nchildren = 2;
            seg->type = USHER_SEG_NODE;
            seg->udata = 0;
            // sort by first byte value
            if( *branch->path < *sibling->path ){
                seg->children[0] = branch;
                seg->children[1] = sibling;
            }
            else {
                seg->children[0] = sibling;
                seg->children[1] = branch;
            }
            branch->parent = seg;
            sibling->parent = seg;
            
            // check variable-segment
            if( branch->type & USHER_SEG_VAR ){
                seg->varchild = branch;
            }
            else if( sibling->type & USHER_SEG_VAR ){
                seg->varchild = sibling;
            }
            else {
                seg->varchild = NULL;
            }
            
            // change children's parent
            for(; i < branch->nchildren; i++ ){
                branch->children[i]->parent = branch;
            }
            
            return 0;
        }
        
        // revert
        seg->children = branch->children;
        pdealloc( branch );
    }
    
    // no-mem
    return -1;
}


static inline int branchoff( const usher_t *u, usher_seg_t *seg, size_t pos, uintptr_t udata )
{
    uint8_t *path = pnalloc( pos + 1, uint8_t );
    
    if( path )
    {
        usher_seg_t *parent = NULL;
        
        memcpy( path, seg->path, pos );
        path[pos] = 0;
        
        // allocate new segment
        if( ( parent = seg_alloc( u, path, 0, udata ) ) )
        {
            pdealloc( path );
            parent->parent = seg->parent;
            if( append2child( parent, seg ) == 0 )
            {
                // update parent children
                uint8_t idx = bsearch_child_idx( parent->parent->children,
                                                 parent->parent->nchildren,
                                                 *parent->path );
                
                parent->parent->children[idx] = parent;
                // erase parent path string
                seg->len -= pos;
                memmove( seg->path, seg->path + pos, seg->len );
                seg->path[seg->len] = 0;
                
                return 0;
            }
            seg_dealloc( parent, NULL );
        }
        else {
            pdealloc( path );
        }
    }

    return -1;
}


usher_error_t seg_add( const usher_t *u, usher_seg_t *seg, uint8_t *path,
                       uintptr_t udata )
{
    usher_seg_t *child = NULL;
    usher_state_t state;
    int rc = seg_get( seg, path, &state );
    uint8_t prev = *(state.remain - 1);
    
    // reached to tail of segment
    if( rc == USHER_MATCH_LONG )
    {
        // append child
        child = seg_alloc( u, state.remain, prev, udata );
        if( child )
        {
            if( append2child( state.seg, child ) == 0 ){
                return 0;
            }
            pdealloc( child );
        }
        
        return USHER_ENOMEM;
    }
    // different
    else if( rc == USHER_MATCH_DIFF )
    {
        // cannot split variable segment
        if( state.seg->type & USHER_SEG_VAR && state.seg->path != state.cur ){
            return USHER_ESPLIT;
        }
        
        // split node and append child segment
        child = seg_alloc( u, state.remain, prev, udata );
        if( child )
        {
            if( segment2edge( u, state.seg, state.cur - state.seg->path,
                              child ) == 0 ){
                return 0;
            }
            pdealloc( child );
        }
        return USHER_ENOMEM;

    }
    // path is too short
    else if( rc == USHER_MATCH_SHORT )
    {
        // cannot split variable segment
        if( state.seg->type & USHER_SEG_VAR ){
            return USHER_ESPLIT;
        }
        else if( branchoff( u, state.seg, state.cur - state.seg->path,
                            udata ) != 0 ){
            return USHER_ENOMEM;
        }
    }
    // USHER_MATCH
    // already registered
    else if( state.seg->type & USHER_SEG_EOS ){
        return USHER_EALREADY;
    }
    // change to node
    else {
        state.seg->type = USHER_SEG_EOS;
        state.seg->udata = udata;
    }
    
    return USHER_OK;
}


usher_match_t seg_get( usher_seg_t *seg, uint8_t *path, usher_state_t *state )
{
    int rc = USHER_MATCH;
    uint8_t *m = seg->path;
    uint8_t *k = path;
    usher_seg_t *child = NULL;
    uint8_t idx = 0;
    
    // parse path-string
    while( *k )
    {
        // reached to tail of segment
        if( !*m )
        {
            // check children
            if( ( child = seg_getchild_idx( seg, *k, &idx ) ) ){
                seg = child;
                m = seg->path;
                goto CHECK_NEXT;
            }
            
            // path is too long
            rc = USHER_MATCH_LONG;
            goto RET_RESULT;
        }
        // different
        else if( *m != *k ){
            rc = USHER_MATCH_DIFF;
            goto RET_RESULT;
        }
        
CHECK_NEXT:
        k++;
        m++;
    }
    
    // path is too short
    // not end of string
    if( *m ){
        rc = USHER_MATCH_SHORT;
    }

RET_RESULT:
    *state = (usher_state_t){
        .seg = seg,
        .cur = m,
        .remain = k,
        .idx = idx
    };
    
    return rc;
}


usher_error_t seg_remove( usher_t *u, usher_seg_t *seg, uint8_t *path )
{
    usher_state_t state;
    
    switch( seg_get( seg, path, &state ) )
    {
        case USHER_MATCH:
            seg = state.seg;
            // end-of-segment
            if( seg->type & USHER_SEG_EOS )
            {
                usher_seg_t *parent = seg->parent;
                
                if( parent && seg->type & USHER_SEG_VAR ){
                    parent->varchild = NULL;
                }
                
                // do not deallocate if segment has children
                if( seg->nchildren )
                {
                    // call user defined finalizer
                    if( u->callback && seg->type & USHER_SEG_EOS ){
                        u->callback( (void*)seg->udata );
                    }
                    // unset flag
                    seg->type &= ~USHER_SEG_EOS;
                    seg->udata = 0;
                }
                else
                {
                    uint8_t i;
                    
                    // deallocate target segment
                    seg_dealloc( seg, u->callback );
                    
CHECK_PARENT:
                    if( parent )
                    {
                        seg = parent;
                        parent = seg->parent;
                        seg->nchildren--;
                        
                        // fill in blank
                        if( seg->nchildren > 1 )
                        {
                            for( i = state.idx; i < seg->nchildren; i++ ){
                                seg->children[i] = seg->children[i+1];
                            }
                            seg->children[i] = NULL;
                        }
                        // merge
                        else if( seg->nchildren == 1 )
                        {
                            usher_seg_t *child = NULL;
                            
                            seg->children[0] = seg->children[1-state.idx];
                            seg->children[1] = NULL;
                            child = seg->children[0];
                            
                            if( !( seg->type & USHER_SEG_EOS ) &&
                                !( child->type & USHER_SEG_VAR ) )
                            {
                                size_t len = seg->len + child->len;
                                
                                path = prealloc( seg->path, len + 1, uint8_t );
                                // no-mem
                                if( !path ){
                                    return USHER_ENOMEM;
                                }
                                memcpy( path + seg->len, child->path, child->len );
                                path[len] = 0;
                                // release existing children
                                pdealloc( seg->children );
                                
                                seg->path = path;
                                seg->len = len;
                                seg->type = child->type;
                                seg->children = child->children;
                                seg->nchildren = child->nchildren;
                                seg->varchild = child->varchild;
                                seg->udata = child->udata;
                                
                                // change children's parent
                                for( i = 0; i < seg->nchildren; i++ ){
                                    seg->children[i]->parent = seg;
                                }
                                
                                // remove child
                                child->children = NULL;
                                seg_dealloc( child, NULL );
                            }
                        }
                        // deallocate unused children
                        else if( seg->type & USHER_SEG_EOS ){
                            seg->children = pdealloc( seg->children );
                            seg->varchild = NULL;
                        }
                        // plain path-segment
                        else
                        {
                            if( parent ){
                                seg_getchild_idx( parent, *seg->path, &state.idx );
                            }
                            else {
                                state.idx = 0;
                            }
                            seg_dealloc( seg, u->callback );
                            goto CHECK_PARENT;
                        }
                    }
                    // set null to root
                    else {
                        u->root = NULL;
                    }
                }
                
                return USHER_OK;
            }
        break;
    }
    
    return USHER_ENOENT;
}


void seg_dump( usher_seg_t *seg, int lv )
{
    usher_seg_t *child;
    size_t i;
    
    printf(
        "lv:%5d| %*s +'%s':%zu -> nchildren: %zu, type: %d\n",
        lv, lv * 2, "", seg->path, seg->len, seg->nchildren, seg->type
    );
        
    for( i = 0; i < seg->nchildren; i++ )
    {
        child = seg->children[i];
        
        printf(
            "lv:%2d-%02zu| %*s -'%s':%zu -> nchildren: %zu, type: %d\n",
            lv, i, lv * 2 + 2, "", child->path, child->len, child->nchildren, child->type
        );
        if( child->nchildren ){
            seg_dump( child, lv + 1 );
        }
    }
}


