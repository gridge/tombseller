# Makefile
# Project: tombseller
# Main Makefile of the project
# Authors: M. Antonelli, S. Pagan Griso
# Description: Main settings; define the structure of the project and allows to compile test programs.
# Special Notes: call individual sections to compile just them.

include Makefile.config

#Targets: all, test, clean, install, plus all the specific sections difined in Makefile.config
.PHONY : clean
all clean install:
	for p in $(SECTIONS) ; do cd $$p && $(MAKE) $@ && cd .. ; done

test:
	CXXFLAGS = -D_BUILDTEST_ $(CXXFLAGS)
	for p in $(SECTIONS) ; do cd $$p && $(MAKE) $@ && cd .. ; done

$(SECTIONS):
	cd $1 && $(MAKE)
