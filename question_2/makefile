.PHONY: all clean

all: poisson

poisson: poisson.o
	gcc poisson.o -o poisson -lm


poisson.o: poisson.c
	gcc -Wall -c poisson.c


clean:
	rm -f *.o poisson;