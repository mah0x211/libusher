/*
 *  usher.h
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


#ifndef ___LIBUSHER_H___
#define ___LIBUSHER_H___

#include <string.h>
#include <stdlib.h>
#include <stdint.h>


// errors
typedef enum {
    USHER_OK = 0,
    USHER_EINVAL,
    USHER_ENOMEM,
    USHER_EFORMAT,
    USHER_ESPLIT,
    USHER_EALREADY,
    USHER_ENOENT
} usher_error_t;

char *usher_strerror( usher_error_t err );


#define USHER_SEG_NODE  0x0
#define USHER_SEG_VAR   0x1
// end-of-segment
#define USHER_SEG_EOS   0x2
#define USHER_SEG_VEOS  0x3

typedef struct _usher_seg {
    // userdata
    uintptr_t udata;
    size_t len;
    uint8_t *path;
    int16_t varchild;
    uint8_t type;
    uint8_t nchildren;
    struct _usher_seg *parent;
    struct _usher_seg **children;
} usher_seg_t;

typedef void(*usher_dealloc_cb)( void* );

#define USHER_DELIM_OPEN    0
#define USHER_DELIM_VAR     1
#define USHER_DELIM_CLOSE   2

typedef struct {
    usher_seg_t *root;
    usher_dealloc_cb callback;
    // delimiter: [delim_open][delim_var]<*parameter_name>[delim_close]
    uint8_t delim[3];
} usher_t;

usher_t *usher_alloc( const char delim[], usher_dealloc_cb callback );
void usher_dealloc( usher_t *u );

usher_error_t usher_set( usher_t *u, const char *path, void *val, int replace );
#define usher_add( u, path, val )       usher_set( u, path, val, 0 )
#define usher_replace( u, path, val )   usher_set( u, path, val, 1 )

usher_error_t usher_remove( usher_t *u, const char *path );


typedef enum {
    USHER_MATCH = 0,
    USHER_MATCH_NONE,
    USHER_MATCH_SHORT,
    USHER_MATCH_LONG,
    USHER_MATCH_DIFF
} usher_match_t;

typedef struct {
    usher_seg_t *seg;
    uint8_t *cur;
    uint8_t *remain;
    uint8_t idx;
} usher_state_t;

usher_match_t usher_get( usher_t *u, const char *path, usher_state_t *state );
usher_error_t usher_remove_segment( usher_t *u, usher_state_t *state );


typedef struct {
    uint8_t *name;
    uint8_t *head;
    uint8_t *tail;
} usher_glob_item_t;

typedef struct {
    usher_seg_t *seg;
    usher_seg_t *eos;
    size_t nitems;
    usher_glob_item_t *items;
} usher_glob_t;

usher_error_t usher_exec( usher_t *u, const char *path, usher_glob_t *glob );
void usher_glob_dealloc( usher_glob_t *glob );


void usher_dump( usher_t *u );


#endif
