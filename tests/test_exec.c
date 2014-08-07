//
//  test_exec.c
//  libusher
//
//  Created by Masatoshi Teruya on 2014/08/06.
//  Copyright (c) 2014 Masatoshi Teruya. All rights reserved.
//

#include "tests.h"


#define remove_and_check(u,i,k) do { \
    removed_key = k[i]; \
    do_remove( u, i, k ); \
    assert( removed_key == NULL ); \
    do_remove_check( u, i, k ); \
}while(0)

void test_exec( const testdata_t data[], size_t len, const char *delim )
{
    usher_t *u = usher_alloc( delim, NULL );
    usher_error_t err;
    usher_glob_t glob;
    const testdata_t *item;
    size_t i, j;
    
    for( i = 0; i < len; i++ ){
        do_insert( u, i, data );
    }
    
    for( i = 0; i < len; i++ )
    {
        item = &data[i];
        glob.nitems = 0;
        glob.items = NULL;
        err = usher_exec( u, item->key, &glob );
        if( err ){
            printf( "\nEXEC ERR: [%d] %s -> %s\n", i, item->path, usher_strerror( err ) );
            assert(0);
        }
        else if( glob.nitems != item->globs.nitems ){
            printf(
                "\nEXEC ERR: [%d] %s -> number of catch param should be %zu but %zu\n",
                i, item->path, item->globs.nitems, glob.nitems
            );
            printf( "key: %s\n", item->key );
            assert(0);
        }
        
        for( j = 0; j < glob.nitems; j++ ){
            assert( strcmp( glob.items[j].name, item->globs.items[j].name ) == 0 );
            assert( strcmp( glob.items[j].val, item->globs.items[j].val ) == 0 );
        }
        usher_glob_dealloc( &glob );
    }
    
    usher_dealloc( u );
}


