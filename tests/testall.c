//
//  main.c
//  libusher
//
//  Created by Masatoshi Teruya on 2014/07/28.
//  Copyright (c) 2014 Masatoshi Teruya. All rights reserved.
//

#include <stdio.h>
#include <errno.h>
#include "usher_private.h"
#include "tests.h"
#include "tests_keys.h"

#define run_test(fn,k,n,delim) do { \
    printf( "%-25s %-12s[%03d][%3s] ", #fn, #k, n, delim ); \
    fn( k, n, delim ); \
    printf("OK\n"); \
}while(0)


int main(int argc, const char * argv[])
{
    size_t len;
    
    // test: static keys
    len = sizeof( STATIC_KEYS ) / sizeof( testdata_t );
    run_test( test_insert_short2long, STATIC_KEYS, len, NULL );
    run_test( test_insert_long2short, STATIC_KEYS, len, NULL );
    run_test( test_remove_short2long, STATIC_KEYS, len, NULL );
    run_test( test_remove_long2short, STATIC_KEYS, len, NULL );
    run_test( test_exec, STATIC_KEYS, len, NULL );
    
    // test: github api keys
    len = sizeof( GITHUB_API ) / sizeof( testdata_t );
    run_test( test_insert_short2long, GITHUB_API, len, "/:/" );
    run_test( test_insert_long2short, GITHUB_API, len, "/:/" );
    run_test( test_remove_short2long, GITHUB_API, len, "/:/" );
    run_test( test_remove_long2short, GITHUB_API, len, "/:/" );
    run_test( test_exec, GITHUB_API, len, "/:/" );
    
    return 0;
}

