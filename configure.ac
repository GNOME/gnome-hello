AC_INIT([gnome-hello], [2.0.3])
AC_CONFIG_SRCDIR(src/hello.c)

AM_INIT_AUTOMAKE
AM_CONFIG_HEADER(config.h)

AM_MAINTAINER_MODE

dnl make sure we keep ACLOCAL_FLAGS around for maintainer builds to work
AC_SUBST(ACLOCAL_AMFLAGS, "\${ACLOCAL_FLAGS}")

AC_PROG_INTLTOOL([0.21])

AC_PROG_CC
AC_ISC_POSIX
AC_HEADER_STDC
AM_PROG_LIBTOOL

GNOME_COMPILE_WARNINGS

LIBGTK_REQUIRED=2.5.0
LIBGNOME_REQUIRED=2.9.0
LIBGNOMEUI_REQUIRED=2.9.0
SCROLLKEEPER_REQUIRED=0.3.14

PKG_CHECK_MODULES(GNOME_HELLO,
  [libgnome-2.0 >= $LIBGNOME_REQUIRED dnl
   libgnomeui-2.0 >= $LIBGNOMEUI_REQUIRED dnl
   gtk+-2.0 >= $LIBGTK_REQUIRED])

dnl Test for Scrollkeeper

AC_PATH_PROG(SCROLLKEEPER_CONFIG, scrollkeeper-config,no)
if test x$SCROLLKEEPER_CONFIG = xno; then
  AC_MSG_ERROR(Couldn't find scrollkeeper-config, please install the scrollkeeper package)
fi

ALL_LINGUAS="am az be bg ca cs da de el en_CA en_GB es fi fr gl he hr id it ja ka lv mn ms nb nl nn pa pl pt pt_BR ru rw sk sr sr@Latn sv tr uk vi wa zh_CN zh_TW"

GETTEXT_PACKAGE=gnome-hello-2.0
AC_SUBST(GETTEXT_PACKAGE)
AM_GLIB_GNU_GETTEXT
AC_DEFINE_UNQUOTED(GETTEXT_PACKAGE,"$GETTEXT_PACKAGE",
                   [definition of GETTEXT_PACKAGE])
AM_GLIB_DEFINE_LOCALEDIR(GNOMELOCALEDIR)

AC_CONFIG_FILES([
Makefile
src/Makefile
po/Makefile.in
pixmaps/Makefile
help/Makefile
help/C/Makefile
])

AC_OUTPUT
