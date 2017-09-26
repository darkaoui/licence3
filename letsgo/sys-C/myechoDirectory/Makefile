CC=gcc
CFLAGS=-Wall
EXEC=myecho

all: $(EXEC)

myecho: strlib.o myecho.o
	$(CC) -o $@ $^

strlib.o: strlib.c
	$(CC) -o $@ -c $< $(CFLAGS)

myecho.o: myecho.c strlib.h
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(EXEC)
