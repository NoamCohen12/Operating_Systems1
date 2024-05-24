CC = gcc
FLAG = -Wall -g
CGOV = -fprofile-arcs -ftest-coverage

.PHONY: all clean

run: dijkstra
	for file in *.txt; do \
		./dijkstra <$$file || true; \
	done
	gcov q4.c

dijkstra: q4.o
	$(CC) $(FLAG) $(CGOV) q4.o -o dijkstra 

q4.o: q4.c
	$(CC) $(FLAG) $(CGOV) -c q4.c

clean:
	rm -f *.o *.gcov *.gcno *.gcda dijkstra