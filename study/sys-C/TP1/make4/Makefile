all:hello4
hello4: bonjour.o main.o identification.o
	gcc -o hello4 bonjour.o main.o
bonjour.o : bonjour.c
	gcc -c bonjour.c
main.o: main.c
	gcc -c main.c
identification.o:
	gcc -c identification.c
clean:
	rm bonjour.o main.o identification.o hello4
