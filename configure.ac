AC_INIT([GNOME Hello], [2.0.3],[mailto:desktop-devel-list@gnome.org],[gnome-hello])

AM_INIT_AUTOMAKE([1.9 foreign dist-bzip2 no-dist-gzip])

AC_CONFIG_SRCDIR([src])
AC_CONFIG_HEADERS([config.h])

AM_MAINTAINER_MODE

AC_PROG_CC
AC_ISC_POSIX
AC_HEADER_STDC
AC_PROG_LIBTOOL

# *****
# GNOME
# *****

GNOME_COMMON_INIT
GNOME_DEBUG_CHECK
GNOME_COMPILE_WARNINGS([maximum])
GNOME_MAINTAINER_MODE_DEFINES

# ***************************
# Check for required packages
# ***************************

LIBGTK_REQUIRED=2.6.0
LIBGNOME_REQUIRED=2.14.0
LIBGNOMEUI_REQUIRED=2.14.0
SCROLLKEEPER_REQUIRED=0.3.14

PKG_CHECK_MODULES([GNOME_HELLO],
  [libgnome-2.0 >= $LIBGNOME_REQUIRED
   libgnomeui-2.0 >= $LIBGNOMEUI_REQUIRED
   gtk+-2.0 >= $LIBGTK_REQUIRED])

# *************
# Documentation
# *************

AC_PATH_PROG(SCROLLKEEPER_CONFIG, scrollkeeper-config,no)
if test x$SCROLLKEEPER_CONFIG = xno; then
  AC_MSG_ERROR(Couldn't find scrollkeeper-config, please install the scrollkeeper package)
fi

# ********************
# Internationalisation
# ********************

IT_PROG_INTLTOOL([0.34.90])

GETTEXT_PACKAGE=gnome-hello-2.0
AC_SUBST([GETTEXT_PACKAGE])
AM_GLIB_GNU_GETTEXT
AC_DEFINE_UNQUOTED([GETTEXT_PACKAGE],["$GETTEXT_PACKAGE"],[gettext domain])

# *************************************
# *************************************

AC_SUBST([AM_CPPFLAGS])
AC_SUBST([AM_CFLAGS])
AC_SUBST([AM_CXXFLAGS])
AC_SUBST([AM_LDFLAGS])

AC_CONFIG_FILES([
Makefile
src/Makefile
po/Makefile.in
pixmaps/Makefile
help/Makefile
help/C/Makefile
])

AC_OUTPUT
