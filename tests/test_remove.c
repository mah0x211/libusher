//
//  test_remove.c
//  libusher
//
//  Created by Masatoshi Teruya on 2014/08/03.
//  Copyright (c) 2014 Masatoshi Teruya. All rights reserved.
//

#include "tests.h"

static const char *removed_key = NULL;

static void finalize( void *val ){
    assert( strcmp( removed_key, val ) == 0 );
    removed_key = NULL;
}

#define remove_and_check(u,i,k) do { \
    removed_key = k[i]; \
    do_remove( u, i, k ); \
    assert( removed_key == NULL ); \
    do_remove_check( u, i, k ); \
}while(0)

void test_remove_short2long( const char *keys[], size_t len )
{
    usher_t *u = usher_alloc( "/:/", finalize );
    size_t i = 0;
    
    // insert from short words to long words
    for( i = 0; i < len; i++ ){
        do_insert( u, i, keys );
    }
    
    for( i = 0; i < len; i++ ){
        remove_and_check( u, i, keys );
    }
    
    usher_dealloc( u );
}


void test_remove_long2short( const char *keys[], size_t len )
{
    usher_t *u = usher_alloc( "/:/", finalize );
    size_t i = len;
    
    // insert from short words to long words
    while( i ){
        do_insert( u, --i, keys );
    }
    
    i = len;
    while( i ){
        i--;
        remove_and_check( u, i, keys );
    }
    
    usher_dealloc( u );
}
