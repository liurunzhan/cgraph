#!/bin/sh

root="."
tool="$root/tools"
inc="$root/include"

if [ ! -d $inc ]; then
  echo "$inc does not exist"
	exit 0
fi

for file in `ls $inc/*`; do
	echo "add header template to $file"
	python3 $tool/header.py -i $file -t $tool/header.txt -b $tool/brief.json -p $tool/cgraph.json
done

echo "update source template in $inc/cgraph_template_off.h"
python3 $tool/macro.py $inc/cgraph_template_off.h $inc/cgraph_template_off.h --template $tool/template_off.macro --comment "end of cgraph_template_off"

echo "update source template in $inc/cgraph_template_check.h"
python3 $tool/macro.py $inc/cgraph_template_check.h $inc/cgraph_template_check.h --template $tool/template_check.macro --comment "end of cgraph_template_check"
