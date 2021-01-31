#!/bin/sh

echo "using autotools to generate configure and Makefiles"

MISSING=""

ACLKCAL=
AUTOCONF=
AUTOHEADER=
AUTOMAKE=
LIBTOOL=
TAR=

# detect whether platform has aclocal or not
env aclocal --version > /dev/null 2>&1
if [ $? -eq 0 ]; then
  ACLOCAL=aclocal
else
  MISSING="$MISSING aclocal"
fi

# detect whether platform has autoconf or not
env autoconf --version > /dev/null 2>&1
if [ $? -eq 0 ]; then
  AUTOCONF=autoconf
else
  MISSING="$MISSING autoconf"
fi

# detect whether platform has autoheader or not
env autoheader --version > /dev/null 2>&1
if [ $? -eq 0 ]; then
  AUTOHEADER=autoheader
else
  MISSING="$MISSING autoheader"
fi

# detect whether platform has automake or not
env automake --version > /dev/null 2>&1
if [ $? -eq 0 ]; then
  AUTOMAKE=automake
else
  MISSING="$MISSING automake"
fi

# detect whether platform has libtoolize/glibtoolize or not
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

# detect whether platform has tar or not
env tar --version > /dev/null 2>&1
if [ $? -ne 0 ]; then
  MISSING="$MISSING tar"
fi

# echo missing tools
if [ "x$MISSING" != "x" ]; then
  for tool in $MISSING; do
    echo " missing $tool"
  done
  exit 1
fi

echo "step 1 : $ACLOCAL"
$ACLOCAL

echo "step 2 : $AUTOHEADER"
$AUTOHEADER

echo "step 3 : $LIBTOOL"
$LIBTOOL

echo "step 4 : $AUTOCONF"
$AUTOCONF

echo "step 5 : $AUTOMAKE --add-missing --force-missing --copy --foreign"
$AUTOMAKE --add-missing --force-missing --copy --foreign

echo "generating configure and Makefiles done"