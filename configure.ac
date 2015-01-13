#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.63])
AC_INIT([rpmatch], [1.0.0-rc1], [bug-report@address])
AC_CONFIG_SRCDIR([src/rpmatch.c])
AC_CONFIG_HEADERS([src/config.h])
AC_CONFIG_AUX_DIR([_build-aux])

# Checks for programs.
AC_PROG_CC
AC_PROG_CC_C89

# Checks for libraries.

# Checks for header files.
AC_CHECK_HEADERS(
  [getopt.h locale.h stdio.h stdlib.h string.h],
  [],
  [AC_MSG_ERROR(header file not found.)]
)

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.
AC_CHECK_FUNCS([getopt_long rpmatch setlocale])

# Automake integration
AM_INIT_AUTOMAKE([foreign dist-xz no-dist-gzip -Wall])
AM_SILENT_RULES([yes])

AC_CONFIG_FILES([Makefile src/Makefile])

AC_OUTPUT

dnl vi: set ft=m4 et sw=2 ts=2:
