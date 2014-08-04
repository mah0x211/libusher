//
//  usher.h
//  libusher
//
//  Created by Masatoshi Teruya on 2014/07/28.
//  Copyright (c) 2014年 Msatoshi Teruya. All rights reserved.
//

#ifndef ___LIBUSHER_H___
#define ___LIBUSHER_H___

#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <errno.h>

typedef struct {
    uint8_t *head;
    size_t len;
} r2param_item_t;

typedef struct {
    r2param_item_t *items;
    size_t nitem;
} r2param_t;


// errors
typedef enum {
    USHER_OK = 0,
    USHER_EINVAL,
    USHER_ENOMEM,
    USHER_EAPPEND,
    USHER_ESPLIT,
    USHER_EALREADY,
    USHER_ENOENT
} usher_error_t;

char *usher_strerror( usher_error_t err );


#define USHER_SEG_NODE  0x0
#define USHER_SEG_VAR   0x1
// end-of-segment
#define USHER_SEG_EOS   0x2

typedef struct _usher_seg {
    // userdata
    uintptr_t udata;
    uint8_t *path;
    size_t len;
    struct _usher_seg *parent;
    struct _usher_seg *varchild;
    struct _usher_seg **children;
    uint8_t nchildren;
    uint8_t type;
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
usher_error_t usher_add( usher_t *u, const char *path, void *val );
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


void usher_dump( usher_t *u );


#endif
