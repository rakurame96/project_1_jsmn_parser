# Compiler Variable
CC = gcc

# Variable for the compile process
CFLAGS = -c -Wall

# Variable for executable file
CEXE  = -o

# Look for .exe name and builds the necessary files (main = main.exe)
all: main

main: example.o
	$(CC) example.o $(CEXE) example -lm

example.o: example.c 
	$(CC) $(CFLAGS) example.c jsmn.c jsmn.h

# Generate the executable file
example.exe: example.o
	$(CC) example.o $(CEXE) example -lm

clean: 
	rm -f *.o *.s *.exe *.gch main

