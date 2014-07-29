//
//  segment.c
//  libusher
//
//  Created by Masatoshi Teruya on 2014/07/29.
//  Copyright (c) 2014年 Msatoshi Teruya. All rights reserved.
//

#include "usher_private.h"


usher_seg_t *seg_alloc( uint8_t *path, uint8_t prev )
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
            if( *ptr == '$' && prev == USHER_SEG_DELIMITER )
            {
                // should try to find segment delimiter if ptr is same as path
                if( ptr == path )
                {
                    // set type as variable-segment
                    seg->type = USHER_SEG_VAR;
                    while( *ptr )
                    {
                        if( *ptr == USHER_SEG_DELIMITER ){
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
        
        len = ptr - path;
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
                    if( ( seg->children[0] = seg_alloc( ptr, prev ) ) ){
                        seg->nchildren = 1;
                        return seg;
                    }
                    pdealloc( seg->children );
                }
                pdealloc( seg->path );
            }
            else
            {
                seg->children = NULL;
                seg->nchildren = 0;
                // set type as node-segment
                // NOTE: variable-segment have no trailing-slash
                if( seg->path[len-1] == '/' ){
                    seg->type = USHER_SEG_NODE;
                }
                // set type as leaf-segment
                else {
                    seg->type |= USHER_SEG_LEAF;
                }
                
                return seg;
            }
        }
        seg = pdealloc( seg );
    }
    
    return seg;
}


// error: no-mem
int seg_append2child( usher_seg_t *seg, usher_seg_t *child )
{
    usher_seg_t **children = prealloc( seg->children, seg->nchildren + 1, usher_seg_t* );
    
    if( children ){
        children[seg->nchildren] = child;
        seg->children = children;
        seg->nchildren++;
        
        return 0;
    }
    
    return -1;
}


int seg_split( usher_seg_t *seg, size_t pos, usher_seg_t *sibling )
{
    usher_seg_t *branch = seg_alloc( seg->path + pos, *(seg->path + pos - 1) );
    
    if( branch )
    {
        branch->children = seg->children;
        branch->nchildren = seg->nchildren;
        // create new children
        if( ( seg->children = prealloc( NULL, 2, usher_seg_t* ) ) )
        {
            seg->len -= branch->len;
            // TODO: should release unused memory
            seg->path[seg->len] = 0;
            seg->nchildren = 2;
            seg->type = USHER_SEG_EDGE;
            seg->children[0] = branch;
            seg->children[1] = sibling;
            return 0;
        }
        
        // revert
        seg->children = branch->children;
        seg->nchildren = branch->nchildren;
        pdealloc( branch );
    }
    
    return -1;
}



int seg_add( usher_seg_t *seg, uint8_t *path )
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
            if( seg->children )
            {
                size_t i = 0;
                printf( "check children: %zu\n", seg->nchildren );
                
                for(; i < seg->nchildren; i++ )
                {
                    child = seg->children[i];
                    printf( "child[%zu]: %s -- %s\n", i, child->path, k );
                    if( *child->path == *k ){
                        seg = child;
                        m = seg->path;
                        printf( "check next\n" );
                        goto CHECK_NEXT;
                    }
                }
            }
            
            printf( "create children\n" );
            // cannot append child to leaf-segment
            if( seg->type & USHER_SEG_LEAF ){
                errno = EINVAL;
            }
            // append child
            else if( ( child = seg_alloc( k, prev ) ) )
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
                break;
            }
            // create child segment
            else if( ( child = seg_alloc( k, prev ) ) )
            {
                // split node and append child segment
                if( seg_split( seg, m - seg->path, child ) == 0 ){
                    printf("parent  %zd -> %s\n", seg->len, seg->path );
                    printf("sibling %zd -> %s\n", child->len, child->path );
                    break;
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


