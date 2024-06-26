# variables
CC=gcc
CFLAGS=-std=c11 -Wall -Werror
LDLIBS=
OUTPUT=Kgame

# targets
all: $(OUTPUT)

$(OUTPUT): K.o main.o
	cppcheck --enable=performance,unusedFunction --error-exitcode=1 --check-level=exhaustive *.c
	$(CC) $(CFLAGS) K.o main.o $(LDLIBS) -o $(OUTPUT)

main.o: main.c
	$(CC) $(CFLAGS) -c main.c $(LDLIBS) -o main.o

K.o: K.c K.h
	$(CC) $(CFLAGS) -c K.c $(LDLIBS) -o K.o

# remove compiled files
clean: 
	rm -rf $(OUTPUT) *.o
