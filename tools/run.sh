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
	$tool/header.py -i $file -t $tool/header.txt -b $tool/brief.json -p $tool/cgraph.json
done