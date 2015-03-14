#Wiki describing code structure

# Introduction #

This page describes the structure of the code in a but more detail.

Refer to this page to become an active developer!

# Details #

> The directory structure is the following:
    * iomanager: libraries for I/O at user-level, including graphics
    * datamanager: libraries for I/O of permanent data
    * objects: Game classes
    * main: Main program and handling functions

> In order to allow a flexible structure, there's a main **Makefile.config** which sets global options (like compiler/linker flags) and that is included in every Makefile.

N.B. **Remember** to update Makefile with your installation directory! This is needed until we migrate to autoconf.

> There's one main Makefile who just loop over the sections (i.e. directories) defined in the Makefile.config and lunch make itself.
> A template for each directory Makefile is the following:
```
# Makefile
# Project: tombseller
# Makefile for XXXXX (directoryYYYY) section.
# Authors: M. Antonelli, S. Pagan Griso
# Description:
#  Define what to compile and how. Define static libraries and test programs.
# Special Notes:

include ../Makefile.config

#Put here new sources
SOURCES = $(nullstring)
OBJECTS = ${SOURCES:%.cc=%.o}

#Add here additional libraries we need for this section
EXTRALIBS = $(nullstring)

#Define output libraries
OUTLIBRARIES = $(nullstring)
#Example:
#libuserio.a: $(OBJECTS)
#       $(AR) $(ARFLAGS) rv $@ $^
#       ranlib $@

#Define here test programs that you may want to build
PROGRAMS = $(nullstring)
#Example:
#mouse: mouse.o
#       $(LD) $(LDFLAGS) -o $@ $^ $(LIBS) $(EXTRALIBS)

#Define below this line all specific $(PROGRAMS), $(OUTLIBRARIES) rules


#Build all
all: $(OUTLIBRARIES) $(PROGRAMS)

#Clean. Delete also core and emacs/vim backup files
clean:
        $(RM) -f $(OBJECTS) $(PROGRAMS) $(OUTLIBRARIES) *~ core* \#*
```

You can define new source files, new libraries, define how to build each library. etc..

Add in _EXTRALIBS_ every specific library that you need just for this section.