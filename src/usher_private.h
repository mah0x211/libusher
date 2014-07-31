//
//  usher_private.h
//  libusher
//
//  Created by Masatoshi Teruya on 2014/07/28.
//  Copyright (c) 2014年 Msatoshi Teruya. All rights reserved.
//

#ifndef ___LIBUSHER_PRIVATE_H___
#define ___LIBUSHER_PRIVATE_H___

#include <errno.h>
#include <stdio.h>
#include <string.h>
#include "usher.h"

// memory alloc/dealloc
#define palloc(t)       (t*)malloc( sizeof(t) )
#define pnalloc(n,t)    (t*)malloc( (n) * sizeof(t) )
#define pcalloc(t)      (t*)calloc( 1, sizeof(t) )
#define pncalloc(n,t)   (t*)calloc( n, sizeof(t) )
#define prealloc(p,n,t) (t*)realloc( p, (n) * sizeof(t) )
#define pdealloc(p)     (free((void*)p),NULL)


// segment
usher_seg_t *seg_alloc( uint8_t *path, uint8_t prev );
int seg_append2child( usher_seg_t *node, usher_seg_t *child );
usher_seg_t *seg_getchild_idx( usher_seg_t *seg, uint8_t k, size_t *idx );
#define seg_getchild(seg,k) seg_getchild_idx(seg,k,NULL)

int seg_split( usher_seg_t *node, size_t pos, usher_seg_t *sibling );
int seg_add( usher_seg_t *node, uint8_t *path );
int seg_get( usher_seg_t **seg, usher_seg_t *src, uint8_t *path );
void seg_dump( usher_seg_t *node, int lv );


#endif
