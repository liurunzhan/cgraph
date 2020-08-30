PERL=perl

.PHONY: all clean

all:
	$(PERL) headers.pl
	$(PERL) sources.pl
	$(PERL) data.pl
	dot headers.dot -Tpng -o headers.png
	dot sources.dot -Tpng -o sources.png
	pandoc Introduction.md -o Introduction.pdf

clean:
	rm -rf *.dot *.png *.pdf