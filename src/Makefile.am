bin_PROGRAMS = gnome-hello

gnome_hello_SOURCES = \
	app.c	\
	hello.c	\
	menus.c	\
	app.h	\
	hello.h	\
	menus.h

gnome_hello_CPPFLAGS = \
	-I$(top_srcdir)					\
	-DG_LOG_DOMAIN=\"GnomeHello\"			\
	-DDATADIR=\""$(pkgdatadir)"\"			\
	-DGNOMELOCALEDIR=\""$(datadir)/locale"\"	\
	$(DISABLE_DEPRECATED)				\
	$(AM_CPPFLAGS)

gnome_hello_CFLAGS = \
	   $(GNOME_HELLO_CFLAGS)	\
	   $(WARN_CFLAGS)		\
	   $(AM_CFLAGS)

gnome_hello_LDFLAGS = \
	$(AM_LDFLAGS)

gnome_hello_LDADD = \
	$(GNOME_HELLO_LIBS)	\
 	$(INTLLIBS)
