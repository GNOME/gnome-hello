SUBDIRS = src pixmaps po help

ACLOCAL_AMFLAGS = -I m4 ${ACLOCAL_FLAGS}

NULL =

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

MAINTAINERCLEANFILES = \
	ChangeLog \
	$(srcdir)/INSTALL \
	$(srcdir)/aclocal.m4 \
	$(srcdir)/autoscan.log \
	$(srcdir)/compile \
	$(srcdir)/config.guess \
	$(srcdir)/config.h.in \
	$(srcdir)/config.sub \
	$(srcdir)/configure \
	$(srcdir)/configure.scan \
	$(srcdir)/depcomp \
	$(srcdir)/install-sh \
	$(srcdir)/ltmain.sh \
	$(srcdir)/missing \
	$(srcdir)/mkinstalldirs \
	$(srcdir)/omf.make \
	$(srcdir)/xmldocs.make \
	$(srcdir)/gtk-doc.make \
	$(srcdir)/po/Makefile.in.in \
	`find "$(srcdir)" -type f -name Makefile.in -print` \
	$(NULL)

# Build ChangeLog from GIT  history
ChangeLog:
	$(AM_V_GEN) if test -d $(top_srcdir)/.git; then \
		GIT_DIR="$(top_srcdir)/.git" git log --stat > $@; \
	fi

dist: ChangeLog

.PHONY: ChangeLog

-include $(top_srcdir)/git.mk
