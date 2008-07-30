# Makefile
# Project: tombseller
# Makefile for Data Manager (datamanager) section.
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
#	$(AR) $(ARFLAGS) rv $@ $^
#	ranlib $@

#Define here test programs that you may want to build
PROGRAMS = $(nullstring)
#Example:
#mouse: mouse.o
#	$(LD) $(LDFLAGS) -o $@ $^ $(LIBS) $(EXTRALIBS) 

#Define below this line all specific $(PROGRAMS), $(OUTLIBRARIES) rules


#Build all
all: $(OUTLIBRARIES) $(PROGRAMS)

#Clean. Delete also core and emacs/vim backup files 
clean:
	$(RM) -f $(OBJECTS) $(PROGRAMS) $(OUTLIBRARIES) *~ core* \#* 
