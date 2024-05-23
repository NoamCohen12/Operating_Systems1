CC = gcc
CFLAGS = -Wall -g

.PHONY: all clean

all: phonefinder

phonefinder: phonefinder.c
	$(CC) $(CFLAGS) phonefinder.c -o phonefinder

clean: 
	rm -f *.o phonefinder