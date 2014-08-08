AM_CPPFLAGS = -I../src
AM_CFLAGS = -D TESTS

check_PROGRAMS = test_static_insert
test_static_insert_LDFLAGS = -L../src -lusher
test_static_insert_SOURCES = test_static_insert.c

check_PROGRAMS += test_static_remove
test_static_remove_LDFLAGS = -L../src -lusher
test_static_remove_SOURCES = test_static_remove.c

check_PROGRAMS += test_static_exec
test_static_exec_LDFLAGS = -L../src -lusher
test_static_exec_SOURCES = test_static_exec.c


check_PROGRAMS += test_github_insert
test_github_insert_LDFLAGS = -L../src -lusher
test_github_insert_SOURCES = test_github_insert.c

check_PROGRAMS += test_github_remove
test_github_remove_LDFLAGS = -L../src -lusher
test_github_remove_SOURCES = test_github_remove.c

check_PROGRAMS += test_github_exec
test_github_exec_LDFLAGS = -L../src -lusher
test_github_exec_SOURCES = test_github_exec.c


TESTS = $(check_PROGRAMS)
