#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct liste_entier{
  int entier;
  struct liste_entier *suivant;
} liste;

liste *cree_element(int n){
  liste * liste = malloc(sizeof(liste));
  liste->entier  = n;
  liste->suivant = NULL;
  return liste;
}

liste *ajoute_element(liste* nouvel_element, liste *liste_courante){
  liste *tmp = NULL;
  tmp = liste_courante;

  //int stop = 1;

  if(nouvel_element->entier < liste_courante->entier){
    nouvel_element->suivant = liste_courante;
    return nouvel_element;
  }
  
  do{
    
    if(liste_courante->suivant == NULL){
	liste_courante->suivant = nouvel_element;
	return tmp;
    }

    if(liste_courante->suivant->entier <= nouvel_element->entier){
      liste_courante = liste_courante->suivant;
    }else{
      nouvel_element->suivant = liste_courante->suivant;
      liste_courante->suivant = nouvel_element;
      return tmp;
    }
    
  }while(1);

  return tmp;
}

void affiche(liste* list){
  while(list != NULL){
    printf("val %d\n", list->entier);
    list = list->suivant;
  }
}

int main(){
  
  liste *list  = cree_element(1);
  liste *element2  = cree_element(2);
  list = ajoute_element(element2, list);
  
  element2 = cree_element(4);
  list = ajoute_element(element2, list);
  
  element2 = cree_element(5);
  list = ajoute_element(element2,list);

  element2 = cree_element(3);
  list = ajoute_element(element2,list);

  element2 = cree_element(8);
  list = ajoute_element(element2,list);

  element2 = cree_element(0);
  list = ajoute_element(element2,list);

  element2 = cree_element(7);
  list = ajoute_element(element2,list);

  element2 = cree_element(6);
  list = ajoute_element(element2,list);

  affiche(list);
}
