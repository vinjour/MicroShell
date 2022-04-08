CC=gcc
FLAGS=-Wall  -g

all : prog

prog : 	shell.o
		$(CC) shell.o -o prog

shell.o :		shell.c shell.h
					$(CC) -c shell.c $(FLAGS) -o shell.o

clean :
		rm -f *.o
		rm -f prog