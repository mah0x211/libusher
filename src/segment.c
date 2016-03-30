/*
 *  segment.c
 *  libusher
 *
 *  Created by Masatoshi Teruya on 2014/07/29.
 *  Copyright (C) 2014 Masatoshi Teruya
 *
 *  Permission is hereby granted, free of charge, to any person obtaining a copy
 *  of this software and associated documentation files (the "Software"), to deal
 *  in the Software without restriction, including without limitation the rights
 *  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *  copies of the Software, and to permit persons to whom the Software is
 *  furnished to do so, subject to the following conditions:
 *
 *  The above copyright notice and this permission notice shall be included in
 *  all copies or substantial portions of the Software.
 *
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL THE
 *  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 *  THE SOFTWARE.
 */

#include "usher_private.h"

#define HAVE_VARCHILD( seg )        ((seg) && (seg)->varchild >= 0)
#define GET_VARCHILD( seg )         ((seg)->children[(seg)->varchild])
#define GET_VARCHILD_TYPE( seg )    (((seg)->children[(seg)->varchild])->type)
#define SET_VARCHILD( seg, idx )    ((seg)->varchild = idx)
#define SET_VARCHILD_NIL( seg )     ((seg)->varchild = -1)

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


usher_error_t seg_alloc( usher_seg_t **pseg, const usher_t *u, uint8_t *path,
                         uint8_t prev, uintptr_t udata )
{
    usher_error_t err = USHER_ENOMEM;
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
                    // should try to find close delimiter if ptr is same of path
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
                        // cannot allocate unnamed variable-segment
                        if( ( ptr - path ) == 1 ){
                            pdealloc( seg );
                            return USHER_EFORMAT;
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
            len = strlen( (char*)path );
        }
        
        if( ( seg->path = pnalloc( len + 1, uint8_t ) ) )
        {
            memcpy( seg->path, path, len );
            seg->path[len] = 0;
            seg->len = len;
            SET_VARCHILD_NIL( seg );
            
            // have children
            if( ptr && *ptr )
            {
                if( ( seg->children = pnalloc( 1, usher_seg_t* ) ) )
                {
                    // allocate child-segment with remaining path
                    usher_seg_t *child = NULL;
                    
                    err = seg_alloc( &child, u, ptr, prev, udata );
                    if( err == USHER_OK )
                    {
                        seg->nchildren = 1;
                        seg->children[0] = child;
                        child->parent = seg;
                        // set varchild index
                        if( child->type & USHER_SEG_VAR ){
                            SET_VARCHILD( seg, 0 );
                        }
                        *pseg = seg;
                        
                        return USHER_OK;
                    }
                    pdealloc( seg->children );
                }
                pdealloc( seg->path );
            }
            else {
                seg->udata = udata;
                seg->type |= USHER_SEG_EOS;
                *pseg = seg;
                
                return USHER_OK;
            }
        }

        pdealloc( seg );
    }
    
    return err;
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


static inline usher_error_t append2child( usher_seg_t *seg, usher_seg_t *child )
{
    usher_seg_t **children = prealloc( seg->children, seg->nchildren + 1,
                                       usher_seg_t* );
    
    if( children )
    {
        uint8_t c = *child->path;
        uint8_t idx = 0;
        
        seg->children = children;
        seg->nchildren++;
        child->parent = seg;
        
        if( seg->nchildren == 1 )
        {
            children[0] = child;
            // set varchild index
            if( child->type & USHER_SEG_VAR ){
                SET_VARCHILD( seg, idx );
            }
        }
        else
        {
            idx = bsearch_child_idx( children, seg->nchildren, c );
            // set varchild index
            if( child->type & USHER_SEG_VAR ){
                SET_VARCHILD( seg, idx );
            }
            
            if( seg->nchildren == 2 ){
                children[1-idx] = children[0];
                children[idx] = child;
            }
            else
            {
                uint8_t right = seg->nchildren - 1;
                
                // move to right
                for(; right > idx; right-- ){
                    children[right] = children[right-1];
                }
                // insert at middle position
                children[right] = child;
            }
        }
        
        return USHER_OK;
    }
    
    // no-mem
    return USHER_ENOMEM;
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


static inline usher_error_t segment2edge( const usher_t *u, usher_seg_t *seg,
                                          size_t pos, usher_seg_t *sibling )
{
    usher_seg_t *branch = NULL;
    usher_error_t err = seg_alloc( &branch, u, seg->path + pos,
                                   ( pos ) ? *(seg->path + pos - 1) : 0, 0 );
    
    if( err == USHER_OK )
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
            // sort by first byte value
            uint8_t sidx = *branch->path < *sibling->path;
            uint8_t bidx = 1 - sidx;

            seg->len -= branch->len;
            // TODO: should release unused memory
            seg->path[seg->len] = 0;
            seg->nchildren = 2;
            seg->type = USHER_SEG_NODE;
            seg->udata = 0;

            // sort by first byte value
            seg->children[bidx] = branch;
            seg->children[sidx] = sibling;
            
            branch->parent = seg;
            sibling->parent = seg;
            
            // check variable-segment
            if( branch->type & USHER_SEG_VAR ){
                SET_VARCHILD( seg, bidx );
            }
            else if( sibling->type & USHER_SEG_VAR ){
                SET_VARCHILD( seg, sidx );
            }
            else {
                SET_VARCHILD_NIL( seg );
            }
            
            // change children's parent
            for(; i < branch->nchildren; i++ ){
                branch->children[i]->parent = branch;
            }
            
            return USHER_OK;
        }
        
        // no-mem
        err = USHER_ENOMEM;
        // revert
        seg->children = branch->children;
        pdealloc( branch );
    }
    
    return err;
}


static inline usher_error_t branchoff( usher_t *u, usher_seg_t *seg,
                                       size_t pos, uintptr_t udata )
{
    uint8_t *path = pnalloc( pos + 1, uint8_t );
    usher_error_t err = USHER_ENOMEM;
    
    if( path )
    {
        usher_seg_t *parent = NULL;
        
        memcpy( path, seg->path, pos );
        path[pos] = 0;
        
        // allocate new segment
        err = seg_alloc( &parent, u, path, 0, udata );
        if( err == USHER_OK )
        {
            pdealloc( path );
            parent->parent = seg->parent;
            err = append2child( parent, seg );
            if( err == USHER_OK )
            {
                // update parent children
                if( parent->parent ){
                    uint8_t idx = bsearch_child_idx( parent->parent->children,
                                                     parent->parent->nchildren,
                                                     *parent->path );
                    
                    parent->parent->children[idx] = parent;
                }
                // change root segment
                else {
                    u->root = parent;
                }
                // erase parent path string
                seg->len -= pos;
                memmove( seg->path, seg->path + pos, seg->len );
                seg->path[seg->len] = 0;
                
                return USHER_OK;
            }
            seg_dealloc( parent, NULL );
        }
        else {
            pdealloc( path );
        }
    }

    return err;
}


usher_error_t seg_add( usher_t *u, usher_seg_t *seg, uint8_t *path,
                       uintptr_t udata, int replace )
{
    usher_error_t err = USHER_OK;
    usher_seg_t *child = NULL;
    usher_state_t state;
    usher_match_t match = seg_get( seg, path, &state );
    uint8_t prev = *(state.remain - 1);
    
    // reached to tail of segment
    if( match == USHER_MATCH_LONG )
    {
        // cannot split variable segment
        if( state.seg->type & USHER_SEG_VAR ){
            return USHER_ESPLIT;
        }

        // append child
        err = seg_alloc( &child, u, state.remain, prev, udata );
        if( err == USHER_OK )
        {
            err = append2child( state.seg, child );
            if( err != USHER_OK ){
                pdealloc( child );
            }
        }
        
        return err;
    }
    // different
    else if( match == USHER_MATCH_DIFF )
    {
        // cannot split variable segment
        if( state.seg->type & USHER_SEG_VAR ){
            return USHER_ESPLIT;
        }
        
        // split node and append child segment
        err = seg_alloc( &child, u, state.remain, prev, udata );
        if( err == USHER_OK )
        {
            err = segment2edge( u, state.seg, state.cur - state.seg->path,
                                child );
            if( err != USHER_OK ){
                pdealloc( child );
            }
        }
        
        return err;

    }
    // path is too short
    else if( match == USHER_MATCH_SHORT )
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
    else if( state.seg->type & USHER_SEG_EOS )
    {
        if( replace == 0 ){
            return USHER_EALREADY;
        }
        // call user defined finalizer
        else if( u->callback ){
            u->callback( (void*)state.seg->udata );
        }
        state.seg->udata = udata;
    }
    // change to node
    else {
        state.seg->type |= USHER_SEG_EOS;
        state.seg->udata = udata;
    }
    
    return err;
}


usher_match_t seg_get( usher_seg_t *seg, uint8_t *path, usher_state_t *state )
{
    usher_match_t match = USHER_MATCH;
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
            match = USHER_MATCH_LONG;
            goto RET_RESULT;
        }
        // different
        else if( *m != *k ){
            match = USHER_MATCH_DIFF;
            goto RET_RESULT;
        }
        
CHECK_NEXT:
        k++;
        m++;
    }
    
    // path is too short
    // not end of string
    if( *m ){
        match = USHER_MATCH_SHORT;
    }

RET_RESULT:
    *state = (usher_state_t){
        .seg = seg,
        .cur = m,
        .remain = k,
        .idx = idx
    };
    
    return match;
}


usher_error_t seg_remove( usher_t *u, usher_seg_t *seg, uint8_t idx )
{
    // end-of-segment
    if( seg->type & USHER_SEG_EOS )
    {
        usher_seg_t *parent = seg->parent;
        
        if( parent && seg->type & USHER_SEG_VAR ){
            SET_VARCHILD_NIL( parent );
        }
        
        // do not deallocate if segment has children
        if( seg->nchildren )
        {
            // call user defined finalizer
            if( u->callback ){
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
                    for( i = idx; i < seg->nchildren; i++ ){
                        seg->children[i] = seg->children[i+1];
                    }
                    seg->children[i] = NULL;
                }
                // merge
                else if( seg->nchildren == 1 )
                {
                    usher_seg_t *child = NULL;
                    
                    seg->children[0] = seg->children[1 - idx];
                    seg->children[1] = NULL;
                    child = seg->children[0];
                    
                    if( !( seg->type & USHER_SEG_EOS ) &&
                        !( child->type & USHER_SEG_VAR ) )
                    {
                        size_t len = seg->len + child->len;
                        uint8_t *path = prealloc( seg->path, len + 1, uint8_t );
                        
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
                    SET_VARCHILD_NIL( seg );
                }
                // plain path-segment
                else
                {
                    if( parent ){
                        idx = bsearch_child_idx( parent->children,
                                                 parent->nchildren,
                                                 *seg->path );
                    }
                    else {
                        idx = 0;
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
    
    return USHER_EINVAL;
}


static inline usher_error_t glob_add( usher_glob_t *glob, usher_seg_t *varchild,
                                      uint8_t *val, size_t len )
{
    usher_glob_item_t *items = prealloc( glob->items, glob->nitems + 1,
                                         usher_glob_item_t );
    
    // no-mem
    if( items ){
        items[glob->nitems].name = varchild->path + 1;
        items[glob->nitems].head = val;
        items[glob->nitems].tail= val + len;
        glob->items = items;
        glob->nitems++;
        return USHER_OK;
    }
    
    return USHER_ENOMEM;
}


usher_error_t seg_exec( const usher_t *u, usher_seg_t *seg, uint8_t *path,
                        usher_glob_t *pglob )
{
    usher_error_t err = USHER_OK;
    const uint8_t sym_open = u->delim[USHER_DELIM_OPEN];
    const uint8_t sym_close = u->delim[USHER_DELIM_CLOSE];
    uint8_t *m = seg->path;
    uint8_t *k = path;
    uint8_t *varhead = k;
    usher_seg_t *tail = seg;
    usher_seg_t *child = NULL;
    usher_glob_t glob = {
        .seg = NULL,
        .eos = NULL,
        .nitems = 0,
        .items = NULL
    };

    // parse path-string
    while( *k )
    {
        // variable segment
        if( seg->type & USHER_SEG_VAR )
        {
CHECK_VARCHILD:
            // search close symbole of variable-segment
            if( *k == sym_close ){ k++; }
            while( *k && *k != sym_close ){
                k++;
            }
            
            // found child segment
            if( *k && ( child = seg_getchild( seg, *k ) ) )
            {
                // substract variable-segment
                err = glob_add( &glob, seg, varhead, k - varhead );
                if( err != USHER_OK ){
                    goto RET_ERROR;
                }

                tail = seg = child;
                m = seg->path;
                varhead = k;
            }
            else if( seg->type & USHER_SEG_EOS )
            {
                if( glob.nitems &&
                    glob.items[glob.nitems-1].name == seg->path ) {
                    goto MERGE_PARENT;
                }

                // substract variable-segment
                err = glob_add( &glob, seg, varhead, strlen( (char*)varhead ) );
                if( err != USHER_OK ){
                    goto RET_ERROR;
                }
                goto RET_STATUS;
            }
            // lookup eos segment from parents
            else if( seg->parent && glob.nitems ){
                tail = seg = seg->parent;
                goto MERGE_PARENT;
            }
            // not found
            else {
                err = USHER_ENOENT;
                goto RET_STATUS;
            }
        }
        // reached to tail of segment-path
        else if( !*m )
        {
            // found child
            if( ( child = seg_getchild( seg, *k ) ) )
            {
                tail = seg = child;
                // jump if child is variable
                if( seg->type & USHER_SEG_VAR ){
                    goto CHECK_VARCHILD;
                }
                m = seg->path;
            }
            // jump if have varchild
            else if( HAVE_VARCHILD( seg ) ){
                tail = seg = GET_VARCHILD( seg );
                goto CHECK_VARCHILD;
            }
            // lookup eos segment from parents
            else if( glob.nitems ){
                goto MERGE_PARENT;
            }
            // not found
            else {
                err = USHER_ENOENT;
                goto RET_STATUS;
            }
        }
        // found different
        else if( *m != *k )
        {
            if( seg->parent )
            {
                // jump if have varchild
                if( HAVE_VARCHILD( seg->parent ) ){
                    tail = seg = GET_VARCHILD( seg->parent );
                    goto CHECK_VARCHILD;
                }
                // jump if parent is VEOS
                else if( seg->parent->type == USHER_SEG_VEOS ){
                    tail = seg = seg->parent;
                    goto CHECK_VARCHILD;
                }
            }
            // lookup eos segment from parents
            else if( glob.nitems ){
                goto MERGE_PARENT;
            }
            
            // not found
            err = USHER_ENOENT;
            tail = tail->parent;
            goto RET_STATUS;
        }
        
        // check next char
CHECK_NEXT:
        // found open symbol of variable-segment
        if( *k == sym_open ){
            varhead = k + 1;
        }
        k++;
        m++;
    }

    // path is too short
    if( *m )
    {
        err = USHER_ENOENT;
        // parent not found
        if( !( seg = seg->parent ) ){
            goto RET_STATUS;
        }
        // substract variable-segment
        else if( HAVE_VARCHILD( seg ) &&
                 GET_VARCHILD_TYPE( seg ) & USHER_SEG_EOS )
        {
            seg = GET_VARCHILD( seg );
            err = glob_add( &glob, seg, varhead, strlen( (char*)varhead ) );
            if( err != USHER_OK ){
                goto RET_ERROR;
            }
        }
        else if( glob.nitems )
        {
            tail = seg;

MERGE_PARENT:
            do
            {
                if( seg->type & USHER_SEG_VAR )
                {
                    // deallocate last glob
                    varhead = glob.items[--glob.nitems].head;
                    if( seg->type == USHER_SEG_VEOS ){
                        break;
                    }
                }
            } while( ( seg = seg->parent ) );
            
            // not found
            if( !seg ){
                err = USHER_ENOENT;
                goto RET_STATUS;
            }

            err = glob_add( &glob, seg, varhead, strlen( (char*)varhead ) );
            if( err != USHER_OK ){
                goto RET_ERROR;
            }
        }
    }
    else if( !( seg->type & USHER_SEG_EOS ) ){
        err = USHER_ENOENT;
    }

RET_STATUS:
    // set current segment
    glob.seg = seg;
    if( err == USHER_OK ){
        glob.eos = seg;
    }
    else if( ( seg = tail ) )
    {
        do
        {
            if( seg->type & USHER_SEG_EOS ){
                glob.eos = seg;
                break;
            }
        } while( ( seg = seg->parent ) );
    }
    // set result
    *pglob = glob;
    return err;

RET_ERROR:
    usher_glob_dealloc( &glob );
    
    return err;
}


// dump to JSON format
void seg_dump( usher_seg_t *seg, int lv, int last )
{
    int obj_pad = lv * 4;
    int pad = obj_pad + 2 - 1;
    
    printf( "%*s{\n", obj_pad, "" );
    printf( "%*s \"path\": \"%s\",\n", pad, "", seg->path );
    printf( "%*s \"len\": %zu,\n", pad, "", seg->len );
    
    if( seg->type )
    {
        printf( "%*s \"type\": [", pad, "" );
        if( seg->type == USHER_SEG_VEOS ){
            printf( "\"VAR\", \"EOS\"" );
        }
        else if( seg->type == USHER_SEG_VAR ){
            printf( "\"VAR\"" );
        }
        else {
            printf( "\"EOS\"" );
        }
        printf( "],\n" );
    }
    else {
        printf( "%*s \"type\": [\"NONE\"],\n", pad, "" );
    }
    
    printf( "%*s \"parent\": \"%s\",\n", pad, "", ( seg->parent ) ? (char*)seg->parent->path : "NONE" );
    
    if( HAVE_VARCHILD( seg ) ){
        printf( "%*s \"varchild\": \"%s\",\n", pad, "", (char*)GET_VARCHILD( seg )->path );
    }
    
    if( seg->nchildren )
    {
        uint8_t i;
        
        printf( "%*s \"nchildren\": %u,\n", pad, "", seg->nchildren );
        printf( "%*s \"children\": [\n", pad, "" );
        for( i = 0; i < seg->nchildren; i++ ){
            seg_dump( seg->children[i], lv + 1, seg->nchildren - 1 == i );
        }
        printf( "%*s ]\n", pad, "" );
    }
    else {
        printf( "%*s \"nchildren\": %u\n", pad, "", seg->nchildren );
    }
    
    printf( "%*s}%s\n", obj_pad, "", last ? "" : "," );
}


