PREFIX		= /usr
ASOURCES=e3-16.asm
AFLAGS	= -w+orphan-labels -f as86

all:	$(ASOURCES) Makefile
	nasm $(AFLAGS) -o e3-16.o $(ASOURCES) -l e3-16.lst -D AS86 -D ELKS
	ld86 -0 -s -i -H 0xF800 -o e3 e3-16.o

install: e3
	sudo install e3 $(TARGET_MNT)/bin

clean:
	rm -f e3*.o e3*.lst e3
