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
usher_seg_t *seg_alloc( uint8_t *path, uint8_t prev, uintptr_t udata );
void seg_dealloc( usher_seg_t *seg, usher_dealloc_cb callback );

usher_seg_t *seg_getchild_idx( usher_seg_t *seg, uint8_t k, uint8_t *idx );
#define seg_getchild(seg,k) seg_getchild_idx(seg,k,NULL)

usher_error_t seg_add( usher_seg_t *node, uint8_t *path, uintptr_t udata );
usher_match_t seg_get( usher_seg_t *seg, uint8_t *path, usher_state_t *state );
int seg_remove( usher_seg_t *seg, uint8_t *path, usher_dealloc_cb callback );
void seg_dump( usher_seg_t *node, int lv );


#endif
