#! /bin/sh

# $Id$
#
# Copyright (c) 2002  Daniel Elstner  <daniel.elstner@gmx.net>,
#               2003  Murray Cumming  <murrayc@usa.net>
#
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License VERSION 2 as
# published by the Free Software Foundation.  You are not allowed to
# use any other version of the license; unless you got the explicit
# permission from the author to do so.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA


# This is meant to be a well-documented, good example of an autogen.sh script
# Please email gnome-devel-list@gnome.org if you think it isn't.


srcdir=`dirname $0`
test -z "$srcdir" && srcdir=.
ORIGDIR=`pwd`

# does $srcdir look like the gnome-hello source tree?
if ! test -f $srcdir/src/hello.c; then
    echo "error: $srcdir does not look like the gnome-hello source directory"
    exit 1
fi

cd $srcdir

# This installs the translation build infrastructure
echo "- glib-gettextize."
glib-gettextize --copy --force 	|| exit $?

echo "- libtoolize."
libtoolize --force || exit $?

# intltool is used to merge translations into things like desktop items.
echo "- intltoolize."
intltoolize --copy --force || exit $?

# if you have documentation that uses xmldocs.make and omf.make, this will
# pull in the latest versions.
echo "- gnome-doc-common"
gnome-doc-common --copy || exit $?

echo "- aclocal"
aclocal $ACLOCAL_FLAGS || exit $?

echo "- autoheader"
autoheader || exit $?

echo "- autoconf."
autoconf || exit $?

echo "- automake."
automake --add-missing --gnu || exit $?

cd $ORIGDIR
echo "- configure"
$srcdir/configure --enable-maintainer-mode ${1+"$@"} || exit $?
