PERL= perl
DOC_MODULE= meep

.PHONY: all gtk clean

all:
	$(PERL) headers.pl
	$(PERL) sources.pl
	$(PERL) data.pl
	dot headers.dot -Tpng -o headers.png
	dot sources.dot -Tpng -o sources.png
	pandoc Introduction.md -o Introduction.pdf

gtk:
	# sources have changed
	gtkdoc-scan --module=$(DOC_MODULE) ../src/*.c
	gtkdoc-scangobj --module=$(DOC_MODULE)
	gtkdoc-mkdb --module=$(DOC_MODULE) --output-format=xml --source-dir=../src
	# xml files have changed
	mkdir html
	cd html && gtkdoc-mkhtml $(DOC_MODULE) ../meep-docs.xml
	gtkdoc-fixxref --module=$(DOC_MODULE) --module-dir=html

clean:
	rm -rf *.dot *.png *.pdf
