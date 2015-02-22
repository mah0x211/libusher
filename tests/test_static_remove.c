//
//  test_remove.c
//  libusher
//
//  Created by Masatoshi Teruya on 2014/08/03.
//  Copyright (c) 2014 Masatoshi Teruya. All rights reserved.
//

#include "tests.h"
#include "tests_keys.h"

static const char *removed_key = NULL;

static void finalize( void *val ){
    assert( strcmp( removed_key, val ) == 0 );
    removed_key = NULL;
}

#define remove_and_check(u,i,d) do { \
    removed_key = d[i].path; \
    do_remove( u, i, d ); \
    assert( removed_key == NULL ); \
    do_remove_check( u, i, d ); \
}while(0)

static void test_static_remove_short2long( const testdata_t data[], size_t len, const char *delim )
{
    usher_t *u = usher_alloc( delim, finalize );
    size_t i = 0;
    
    // insert from short words to long words
    for( i = 0; i < len; i++ ){
        do_insert( u, i, data );
    }
    
    for( i = 0; i < len; i++ ){
        remove_and_check( u, i, data );
    }
    
    usher_dealloc( u );
}


static void test_static_remove_long2short( const testdata_t data[], size_t len, const char *delim )
{
    usher_t *u = usher_alloc( delim, finalize );
    size_t i = len;
    
    // insert from short words to long words
    while( i ){
        do_insert( u, --i, data );
    }
    
    i = len;
    while( i ){
        i--;
        remove_and_check( u, i, data );
    }
    
    usher_dealloc( u );
}


void static_remove( void )
{
    size_t len;
    
    // test: static keys
    len = sizeof( STATIC_KEYS ) / sizeof( testdata_t );
    run_test( test_static_remove_short2long, STATIC_KEYS, len, NULL );
    run_test( test_static_remove_long2short, STATIC_KEYS, len, NULL );
}


#ifdef TESTS

int main(int argc, const char * argv[])
{
    static_remove();
    return 0;
}
#endif

