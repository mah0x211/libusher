#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ(2.61)
AC_INIT(libusher, 0.10.1)
AC_CONFIG_SRCDIR([src/usher.c])
AM_INIT_AUTOMAKE([foreign no-dist no-installinfo no-installman -Wall])
AC_CONFIG_HEADER([config.h])
AC_CONFIG_MACRO_DIR([m4])


# Checks for programs.
AC_PROG_CC
AC_PROG_LIBTOOL

# Checks for header files.
AC_HEADER_STDC
AC_CHECK_HEADERS([stdlib.h stdint.h string.h limits.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_C_CONST
AC_TYPE_SIZE_T
AC_CHECK_TYPES([uint8_t, size_t, uintptr_t])

# Checks for library functions.
AC_FUNC_REALLOC
AC_CHECK_FUNCS([ \
    malloc \
    calloc \
    realloc \
    free \
    memmove \
    memcpy
])

#
# debug option 
#
AC_ARG_ENABLE(
    [debug],
    AS_HELP_STRING([--enable-debug], [enable debug build.]),
    [ENABLE_DEBUG=$enableval], [ENABLE_DEBUG=no]
)
AS_IF([test "$ENABLE_DEBUG" != "no"],
    [ AC_DEFINE([DEBUG], [1], [Define if you enabled debug]) ],
    [ AC_SUBST([CFLAGS], ["-O3"]) ]
)

AC_CONFIG_FILES([Makefile \
                 libusher.pc \
                 src/Makefile \
                 tests/Makefile])
AC_OUTPUT
