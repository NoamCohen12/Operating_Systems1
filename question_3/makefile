.PHONY: all clean

all: q3

q3: q3.o libpoisson.so
	gcc q3.o -L. -lpoisson -o q3 -lm

q3.o: q3.c poisson.h
	gcc -c q3.c -o q3.o 

libpoisson.so: poisson.o
	gcc -shared poisson.o -o libpoisson.so

poisson.o: poisson.c poisson.h
	gcc -c -fPIC poisson.c -o poisson.o

clean:
	rm -f *.o libpoisson.so q3

