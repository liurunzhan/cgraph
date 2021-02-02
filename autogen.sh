#!/bin/sh

echo "using autotools to generate configure"

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
  MISSING="aclocal"
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
    echo "missing TOOL $tool"
  done
  exit 1
fi

echo "step 1 : running $ACLOCAL"
$ACLOCAL
if [ $? -ne 0 ]; then
  echo "running $ACLOCAL error"
  exit 1
fi

echo "step 2 : running $AUTOHEADER"
$AUTOHEADER
if [ $? -ne 0 ]; then
  echo "running $AUTOHEADER error"
  exit 1
fi

echo "step 3 : running $LIBTOOL --automake --copy --force"
$LIBTOOL --automake --copy --force
if [ $? -ne 0 ]; then
  echo "running $LIBTOOL --automake --copy --force error"
  exit 1
fi

echo "step 4 : running $AUTOCONF"
$AUTOCONF
if [ $? -ne 0 ]; then
  echo "running $AUTOCONF error"
  exit 1
fi

echo "step 5 : running $AUTOMAKE --add-missing"
$AUTOMAKE --add-missing
if [ $? -ne 0 ]; then
  echo "running $AUTOMAKE --add-missing error"
  exit 1
fi

echo "generating configure done"