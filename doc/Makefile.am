# Process this file with automake to create Makefile.in.

SUBDIRS = . example

doc_DATA = pcsc-lite.tex pcsc-lite.bib \
			ifdhandler-3.tex \
			README.DAEMON

man_MANS = pcscd.8 reader.conf.5 update-reader.conf.8
man_in = pcscd.8.in reader.conf.5.in update-reader.conf.8.in

EXTRA_DIST = $(doc_DATA) $(man_in) doxygen.conf.in formaticc.1

CLEANFILES = ifdhandler-3.aux ifdhandler-3.bbl ifdhandler-3.blg \
	ifdhandler-3.dvi ifdhandler-3.log ifdhandler-3.out \
	ifdhandler-3.toc \
	pcsc-lite.aux pcsc-lite.bbl pcsc-lite.blg pcsc-lite.log \
	pcsc-lite.out pcsc-lite.toc

DISTCLEANFILES = ifdhandler-3.pdf pcsc-lite.pdf

# name of commands
LATEX = latex
PDFLATEX = pdflatex
BIBTEX = bibtex
LATEX2HTML = latex2html

# create a dvi file from a tex file
%.dvi: %.tex
	$(LATEX) $*
	-@egrep -c 'Citation .* undefined.' $*.log && ($(BIBTEX) $* ; $(LATEX) $*)
	-@grep 'Rerun' $*.log && $(LATEX) $*
	-@grep 'Rerun' $*.log && $(LATEX) $*

# create a dvi file from a tex file
%.pdf: %.tex
	-$(PDFLATEX) $*
	-@egrep -c 'Citation .* undefined.' $*.log && ($(BIBTEX) $* ; $(PDFLATEX) $*)
	-@grep 'Rerun' $*.log && $(PDFLATEX) $*
	-@grep 'Rerun' $*.log && $(PDFLATEX) $*

# create a HTML document
%.html: %.tex
	rm -rf $*
	$(LATEX2HTML) -local_icons -split +2 $*

doxygen:
	rm -fr api ; cd .. ; doxygen doc/doxygen.conf
#	cp doxygen.css api/
