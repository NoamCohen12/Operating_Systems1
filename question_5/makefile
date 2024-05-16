CC = gcc
FLAG = -Wall -g


.PHONY: all clean
all:n1 n2 n3



n1:n1.o
	$(CC) $(FLAG) -o n1

n2:n2.o
	$(CC) $(FLAG) -o n2

n3:n3.o
	$(CC) $(FLAG) -o n3







n1.o: n1.c
	$(CC) $(FLAG) -c n1.c 


n2.o: n2.c
	$(CC) $(FLAG) -c n2.c 


	
n3.o: n3.c
	$(CC) $(FLAG)  -c n3.c


clean:
	rm -f *.o n1 n2 n3 


