INCLUDES = -I$(top_srcdir)						\
	   $(GNOME_HELLO_CFLAGS)					\
           -DG_LOG_DOMAIN=\"GnomeHello\"				\
	   -DGNOMELOCALEDIR=\""$(prefix)/$(DATADIRNAME)/locale"\"	\
	   -DDATADIR=\""$(datadir)"\"					\
	   -DG_DISABLE_DEPRECATED -DGTK_DISABLE_DEPRECATED		\
	   -DGDK_DISABLE_DEPRECATED -DGNOME_DISABLE_DEPRECATED

bin_PROGRAMS = gnome-hello

gnome_hello_SOURCES =         \
        app.c           \
        hello.c         \
        menus.c		\
	app.h		\
	hello.h		\
	menus.h

gnome_hello_LDADD = $(GNOME_HELLO_LIBS) $(INTLLIBS)
