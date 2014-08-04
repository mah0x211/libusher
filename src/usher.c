//
//  route.c
//  libusher
//
//  Created by Masatoshi Teruya on 2014/07/28.
//  Copyright (c) 2014年 Msatoshi Teruya. All rights reserved.
//

#include "usher_private.h"
#include <limits.h>


char *usher_strerror( usher_error_t err )
{
    switch( err ){
        case USHER_OK:
            return "no error";
        case USHER_EINVAL:
            return "invalid argument";
        case USHER_ENOMEM:
            return "could not allocate memory";
        case USHER_EAPPEND:
            return "cannot append segment to leaf-segment";
        case USHER_ESPLIT:
            return "cannot split variable/leaf segment";
        case USHER_EALREADY:
            return "segment already defined";
        case USHER_ENOENT:
            return "segment not found";
    }
    
    return "unknown error";
}


usher_t *usher_alloc( usher_dealloc_cb callback )
{
    usher_t *u = pcalloc( usher_t );
    
    if( u )
    {
        u->callback = callback;
        if( !( u->root = seg_alloc( (uint8_t*)"/", 0, 0 ) ) ){
            u = pdealloc( u );
        }
    }
    
    return u;
}


void usher_dealloc( usher_t *u )
{
    if( u->root ){
        seg_dealloc( u->root, u->callback );
    }
    pdealloc( u );
}


usher_error_t usher_add( usher_t *u, const char *path, void *val )
{
    // error: path-string is null
    if( path && *path )
    {
        if( u->root ){
            return seg_add( u->root, (uint8_t*)path, (uintptr_t)val );
        }
        else if( !( u->root = seg_alloc( (uint8_t*)path, 0, (uintptr_t)val) ) ){
            return USHER_ENOMEM;
        }
        else {
            return USHER_OK;
        }
    }
    
    return USHER_EINVAL;
}


usher_match_t usher_get( usher_t *u, const char *path, usher_state_t *state )
{
    if( path && *path ){
        return seg_get( u->root, (uint8_t*)path, state );
    }
    
    return USHER_MATCH_NONE;
}

usher_error_t usher_remove( usher_t *u, const char *path )
{
    if( path && *path ){
        return seg_remove( u->root, (uint8_t*)path, u->callback );
    }
    
    return USHER_EINVAL;
}

void usher_dump( usher_t *u )
{
    if( u->root ){
        seg_dump( u->root, 0 );
    }
}

