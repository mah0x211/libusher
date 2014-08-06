//
//  test_insert.c
//  libusher
//
//  Created by Masatoshi Teruya on 2014/08/03.
//  Copyright (c) 2014 Masatoshi Teruya. All rights reserved.
//

#include "tests.h"

#define test_insert_and_check(u,i,keys) do { \
    do_insert( u, i, keys ); \
    do_insert_check( u, i, keys ); \
}while(0)


void test_insert_short2long( const char *keys[], size_t len )
{
    usher_t *u = usher_alloc( "/:/", NULL );
    size_t i = 0;
    
    // insert from short words to long words
    for( i = 0; i < len; i++ ){
        test_insert_and_check( u, i, keys );
    }
    
    for( i = 0; i < len; i++ ){
        do_insert_check( u, i, keys );
    }
    
    usher_dealloc( u );
}

void test_insert_long2short( const char *keys[], size_t len )
{
    usher_t *u = usher_alloc( "/:/", NULL );
    size_t i = len;
    
    // insert from short words to long words
    while( i ){
        i--;
        test_insert_and_check( u, i, keys );
    }
    
    i = len;
    while( i ){
        do_insert_check( u, --i, keys );
    }
    
    usher_dealloc( u );
}


