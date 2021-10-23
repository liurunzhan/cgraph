DIR = .
INC = $(DIR)$(SEPARATOR)..$(SEPARATOR)include
SRC = $(DIR)$(SEPARATOR)..$(SEPARATOR)src

PERL = perl
DOC_MODULE = cgraph

.PHONY: all doc clean distclean

all:
	$(PERL) headers.pl
	$(PERL) sources.pl
	$(PERL) data.pl
	dot headers.dot -Tpng -o headers.png
	dot sources.dot -Tpng -o sources.png
	pandoc Introduction.md -o Introduction.pdf

doc:
	# sources have changed
	gtkdoc-scan --module=$(DOC_MODULE) $(SRC)$(SEPARATOR)*.c $(SRC)$(SEPARATOR)*.ct
	-gtkdoc-scangobj --module=$(DOC_MODULE)
	gtkdoc-mkdb --module=$(DOC_MODULE) --xml-mode --output-format=xml --source-dir=$(SRC)
	# xml files have changed
	$(MKDIR) $(MKDIRFLAGS) html
	cd html $(SPLIT) gtkdoc-mkhtml $(DOC_MODULE) $(DIR)$(SEPARATOR)..$(SEPARATOR)$(DOC_MODULE)-docs.xml
	gtkdoc-fixxref --module=$(DOC_MODULE) --module-dir=html

CLEANED_FILES = *.dot *.png *.pdf *.txt $(DOC_MODULE)-* $(DOC_MODULE).* *.stamp

clean:
	$(RM) $(RMFLAGS) $(CLEANED_FILES)

distclean:
	$(RM) $(RMFLAGS) $(CLEANED_FILES)
