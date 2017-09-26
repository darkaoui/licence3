#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

char* phrase_passe(int nombre, int taille, char* tab[taille]){
  int longueur =0;
  int choisies[nombre];

  if(taille == 1){
    fprintf(stderr,"Erreur,aucun mot rentre!\n");
    exit(1);
  }

  else if(nombre>taille){
    fprintf(stderr,"Erreur,le nombre de mots a choisir ne peut exceder la taille du tableau!\n");
    exit(2);
  }

  for(int i=0; i<nombre;i++){
    choisies[i] = 1+ rand()%(taille-1);
    longueur+= strlen(tab[choisies[i]]);
  }

  char* result = (char*) malloc((longueur+1)*sizeof(*result));
  char* pres   = result;

  //on copie les chaines selectionnees
  for(int i=0; i<nombre; i++){
    strcpy(pres,tab[choisies[i]]);
    pres+= strlen(tab[choisies[i]]); //c'est malin
  }

  *(pres+longueur)='\0';
  return result;
    
}

int main(int argc, char* argv[]){
  srand(time(NULL));

  char* s= phrase_passe(4,argc,argv);
  printf("Phrase de passe avec 4 mots:\n%s\n",s);

  free(s);

  return EXIT_SUCCESS;
}
