# Makefile
# Project: tombseller
# Makefile for main program
# Authors: M. Antonelli, S. Pagan Griso
# Description: Define what to compile and how
# Special Notes:

include ../Makefile.config

#Put here new sources
SOURCES = tombseller.cc
OBJECTS = ${SOURCES:%.cc=%.o}

# Add here additional object files for linking
EXTRAOBJS = $(nullstring)

#Add here additional libraries we need for this section
EXTRALIBS = -luserio

#Define here test programs that you may want to build
PROGRAMS = tombseller

#Main program
tombseller: $(OBJECTS) 
	$(LD) $(LDFLAGS) -o $@ $(EXTRAOBJS) $^ $(LIBS) $(EXTRALIBS)

#Build all
all: $(OBJECTS) $(PROGRAMS)

#Clean. Delete also core and emacs/vim backup files 
clean:
	$(RM) -f $(OBJECTS) $(PROGRAMS) *~ core* \#~ 
