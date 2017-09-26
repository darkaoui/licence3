all: joueur1 joueur2 joueur3

joueur1: joueur1.o joueur.o
	gcc joueur.o joueur1.o -o joueur1
joueur2: joueur2.o joueur.o
	gcc joueur.o joueur2.o -o joueur2
joueur3: joueur3.o joueur3.o
	gcc joueur.o joueur3.o -o joueur3

joueur.o: joueur.c
	gcc -c joueur.c
joueur1.o: joueur1.c
	gcc -c joueur1.c
joueur2.o: joueur2.c
	gcc -c joueur2.c
joueur3.o: joueur3.c
	gcc -c joueur3.c

clean: rm joueur1.o joueur.o
