# Makefile for the ELKS 286pmode extender.
#
# Note! Dependencies are done automagically by 'make dep', which also
# removes any old dependencies. DON'T put your own dependencies here
# unless it's something special (ie not a .c file).
#
#########################################################################
# Relative path to base directory.

BASEDIR 	= ../../..

#########################################################################
# Define the variables required by the standard rules - see the standard
# rules file (below) for details of these variables.

USEBCC  	= Y

CLEANDEP	= 

CLEANME 	= pmode286

DEPEND  	= 

DISTFILES	= 

NOINDENT	= main.c

#########################################################################
# Include standard commands.

include $(BASEDIR)/Makefile-rules

#########################################################################
# Objects to be compiled. crt0.o should be first.

OBJS  = crt0.o main.o irq.o

#########################################################################
# Commands.

all:	pmode286

pmode286: $(OBJS)
	$(LD) $(LDFLAGS) -i $(OBJS) ../lib/lib86.a -M -o pmode286 \
		> $(BASEDIR)/pmode286.map

#########################################################################
# Standard commands.

distdir:
	cp -pf Makefile *.c *.h $(DISTDIR)/arch/i86/286pmode
	cp -pf crt0.s irq.s $(DISTDIR)/arch/i86/286pmode

#########################################################################
### Dependencies:
