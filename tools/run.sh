#!/bin/sh

root="."
tool="$root/tools"
inc="$root/include"

if [ ! -d $tool ]; then
  echo "$tool does not exist"
	exit 0
fi

if [ ! -d $inc ]; then
  echo "$inc does not exist"
	exit 0
fi

for file in `ls $inc/*`; do
	echo "add header template to $file"
	python3 $tool/header.py $file -t $tool/header.macro -b $tool/brief.json -p $tool/cgraph.json
	if [ $? -ne 0 ]; then
		exit 0
	fi
done

echo "update source template in $inc/cgraph_template_off.h"
python3 $tool/macro.py $inc/cgraph_template_off.h -t $tool/template_off.macro -c "end of cgraph_template_off"

echo "update source template in $inc/cgraph_template_check.h"
python3 $tool/macro.py $inc/cgraph_template_check.h -t $tool/template_check.macro -c "end of cgraph_template_check"
