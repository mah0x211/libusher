//
//  route.c
//  libusher
//
//  Created by Masatoshi Teruya on 2014/07/28.
//  Copyright (c) 2014年 Msatoshi Teruya. All rights reserved.
//

#include "usher_private.h"
#include <limits.h>


usher_t *usher_alloc( void )
{
    usher_t *u = pcalloc( usher_t );
    
    if( u )
    {
        if( !( u->root = seg_alloc( (uint8_t*)"/", 0 ) ) ){
            u = pdealloc( u );
        }
    }
    
    return u;
}


void usher_dealloc( usher_t *u )
{
    if( u->root ){
        pdealloc( u->root );
    }
    pdealloc( u );
}


int usher_add( usher_t *u, const char *path, void *val )
{
    // error: path-string is null or not valid absolute-path format.
    if( !path || !*path || *path != USHER_SEG_DELIMITER ){
        errno = EINVAL;
        return -1;
    }
    else {
        return seg_add( u->root, (uint8_t*)path );
    }
    
    return -1;
}


void usher_dump( usher_t *u )
{
    if( u->root ){
        seg_dump( u->root, 0 );
    }
}

