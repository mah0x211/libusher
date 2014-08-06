//
//  tests.h
//  libusher
//
//  Created by Masatoshi Teruya on 2014/08/03.
//  Copyright (c) 2014 Masatoshi Teruya. All rights reserved.
//

#ifndef ___LIBUSHER_TESTS_H___
#define ___LIBUSHER_TESTS_H___

#include "../src/usher_private.h"
#include <stdio.h>
#include <assert.h>


static inline void do_insert( usher_t *u, int idx, const char *keys[] )
{
    const char *key = keys[idx];
    usher_error_t err = usher_add( u, key, (void*)key );
    
    if( err != USHER_OK ){
        printf( "\nINSERT ERR: %s -> %s\n", idx, key, usher_strerror( err ) );
        assert(0);
    }
}

static inline void do_insert_check( usher_t *u, int idx, const char *keys[] )
{
    const char *key = keys[idx];
    usher_state_t state;
    usher_match_t match = usher_get( u, key, &state );
    
    if( match != USHER_MATCH ||
        !( state.seg->type & USHER_SEG_EOS ) ||
        state.seg->udata != (uintptr_t)key ){
        printf( "\nINSERT CHK ERR: [%d] %s\n", idx, key );
        assert(0);
    }
}

static inline void do_remove( usher_t *u, int idx, const char *keys[] )
{
    const char *key = keys[idx];
    usher_error_t err = usher_remove( u, key );
    
    if( err ){
        printf( "\nREMOVE ERR: [%d] %s -> %s\n", idx, key, usher_strerror( err ) );
        assert(0);
    }
}

static inline void do_remove_check( usher_t *u, int idx, const char *keys[] )
{
    const char *key = keys[idx];
    usher_state_t state;
    usher_match_t match = usher_get( u, key, &state );
    
    if( match == USHER_MATCH && state.seg->udata == (uintptr_t)key ){
        printf( "\nREMOVE CHK ERR: [%d] %s == %zu == %zu\n", idx, key );
        assert(0);
    }
    
}

void test_insert_short2long( const char *keys[], size_t len );
void test_insert_long2short( const char *keys[], size_t len );

void test_remove_short2long( const char *keys[], size_t len );
void test_remove_long2short( const char *keys[], size_t len );

#endif