#!/bin/sh

echo "This script is used to generate FILE ./configure by autotools"

MISSING=""

ACLKCAL=
AUTOHEADER=
LIBTOOL=
AUTOCONF=
GTKDOCIZE= 
AUTOMAKE=
TAR=
DOXYGEN=

echo ">>> detect all the needed autotools"

# detect whether platform supports aclocal or not
env aclocal --version > /dev/null 2>&1
if [ $? -eq 0 ]; then
  ACLOCAL=aclocal
else
  MISSING="aclocal"
fi

# detect whether platform supports autoheader or not
env autoheader --version > /dev/null 2>&1
if [ $? -eq 0 ]; then
  AUTOHEADER=autoheader
else
  MISSING="$MISSING autoheader"
fi

# detect whether platform supports libtoolize/glibtoolize or not
env libtoolize --version > /dev/null 2>&1
if [ $? -eq 0 ]; then
  LIBTOOL=libtoolize
else
  env glibtoolize --version > /dev/null 2>&1
  if [ $? -eq 0 ]; then
    LIBTOOL=glibtoolize
  else
    MISSING="$MISSING libtoolize/glibtoolize"
  fi
fi

# detect whether platform supports autoconf or not
env autoconf --version > /dev/null 2>&1
if [ $? -eq 0 ]; then
  AUTOCONF=autoconf
else
  MISSING="$MISSING autoconf"
fi

# detect whether platform supports gtkdocize or not
env gtkdocize --version > /dev/null 2>&1
if [ $? -eq 0 ]; then
  GTKDOCIZE=gtkdocize
else
  MISSING="$MISSING gtkdocize"
fi

# detect whether platform supports automake or not
env automake --version > /dev/null 2>&1
if [ $? -eq 0 ]; then
  AUTOMAKE=automake
else
  MISSING="$MISSING automake"
fi

# detect whether platform supports tar or not
env tar --version > /dev/null 2>&1
if [ $? -eq 0 ]; then
  TAR=tar
else
  MISSING="$MISSING tar"
fi

# detect whether platform supports doxygen or not
env doxygen --version > /dev/null 2>&1
if [ $? -eq 0 ]; then
  DOXYGEN=doxygen
else
  MISSING="$MISSING doxygen"
fi

# echo missing tools
if [ "x$MISSING" != "x" ]; then
  for tool in $MISSING; do
    echo ">>> missing TOOL $tool"
  done
  exit 1
fi

echo ">>> generate ./configure with detected autotools"
echo "step 1 : running $ACLOCAL with OPTIONS --install --force"
$ACLOCAL --install --force
if [ $? -ne 0 ]; then
  echo "ERROR with step 1 : running $ACLOCAL with OPTIONS --install --force"
  exit 1
fi

echo "step 2 : running $AUTOHEADER"
$AUTOHEADER
if [ $? -ne 0 ]; then
  echo "ERROR with step 2 : running $AUTOHEADER"
  exit 1
fi

echo "step 3 : running $LIBTOOL with OPTIONS --automake --copy --force"
$LIBTOOL --automake --copy --force
if [ $? -ne 0 ]; then
  echo "ERROR with step 3 : running $LIBTOOL with OPTIONS --automake --copy --force"
  exit 1
fi

echo "step 4 : running $AUTOCONF"
$AUTOCONF
if [ $? -ne 0 ]; then
  echo "ERROR with step 4 : running $AUTOCONF"
  exit 1
fi

echo "step 5 : running $GTKDOCIZE"
$GTKDOCIZE
if [ $? -ne 0 ]; then
  echo "ERROR with step 5 : running $GTKDOCIZE"
  exit 1
fi

echo "step 6 : running $AUTOMAKE with OPTIONS --add-missing"
$AUTOMAKE --add-missing
if [ $? -ne 0 ]; then
  echo "ERROR with step 6 : running $AUTOMAKE with OPTIONS --add-missing"
  exit 1
fi

echo "step 7 : running script tools/run.sh"
chmod +x tools/run.sh
tools/run.sh

if [ -f "./configure" ]; then
echo ">>> generate FILE ./configure successfully"
echo ">>> then please run ./configure with options you want to generate Makefiles and compile project with them"
else
echo ">>> ERROR : configure with errors happen"
echo ">>> please check all needed tools and files, and then re-run this script"
fi