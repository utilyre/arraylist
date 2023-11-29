CC=gcc
CFLAGS=-I.

cvector: vector.o main.o
	$(CC) -o cvector vector.o main.o

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	rm -f *.o cvector
