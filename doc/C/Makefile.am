gnome_hello_helpdir = $(datadir)/gnome/help/gnome-hello/C

gnome_hello_help_DATA =         \
        gnome-hello.html        \
        topic.dat

SGML_FILES =                    \
        gnome-hello.sgml

# files that aren't in a binary/data/library target have to be listed here
# to be included in the tarball when you 'make dist'
EXTRA_DIST = \
        topic.dat               \
        $(SGML_FILES)


## The - before the command means to ignore it if it fails.  that way
## people can still build the software without the docbook tools

all: 

gnome-hello.html: gnome-hello/gnome-hello.html
	-cp gnome-hello/gnome-hello.html .

gnome-hello/gnome-hello.html: $(SGML_FILES)
	-db2html gnome-hello.sgml

## when we make dist, we include the generated HTML so people don't
## have to have the docbook tools
dist-hook:
	mkdir $(distdir)/gnome-hello
	-cp gnome-hello/*.html gnome-hello/*.css $(distdir)/gnome-hello
	-cp gnome-hello.html $(distdir)

install-data-local: gnome-hello.html
	$(mkinstalldirs) $(gnome_hello_helpdir)/images
	-for file in $(srcdir)/gnome-hello/*.html $(srcdir)/gnome-hello/*.css; do \
	basefile=`basename $$file`; \
	$(INSTALL_DATA) $(srcdir)/$$file $(gnome_hello_helpdir)/$$basefile; \
	done

gnome-hello.ps: gnome-hello.sgml
	-db2ps $<

gnome-hello.rtf: gnome-hello.sgml       
	-db2rtf $<

