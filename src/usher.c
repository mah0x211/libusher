/*
 *  usher.c
 *  libusher
 *
 *  Created by Masatoshi Teruya on 2014/07/28.
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
        case USHER_EFORMAT:
            return "cannot create unnamed variable segment";
        case USHER_ESPLIT:
            return "cannot split variable/leaf segment";
        case USHER_EALREADY:
            return "segment already defined";
        case USHER_ENOENT:
            return "segment not found";
    }
    
    return "unknown error";
}


usher_t *usher_alloc( const char *delim, usher_dealloc_cb callback )
{
    usher_t *u = pcalloc( usher_t );
    
    if( u )
    {
        if( delim ){
            memcpy( u->delim, delim, sizeof( uint8_t ) * 3 );
        }
        u->callback = callback;
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


usher_error_t usher_set( usher_t *u, const char *path, void *val, int replace )
{
    // error: path-string is null
    if( path && *path )
    {
        if( u->root ){
            return seg_add( u, u->root, (uint8_t*)path, (uintptr_t)val, replace );
        }
        
        return seg_alloc( &u->root, u, (uint8_t*)path, 0, (uintptr_t)val );
    }
    
    return USHER_EINVAL;
}


usher_match_t usher_get( usher_t *u, const char *path, usher_state_t *state )
{
    if( path && *path && u->root ){
        return seg_get( u->root, (uint8_t*)path, state );
    }
    
    return USHER_MATCH_NONE;
}


usher_error_t usher_remove( usher_t *u, const char *path )
{
    if( !path || !*path ){
        return USHER_EINVAL;
    }
    else if( u->root )
    {
        usher_state_t state;
        
        if( seg_get( u->root, (uint8_t*)path, &state ) == USHER_MATCH ){
            return seg_remove( u, state.seg, state.idx );
        }
    }

    return USHER_ENOENT;
}


usher_error_t usher_remove_segment( usher_t *u, usher_state_t *state )
{
    if( !state ){
        return USHER_EINVAL;
    }
    else if( u->root ){
        return seg_remove( u, state->seg, state->idx );
    }

    return USHER_ENOENT;
}


usher_error_t usher_exec( usher_t *u, const char *path, usher_glob_t *glob )
{
    if( path && *path && u->root ){
        return seg_exec( u, u->root, (uint8_t*)path, glob );
    }
    
    return USHER_ENOENT;
}

void usher_glob_dealloc( usher_glob_t *glob )
{
    if( glob->items ){
        pdealloc( glob->items );
    }
}

void usher_dump( usher_t *u )
{
    if( u->root ){
        seg_dump( u->root, 0, 1 );
    }
}

