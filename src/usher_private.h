/*
 *  usher_private.h
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

#ifndef ___LIBUSHER_PRIVATE_H___
#define ___LIBUSHER_PRIVATE_H___

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
usher_error_t seg_alloc( usher_seg_t **pseg, const usher_t *u, uint8_t *path,
                         uint8_t prev, uintptr_t udata );

void seg_dealloc( usher_seg_t *seg, usher_dealloc_cb callback );

usher_seg_t *seg_getchild_idx( usher_seg_t *seg, uint8_t k, uint8_t *idx );
#define seg_getchild(seg,k) seg_getchild_idx(seg,k,NULL)

usher_error_t seg_add( const usher_t *u, usher_seg_t *node, uint8_t *path,
                       uintptr_t udata, int replace );

usher_match_t seg_get( usher_seg_t *seg, uint8_t *path, usher_state_t *state );

usher_error_t seg_remove( usher_t *u, usher_seg_t *seg, uint8_t idx );

usher_error_t seg_exec( const usher_t *u, usher_seg_t *seg, uint8_t *path,
                        usher_glob_t *glob );

void seg_dump( usher_seg_t *seg, int lv, int last );

#endif
