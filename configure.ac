AC_PREREQ(2.61)
AC_INIT([GNOME Hello],[2.0.3],[mailto:desktop-devel-list@gnome.org],[gnome-hello])

AC_CONFIG_SRCDIR([src])
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_MACRO_DIR([m4])
AC_CONFIG_AUX_DIR([build-aux])

AM_INIT_AUTOMAKE([1.10 foreign dist-bzip2 no-dist-gzip])

m4_ifdef([AM_SILENT_RULES],[AM_SILENT_RULES([yes])])

# Check for programs
AX_CHECK_ENABLE_DEBUG
AC_PROG_CC

# Initialize libtool
LT_PREREQ([2.2.6])
LT_INIT

# *****
# GNOME
# *****

GNOME_COMPILE_WARNINGS([maximum])

# ***************************
# Check for required packages
# ***************************

LIBGTK_REQUIRED=2.91

PKG_CHECK_MODULES([GNOME_HELLO],
   [gtk+-3.0 >= $LIBGTK_REQUIRED])

# *************
# Documentation
# *************

YELP_HELP_INIT

# ********************
# Internationalisation
# ********************

IT_PROG_INTLTOOL([0.40.0])

AM_GNU_GETTEXT_VERSION([0.17])
AM_GNU_GETTEXT([external])

AC_SUBST([GETTEXT_PACKAGE], [gnome-hello])
AC_DEFINE([GETTEXT_PACKAGE], [PACKAGE_TARNAME], [Define to the gettext package name.])

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
])

AC_OUTPUT
