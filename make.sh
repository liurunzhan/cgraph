#!/bin/sh

root=`pwd`
tool="$root/tools"
inc="$root/include"

if [ ! -d $tool ]; then
  echo "$tool does not exist"
  exit 1
fi

if [ ! -d $inc ]; then
  echo "$inc does not exist"
  exit 1
fi

echo "Step 0 : updatting source files by template"
# python3 $tool/macro.py $inc/cgraph_template_off.h -t $tool/template_off.macro -c "end of cgraph_template_off"
# python3 $tool/macro.py $inc/cgraph_template_check.h -t $tool/template_check.macro -c "end of cgraph_template_check"
python3 $tool/macro.py $inc/cgraph_stdchk.h.in -t $tool/stdchk.macro -c "" --novar

echo "Step 1 : running autogen.sh to generate configure"
chmod +x $root/autogen.sh; $root/autogen.sh

number=20
arguments=""
for i in $*; do
	argument_header=`echo $i | cut -c -2`
  if [ $argument_header = "-j" ]; then
    number=`echo $i | cut -c 3-`
  else
    arguments="$arguments $i"
  fi
done

echo "Step 2 : running 'configure $arguments' to generate Makefiles"
chmod +x $root/configure; $root/configure $arguments

echo "Step 3 : updatting source files"
for file in `ls $inc/*`; do
  echo "add header template to $file"
  python3 $tool/header.py $file -t $tool/header.macro -b $tool/brief.json -p $tool/cgraph.json
  if [ $? -ne 0 ]; then
    exit 0
  fi
done

echo "Step 4 : using $number threads to do 'make' and 'make check'"
make -j$number
make check -j$number 2> build.log
