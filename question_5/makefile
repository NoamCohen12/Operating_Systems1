CC = gcc
FLAG = -pg -Wall -g 


.PHONY: all clean

all:n1 n2 n3



n1:n1.o main.o
	$(CC) $(FLAG) n1.o main.o -o n1

n2:n2.o main.o
	$(CC) $(FLAG) n2.o main.o -o n2

n3:n3.o main.o
	$(CC) $(FLAG) n3.o main.o -o n3



n1.o: n1.c
	$(CC) $(FLAG) -c n1.c 


n2.o: n2.c
	$(CC) $(FLAG) -c n2.c 
	
n3.o: n3.c
	$(CC) $(FLAG)  -c n3.c

main.o:main.c
	$(CC) $(FLAG)  -c main.c



clean:
	rm -f *.o *.out n1 n2 n3 


