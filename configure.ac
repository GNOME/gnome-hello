AC_INIT(src/hello.c)

AM_CONFIG_HEADER(config.h)

dnl Might as well give it a GNOME 2.0 version number
AM_INIT_AUTOMAKE(gnome-hello, 2.0.1)

AM_MAINTAINER_MODE

AC_PROG_INTLTOOL([0.21])

AC_PROG_CC
AC_ISC_POSIX
AC_HEADER_STDC
AM_PROG_LIBTOOL

GNOME_COMPILE_WARNINGS

LIBGNOME_REQUIRED=1.96.0
LIBGNOMEUI_REQUIRED=1.96.0
SCROLLKEEPER_REQUIRED=0.1.4

PKG_CHECK_MODULES(GNOME_HELLO, libgnome-2.0 >= $LIBGNOME_REQUIRED libgnomeui-2.0 >= $LIBGNOMEUI_REQUIRED)
AC_SUBST(GNOME_HELLO_CFLAGS)
AC_SUBST(GNOME_HELLO_LIBS)

dnl Test for Scrollkeeper

AC_PATH_PROG(SCROLLKEEPER_CONFIG, scrollkeeper-config,no)
if test x$SCROLLKEEPER_CONFIG = xno; then
  AC_MSG_ERROR(Couldn't find scrollkeeper-config, please install the scrollkeeper package)
fi

AC_DEFINE_UNQUOTED(GNOME_ICONDIR, "${prefix}/share/pixmaps", "definition of GNOME_ICONDIR")

ALL_LINGUAS="az bg cs da de el es fi fr gl it lv ms nl nn no pl pt pt_BR ru sk sv tr uk vi wa zh_CN zh_TW"

GETTEXT_PACKAGE=gnome-hello-2.0
AC_SUBST(GETTEXT_PACKAGE)
AM_GLIB_GNU_GETTEXT
AC_DEFINE_UNQUOTED(GETTEXT_PACKAGE,"$GETTEXT_PACKAGE", "definition of GETTEXT_PACKAGE")

AC_SUBST(CFLAGS)
AC_SUBST(CPPFLAGS)
AC_SUBST(LDFLAGS)

AC_OUTPUT([
Makefile
src/Makefile
po/Makefile.in
pixmaps/Makefile
help/Makefile
help/C/Makefile
])