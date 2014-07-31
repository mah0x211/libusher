//
//  segment.c
//  libusher
//
//  Created by Masatoshi Teruya on 2014/07/29.
//  Copyright (c) 2014年 Msatoshi Teruya. All rights reserved.
//

#include "usher_private.h"


static inline size_t bsearch_child_idx( usher_seg_t **children, size_t len,
                                        uint8_t c )
{
    if( len > 2 )
    {
        size_t left = 0;
        size_t right = len - 1;
        size_t mid = 0;
        
        // find middle
        while( left < right )
        {
            mid = left + ( ( right - left ) >> 1 );
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


usher_seg_t *seg_alloc( uint8_t *path, uint8_t prev, uintptr_t udata )
{
    usher_seg_t *seg = palloc( usher_seg_t );
    
    if( seg )
    {
        size_t len = 0;
        uint8_t *ptr = path;
        
        printf( "alloc: %s\n", ptr );
        // check parametalized segment
        while( *ptr )
        {
            printf( "check: %s\n", ptr );
            // found variable-delimiter
            if( *ptr == USHER_DELIM_VAR && prev == USHER_DELIM_SEG )
            {
                // should try to find segment delimiter if ptr is same as path
                if( ptr == path )
                {
                    // set type as variable-segment
                    seg->type = USHER_SEG_VAR;
                    ptr++;
                    while( *ptr )
                    {
                        if( *ptr == USHER_DELIM_SEG ){
                            prev = *ptr;
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
        if( ( seg->path = pnalloc( len + 1, uint8_t ) ) )
        {
            memcpy( seg->path, path, len );
            seg->path[len] = 0;
            seg->len = len;
            printf( "path: %s, remain: %s\n", seg->path, ptr );
            
            // have children
            if( *ptr )
            {
                // set type as node-segment
                seg->type |= USHER_SEG_NODE;
                if( ( seg->children = pnalloc( 1, usher_seg_t* ) ) )
                {
                    // allocate child-segment with remaining path
                    if( ( seg->children[0] = seg_alloc( ptr, prev, udata ) ) ){
                        seg->nchildren = 1;
                        seg->children[0]->parent = seg;
                        return seg;
                    }
                    pdealloc( seg->children );
                }
                pdealloc( seg->path );
            }
            else
            {
                seg->parent = NULL;
                seg->children = NULL;
                seg->nchildren = 0;
                seg->udata = udata;
                // set type as node-segment
                // NOTE: variable-segment have no trailing-slash
                if( seg->path[len-1] == USHER_DELIM_SEG ){
                    seg->type = USHER_SEG_NODE|USHER_SEG_EOS;
                }
                // set type as leaf-segment
                else {
                    seg->type |= USHER_SEG_LEAF|USHER_SEG_EOS;
                }
                
                return seg;
            }
        }
        seg = pdealloc( seg );
    }
    
    return seg;
}


void seg_dealloc( usher_seg_t *seg, usher_dealloc_cb callback )
{
    printf("dealloc: %s ----------------------------------\n", seg->path );
    
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



// error: no-mem
int seg_append2child( usher_seg_t *seg, usher_seg_t *child )
{
    usher_seg_t **children = prealloc( seg->children, seg->nchildren + 1, usher_seg_t* );
    
    if( children )
    {
        uint8_t c = *child->path;
        
        seg->children = children;
        seg->nchildren++;
        child->parent = seg;
        
        if( seg->nchildren == 1 ){
            children[0] = child;
        }
        else
        {
            size_t mid = bsearch_child_idx( children, seg->nchildren, c );
            
            if( seg->nchildren == 2 ){
                children[1-mid] = children[0];
                children[mid] = child;
            }
            else
            {
                size_t right = seg->nchildren - 1;
                
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
    
    return -1;
}


usher_seg_t *seg_getchild_idx( usher_seg_t *seg, uint8_t k, size_t *idx )
{
    usher_seg_t *child = NULL;
    
    // check children
    if( seg->children )
    {
        size_t mid = bsearch_child_idx( seg->children, seg->nchildren, k );
        
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


int seg_split( usher_seg_t *seg, size_t pos, usher_seg_t *sibling )
{
    usher_seg_t *branch = seg_alloc( seg->path + pos, *(seg->path + pos - 1), 0 );
    
    if( branch )
    {
        branch->type = seg->type;
        branch->children = seg->children;
        branch->nchildren = seg->nchildren;
        branch->udata = seg->udata;
        // create new children
        if( ( seg->children = prealloc( NULL, 2, usher_seg_t* ) ) )
        {
            size_t i = 0;
            
            seg->len -= branch->len;
            // TODO: should release unused memory
            seg->path[seg->len] = 0;
            seg->nchildren = 2;
            seg->type = USHER_SEG_EDGE;
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
    
    return -1;
}


int seg_add( usher_seg_t *seg, uint8_t *path, uintptr_t udata )
{
    uint8_t *m = seg->path;
    uint8_t *k = path;
    uint8_t prev = 0;
    usher_seg_t *child = NULL;
    
    printf("append %s : %zu\n", path, strlen( (char*)path ) );
    // parse path-string
    while( *k )
    {
        printf( "k: %3d -> %s, %3d -> %s\n", *k, k, *m, m );
        // reached to tail of segment
        if( !*m )
        {
            // check children
            if( ( child = seg_getchild( seg, *k ) ) ){
                seg = child;
                m = seg->path;
                printf( "check next: %s, type %d\n", seg->path, seg->type );
                goto CHECK_NEXT;
            }
            
            printf( "create children\n" );
            // cannot append child to leaf-segment
            if( seg->type & USHER_SEG_LEAF ){
                errno = EINVAL;
            }
            // append child
            else if( ( child = seg_alloc( k, prev, udata ) ) )
            {
                if( seg_append2child( seg, child ) == 0 ){
                    return 0;
                }
                pdealloc( child );
            }
            break;
        }
        // different
        else if( *m != *k )
        {
            printf("split: %s %zu, type %d\n", m, m - seg->path, seg->type );
            // cannot split variable segment
            if( seg->type & USHER_SEG_VAR ){
                errno = EINVAL;
            }
            // create child segment
            else if( ( child = seg_alloc( k, prev, udata ) ) )
            {
                // split node and append child segment
                if( seg_split( seg, (size_t)(m - seg->path), child ) == 0 ){
                    printf("parent  %zd -> %s\n", seg->len, seg->path );
                    printf("sibling %zd -> %s\n", child->len, child->path );
                    return 0;
                }
                pdealloc( child );
            }
            break;
        }
        
CHECK_NEXT:
        prev = *k;
        k++;
        m++;
    }
    
    // already registered
    if( !*k ){
        errno = EALREADY;
    }
    
    return -1;
}


int seg_get( usher_seg_t **seg, usher_seg_t *src, uint8_t *path )
{
    uint8_t *m = src->path;
    uint8_t *k = path;
    usher_seg_t *child = NULL;
    
    printf("search %s : %zu\n", path, strlen( (char*)path ) );
    // parse path-string
    while( *k )
    {
        printf( "k: %3d -> %s, %3d -> %s\n", *k, k, *m, m );
        // reached to tail of segment
        if( !*m )
        {
            // check children
            if( ( child = seg_getchild( src, *k ) ) ){
                src = child;
                m = src->path;
                printf( "check next: %s, type %d\n", src->path, src->type );
                goto CHECK_NEXT;
            }
            
            *seg = src;
            return USHER_MATCH_SEG;
        }
        // different
        else if( *m != *k ){
            *seg = src;
            return USHER_MATCH_SUB;
        }
        
CHECK_NEXT:
        k++;
        m++;
    }
    
    printf("found: %p\n", src );
    *seg = src;
    // not end of string
    if( *m ){
        return USHER_MATCH_SUB;
    }
    
    return USHER_MATCH;
}


int seg_remove( usher_seg_t *seg, uint8_t *path, usher_dealloc_cb callback )
{
    uint8_t *m = seg->path;
    uint8_t *k = path;
    
    // parse path-string
    while( *k )
    {
        // reached to tail of segment
        if( !*m )
        {
            size_t idx = 0;
            usher_seg_t *child = seg_getchild_idx( seg, *k, &idx );
            
            // remove children
            if( child && seg_remove( child, k, callback ) == 0 )
            {
                printf("%s -- nhildren: %zd/%zd\n", seg->path, idx, seg->nchildren );
                seg->nchildren--;
                if( seg->nchildren > 1 )
                {
                    for(; idx < seg->nchildren; idx++ ){
                        printf("swap: %zd <- %zd\n", idx, idx+1);
                        seg->children[idx] = seg->children[idx+1];
                    }
                    printf("set null: %zd/%zd\n", idx, seg->nchildren );
                    seg->children[idx] = NULL;
                }
                else if( seg->nchildren == 1 )
                {
                    printf("swap[%zd]: %zd <- %zd\n", idx, 0, 1 - idx );
                    seg->children[0] = seg->children[1-idx];
                    seg->children[1] = NULL;
                    child = seg->children[0];
                    
                    // merge
                    if( !( seg->type & USHER_SEG_EOS ) &&
                        !( child->type & USHER_SEG_VAR ) )
                    {
                        size_t len = seg->len + child->len;
                        uint8_t *newpath = prealloc( seg->path, len + 1, uint8_t );
                        
                        // no-mem
                        if( !newpath ){
                            return -1;
                        }
                        printf("marge path: %s <- %s: ", seg->path, child->path );
                        memcpy( newpath + seg->len, child->path, child->len );
                        newpath[len] = 0;
                        printf("%s\n", newpath );
                        // release existing children
                        pdealloc( seg->children );
                        
                        seg->path = newpath;
                        seg->len = len;
                        seg->type = child->type;
                        seg->children = child->children;
                        seg->nchildren = child->nchildren;
                        seg->udata = child->udata;
                    }
                }
                else if( !( seg->type & USHER_SEG_EOS ) ){
                    seg_dealloc( seg, callback );
                    return 0;
                }
            }
            
            return -1;
        }
        // different
        else if( *m != *k ){
            return -1;
        }
        
        k++;
        m++;
    }
    
    // not end of string or not end-of-segment
    if( *m || !( seg->type & USHER_SEG_EOS ) ){
        return -1;
    }
    
    printf("should remove this segment\n");
    seg_dump( seg, 0 );
    seg_dealloc( seg, callback );
    
    return 0;
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


