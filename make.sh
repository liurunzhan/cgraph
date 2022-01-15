#!/bin/sh

echo "Step 1 : running autogen.sh"
chmod +x ./autogen.sh; ./autogen.sh

echo "Step 2 : running ./configure"
./configure

echo "Step 3 : running ./tools/run.sh"
chmod +x ./tools/run.sh; ./tools/run.sh

num=20
if [ -n $1 ] 
then
	num=$1
fi
echo "Step 4 : use $num threads to running make"
make check -j$num
