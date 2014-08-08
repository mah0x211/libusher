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


int main(int argc, const char * argv[])
{
    size_t len;
    
    // test: static keys
    len = sizeof( STATIC_KEYS ) / sizeof( testdata_t );
    run_test( test_static_insert_short2long, STATIC_KEYS, len, NULL );
    run_test( test_static_insert_long2short, STATIC_KEYS, len, NULL );
    run_test( test_static_remove_short2long, STATIC_KEYS, len, NULL );
    run_test( test_static_remove_long2short, STATIC_KEYS, len, NULL );
    run_test( test_static_exec, STATIC_KEYS, len, NULL );
    
    // test: github api keys
    len = sizeof( GITHUB_API ) / sizeof( testdata_t );
    run_test( test_github_insert_short2long, GITHUB_API, len, "/:/" );
    run_test( test_github_insert_long2short, GITHUB_API, len, "/:/" );
    run_test( test_github_remove_short2long, GITHUB_API, len, "/:/" );
    run_test( test_github_remove_long2short, GITHUB_API, len, "/:/" );
    run_test( test_github_exec, GITHUB_API, len, "/:/" );
    
    return 0;
}

