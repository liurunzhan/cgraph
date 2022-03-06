DIR=.
INC=$(DIR)$(SEPARATOR)..$(SEPARATOR)include
SRC=$(DIR)$(SEPARATOR)..$(SEPARATOR)src
SRC_FUNC=$(SRC)$(SEPARATOR)func
SRC_TYPE=$(SRC)$(SEPARATOR)type
SRC_TYPE_BASIC=$(SRC_TYPE)$(SEPARATOR)basic
SRC_TYPE_DATA_DIR=$(SRC_TYPE)$(SEPARATOR)data
SRC_TYPE_OBJECT=$(SRC_TYPE)$(SEPARATOR)object
SRC_TYPE_STRUCTURE=$(SRC_TYPE)$(SEPARATOR)structure
SRC_GAME=$(SRC)$(SEPARATOR)game
SRC_GRAPH=$(SRC)$(SEPARATOR)graph

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
	gtkdoc-scan --module=$(SRC)$(SEPARATOR)*.c $(SRC_FUNC)$(SEPARATOR)*.c $(SRC_TYPE)$(SEPARATOR)*.c $(SRC_TYPE)$(SEPARATOR)*.ct $(SRC_TYPE_BASIC)$(SEPARATOR)*.c $(SRC_TYPE_DATA_DIR)$(SEPARATOR)*.c $(SRC_TYPE_OBJECT)$(SEPARATOR)*.c $(SRC_TYPE_STRUCTURE)$(SEPARATOR)*.c $(SRC_GAME)$(SEPARATOR)*.c $(SRC_GRAPH)$(SEPARATOR)*.c $(INC)$(SEPARATOR)*.ht $(INC)$(SEPARATOR)*.h
	-gtkdoc-scangobj --module=$(DOC_MODULE) --rebuild-sections --rebuild-types 
	gtkdoc-mkdb --module=$(DOC_MODULE) --output-format=xml --source-dir=$(SRC)
	# xml files have changed
	$(MKDIR) $(MKDIRFLAGS) html
	cd html $(SPLIT) gtkdoc-mkhtml $(DOC_MODULE) $(DIR)$(SEPARATOR)$(DOC_MODULE)-docs.xml
	gtkdoc-fixxref --module=$(DOC_MODULE) --module-dir=html

CLEANED_FILES = *.dot *.png *.pdf *.txt $(DOC_MODULE)-*.* $(DOC_MODULE).* *.stamp *.log

clean:
	$(RM) $(RMFLAGS) $(CLEANED_FILES)

distclean:
	$(RM) $(RMFLAGS) $(CLEANED_FILES)
