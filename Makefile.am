SUBDIRS = po src pixmaps help

appdir = $(datadir)/applications
app_in_files = gnome-hello.desktop.in
app_DATA = $(app_in_files:.desktop.in=.desktop)
@INTLTOOL_DESKTOP_RULE@

# On uninstall, scrollkeeper will leave behind an empty database.
# We add thies lines so that it does not show up as an error during distcheck.
distcleancheck_listfiles = find . -type f -print | grep -v 'omf\.out'

distuninstallcheck_listfiles = find . -type f -print | grep -v 'scrollkeeper' | grep -v 'omf' | grep -v 'figures'

## We dist autogen.sh since this is an example program
## Real-world programs do not need to distribute autogen.sh
## But there is no harm in it, and you probably should.

EXTRA_DIST = \
	gnome-hello.desktop	\
	autogen.sh		\
	xmldocs.make		\
	intltool-extract.in	\
	intltool-merge.in	\
	intltool-update.in	\
	$(app_in_files)		\
	$(app_DATA)
