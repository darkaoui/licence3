#include <stdio.h>
#include <ctype.h>
#include <string.h>

typedef struct {
  char* nom;
  char  num[10];

} ETUDIANT;

ETUDIANT* lire(ETUDIANT* e){
  e->nom = "Diallo";
  e->num[3] = 'k';
}

void affiche(ETUDIANT e){
}


int main(){
  int taille;
  char chaine[taille];
}
