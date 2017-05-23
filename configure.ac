AC_INIT([MagicSearchEngine], [0.0.0], [@bugreport@], [MagicSearchEngine])
AC_CONFIG_HEADERS(config.h)
AM_INIT_AUTOMAKE(no-dist-gzip dist-bzip2)
 
AC_SUBST(PACKAGE_AUTHOR, ["Auratons"])
AC_SUBST(PACKAGE_DESCRIPTION, ["Similarity search for Magic: The Gathering"])
AC_SUBST(PACKAGE_HOMEPAGE, ["https://github.com/Auratons/MagicSearchEngine"])
AC_SUBST(PACKAGE_MONTH, [$(LANG=C date '+%B')])
AC_SUBST(PACKAGE_YEAR, [$(LANG=C date '+%Y')])

# Checks for programs.
AC_PROG_CXX

# Checks for libraries.
#PKG_CHECK_MODULES([JSONCPP], [jsoncpp])

AX_PTHREAD( [
            AC_DEFINE(HAVE_PTHREAD,1,[Define if you have POSIX threads libraries and header files.])
            CLIBS="$PTHREAD_LIBS $LIBS"
            CFLAGS="$CFLAGS $PTHREAD_CFLAGS"
            LDFLAGS="$LDFLAGS $PTHREAD_CFLAGS"
            CC="$PTHREAD_CC"],[])

# Checks for header files.
AC_STDC_HEADERS

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.

AC_CONFIG_FILES([Makefile src/Makefile])
AC_OUTPUT
