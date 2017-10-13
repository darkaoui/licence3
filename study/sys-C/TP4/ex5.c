#include <stdio.h>
#include <stdlib.h>


int main(){

  int colonne   = 2;
  int ligne     = 10;

  //parcourir le tableau sans utilise [.]: on accede a la premiers valeur du tableau qui est un pointeur
  //puis on de roule par un incrementeur(voir le remplissage et l'affichage)

  // On a notre tableau a memoire contigue
  int **tableau = (int **)malloc(colonne*sizeof(int*));
  tableau[0]    = (int*)malloc(ligne*colonne*sizeof(int));
  for(int i=1; i<colonne; i++){
    tableau[i] = tableau[0] + i*ligne;
  }

  //remplissage du tableau par des zero
  for(int i=0; i<ligne*colonne; i++){
    *(*tableau+i) = 0;
  }

  //l'affichage d'une ligne( le 2eme element)
  printf("2eme ligne %d\n", *(*tableau+1));

  //l'affichage d'une colonne

  //premiere colonne
  printf("premiere colonne: ");
  for(int i=0; i<ligne; i++){
    printf("%d ",*(*tableau+i));
  }

  printf("\n");

  //deuxieme colonne
  printf("premiere colonne: ");
  for(int i=0; i<ligne; i++){
    printf("%d ",*(*tableau+i));
  }


  printf("\n");
  
}
