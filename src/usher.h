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


#define USHER_SEG_DELIMITER '/'

#define USHER_SEG_NODE  0x1
#define USHER_SEG_LEAF  0x2
#define USHER_SEG_EDGE  0x4
#define USHER_SEG_VAR   0x8

enum {
    USHER_UNMATCH = 0,
    USHER_MATCH,
    USHER_MATCH_SUB,
    USHER_MATCH_SEG
};

typedef struct _usher_seg {
    uint8_t type;
    uint8_t *path;
    size_t len;
    struct _usher_seg **children;
    size_t nchildren;
} usher_seg_t;


typedef struct {
    usher_seg_t *root;
} usher_t;


usher_t *usher_alloc( void );
void usher_dealloc( usher_t *u );
int usher_add( usher_t *u, const char *path, void *val );
int usher_get( usher_seg_t **seg, usher_t *u, const char *path );
void usher_dump( usher_t *u );


#endif
