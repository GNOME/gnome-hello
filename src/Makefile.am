INCLUDES = -I$(top_srcdir)				\
	   -I$(includedir)				\
	   $(GNOME_HELLO_CFLAGS)			\
           -DG_LOG_DOMAIN=\"GnomeHello\"		\
	   -DGNOMELOCALEDIR=\""$(datadir)/locale"\"	\
	   -DDATADIR=\""$(datadir)"\"			\
	   -I../intl -I$(top_srcdir)/intl

bin_PROGRAMS = gnome-hello

gnome_hello_SOURCES =         \
        app.c           \
        hello.c         \
        menus.c		\
	app.h		\
	hello.h		\
	menus.h

gnome_hello_LDADD = $(GNOME_HELLO_LIBS) $(INTLLIBS)
