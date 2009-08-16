SUBDIRS = src pixmaps po help

desktopdir = $(datadir)/applications
desktop_in_files = gnome-hello.desktop.in
desktop_DATA = $(desktop_in_files:.desktop.in=.desktop)

@INTLTOOL_DESKTOP_RULE@

distuninstallcheck_listfiles = find . -type f -print | grep -v scrollkeeper

EXTRA_DIST = \
	autogen.sh		\
	gnome-doc-utils.make	\
	$(desktop_in_files)	

CLEANFILES = \
	$(desktop_DATA)

DISTCLEANFILES =

# Build ChangeLog from GIT  history
ChangeLog:
	$(AM_V_GEN) if test -d $(top_srcdir)/.git; then \
		GIT_DIR="$(top_srcdir)/.git" git log --stat > $@; \
	fi

dist: ChangeLog

.PHONY: ChangeLog
