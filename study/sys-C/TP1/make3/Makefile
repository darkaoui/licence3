all:hello3
hello3: bonjour.o main.o
	gcc -o hello3 bonjour.o main.o
bonjour.o : bonjour.c
	gcc -c bonjour.c
main.o: main.c
	gcc -c main.c
clean:
	rm bonjour.o main.o
