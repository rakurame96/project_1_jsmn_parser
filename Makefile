# Compiler Variable
CC = gcc

# Variable for the compile process
CFLAGS = -c

# Variable for executable file
CEXE  = -o

main:
	$(CC) -g example.c jsmn.c $(CEXE) example

# jsmn.o: 	$(cc) -g jsmn.c $(CFLAGS) jsmn.o

clean: 
	rm -f *.o example

