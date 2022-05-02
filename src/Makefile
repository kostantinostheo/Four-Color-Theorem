CC=gcc

CFLAGS=-c -lm

all: mapcol

mapcol: main.o graphImp.o coloringImp.o
	$(CC) -o mapcol main.o graphImp.o coloringImp.o

main.o: main.c
	$(CC) $(CFLAGS) main.c

graphImp.o: graphImp.c
	$(CC) $(CFLAGS) graphImp.c

coloringImp.o: coloringImp.c
	$(CC) $(CFLAGS) coloringImp.c

clean:
	rm -rf *o mapcol
