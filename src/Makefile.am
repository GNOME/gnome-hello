
INCLUDES = -I$(top_srcdir) -I$(includedir) $(GNOME_INCLUDEDIR) \
         -DG_LOG_DOMAIN=\"GnomeHello\" -DGNOMELOCALEDIR=\""$(datadir)/locale"\" \
	-I../intl -I$(top_srcdir)/intl

bin_PROGRAMS = hello

hello_SOURCES =         \
        app.c           \
        hello.c         \
        menus.c		\
	app.h		\
	hello.h		\
	menus.h

hello_LDADD = $(GNOMEUI_LIBS) $(GNOME_LIBDIR) $(INTLLIBS)
