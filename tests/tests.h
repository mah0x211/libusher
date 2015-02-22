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

typedef struct {
    const char *path;
    const char *key;
    usher_glob_t globs;
} testdata_t;


static inline void do_insert( usher_t *u, int idx, const testdata_t data[] )
{
    const char *key = data[idx].path;
    usher_error_t err = usher_add( u, key, (void*)key );
    
    if( err != USHER_OK ){
        printf( "\nINSERT ERR[%d] %s -> %s\n", idx, key, usher_strerror( err ) );
        assert(0);
    }
}

static inline void do_insert_check( usher_t *u, int idx, const testdata_t data[] )
{
    const char *key = data[idx].path;
    usher_state_t state;
    usher_match_t match = usher_get( u, key, &state );
    
    if( match != USHER_MATCH ||
        !( state.seg->type & USHER_SEG_EOS ) ||
        state.seg->udata != (uintptr_t)key ){
        printf( "\nINSERT CHK ERR[%d]: %s\n", idx, key );
        assert(0);
    }
}

static inline void do_remove( usher_t *u, int idx, const testdata_t data[] )
{
    const char *key = data[idx].path;
    usher_error_t err = usher_remove( u, key );
    
    if( err ){
        printf( "\nREMOVE ERR[%d]: %s -> %s\n", idx, key, usher_strerror( err ) );
        assert(0);
    }
}

static inline void do_remove_check( usher_t *u, int idx, const testdata_t data[] )
{
    const char *key = data[idx].path;
    usher_state_t state;
    usher_match_t match = usher_get( u, key, &state );
    
    if( match == USHER_MATCH && state.seg->udata == (uintptr_t)key ){
        printf( "\nREMOVE CHK ERR[%d]: %s is still reachable\n", idx, key );
        assert(0);
    }
    
}


void static_insert( void );
void static_remove( void );
void static_exec( void );

void github_insert( void );
void github_remove( void );
void github_exec( void );

#define run_test(fn,k,n,delim) do { \
    printf( "%-30s %-12s[%03zu][%3s] ", #fn, #k, n, delim ); \
    fn( k, n, delim ); \
    printf("OK\n"); \
}while(0)


#endif
