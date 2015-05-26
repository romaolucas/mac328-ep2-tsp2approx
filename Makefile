CC = gcc
CFLAGS = -Wall -ansi -pedantic -std=c99 -g

shortcuts: main.c digraph.o algs.o union_find.o
	$(CC) $^ -o $@ $(CFLAGS)

algs.o: algs.c algs.h union_find.h digraph.h
	$(CC) $(CFLAGS) -c algs.c

union_find.o: union_find.c union_find.h digraph.h
	$(CC) $(CFLAGS) -c union_find.c 

digraph.o: digraph.c digraph.h
	$(CC) $(CFLAGS) -c digraph.c
