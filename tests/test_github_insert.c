//
//  test_insert.c
//  libusher
//
//  Created by Masatoshi Teruya on 2014/08/03.
//  Copyright (c) 2014 Masatoshi Teruya. All rights reserved.
//

#include "tests.h"
#include "tests_keys.h"

#define test_insert_and_check(u,i,keys) do { \
    do_insert( u, i, data ); \
    do_insert_check( u, i, data ); \
}while(0)


static void test_github_insert_short2long( const testdata_t data[], size_t len, const char *delim )
{
    usher_t *u = usher_alloc( delim, NULL );
    size_t i = 0;
    
    // insert from short words to long words
    for( i = 0; i < len; i++ ){
        test_insert_and_check( u, i, data );
    }
    
    for( i = 0; i < len; i++ ){
        do_insert_check( u, i, data );
    }
    
    usher_dealloc( u );
}

static void test_github_insert_long2short( const testdata_t data[], size_t len, const char *delim )
{
    usher_t *u = usher_alloc( delim, NULL );
    size_t i = len;
    
    // insert from short words to long words
    while( i ){
        i--;
        test_insert_and_check( u, i, keys );
    }
    
    i = len;
    while( i ){
        do_insert_check( u, --i, data );
    }
    
    usher_dealloc( u );
}


void github_insert( void )
{
    size_t len;
    
    // test: github api keys
    len = sizeof( GITHUB_API ) / sizeof( testdata_t );
    run_test( test_github_insert_short2long, GITHUB_API, len, "/:/" );
    run_test( test_github_insert_long2short, GITHUB_API, len, "/:/" );
}


#ifdef TESTS

int main(int argc, const char * argv[])
{
    github_insert();
    return 0;
}

#endif
