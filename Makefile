CC=gcc
AR=ar
FLAGS= -Wall -g

all: connections

connections: main.o my_mat.o
	$(CC) $(FLAGS) -o connections main.o my_mat.o
main.o: main.c my_mat.h
	$(CC) $(FLAGS) -c main.c
my_mat.o: my_mat.c my_mat.h
	$(CC) $(FLAGS) -c my_mat.c

.PHONY: clean all
clean:
	rm -f *.o *.a *.so connections