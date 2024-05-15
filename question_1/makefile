CC = gcc
CFLAGS =-g -Wall

SOURCES = q1.c q2.c q3.c
OBJECTS = $(SOURCES:.c=.o)
EXECUTABLES = q1 q2 q3

all: $(EXECUTABLES)

$(EXECUTABLES): $(OBJECTS)
	$(CC) $(CFLAGS) $@.o -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(EXECUTABLES)

.PHONY: all clean
