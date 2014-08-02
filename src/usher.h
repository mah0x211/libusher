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
    USHER_EALREADY
} usher_error_t;



#define USHER_DELIM_SEG '/'
#define USHER_DELIM_VAR '$'

#define USHER_SEG_NODE  0x0
#define USHER_SEG_LEAF  0x1
#define USHER_SEG_VAR   0x2
// end-of-segment
#define USHER_SEG_EOS   0x4


enum {
    USHER_UNMATCH = 0,
    USHER_MATCH,
    USHER_MATCH_SUB,
    USHER_MATCH_SEG
};

typedef struct _usher_seg {
    // userdata
    uintptr_t udata;
    uint8_t *path;
    size_t len;
    struct _usher_seg *parent;
    struct _usher_seg **children;
    uint8_t nchildren;
    uint8_t type;
} usher_seg_t;


typedef void(*usher_dealloc_cb)( void* );

typedef struct {
    usher_seg_t *root;
    usher_dealloc_cb callback;
} usher_t;


usher_t *usher_alloc( usher_dealloc_cb callback );
void usher_dealloc( usher_t *u );
usher_error_t usher_add( usher_t *u, const char *path, void *val );
int usher_get( usher_seg_t **seg, usher_t *u, const char *path );
int usher_remove( usher_t *u, const char *path );

void usher_dump( usher_t *u );


#endif
