CC = gcc
CFLAGS = -Wall -g

.PHONY: all clean

all: phonefinder add2PB

phonefinder: phonefinder.c
	$(CC) $(CFLAGS) phonefinder.c -o phonefinder


add2PB: add2PB.c
	$(CC) $(CFLAGS) add2PB.c -o add2PB	

clean: 
	rm -f *.o phonefinder