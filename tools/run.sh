#!/bin/sh

for file in `ls ./include/*.h`; do
	echo "add header template to $file"
	./tools/header.py -i $file -t ./tools/header.txt -b ./tools/brief.json -p ./tools/cgraph.json
done