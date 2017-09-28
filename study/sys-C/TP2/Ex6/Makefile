CFLAGS = -W -Wall

all: main clean

main: main.o fractions.o heron.o
	gcc -o main main.o fractions.o heron.o

main.o: main.c fractions.h
	gcc -c main.c $(CFLAGS)

fractions.o: fractions.h fractions.c
	gcc -c fractions.c $(CFLAGS)

heron.o: fractions.h
	gcc -c heron.c $(CFLAGS)

clean:
	rm *.o
