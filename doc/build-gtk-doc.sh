#!/usr/bin/sh

DOC_MODULE= meep

# sources have changed
gtkdoc-scan --module=${DOC_MODULE} ../src/*.c
gtkdoc-scangobj --module=${DOC_MODULE}
gtkdoc-mkdb --module=${DOC_MODULE} --output-format=xml --source-dir=../src
# xml files have changed
mkdir html
cd html && gtkdoc-mkhtml ${DOC_MODULE} ../meep-docs.xml
gtkdoc-fixxref --module=${DOC_MODULE} --module-dir=html
