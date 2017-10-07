#include <stdio.h>
#include <stdlib.h>

//Question 8
int tab_equal(int[], int[], int);


//Question 9
int set_max(int[], int, int*);

//Question 10
int remove_elem(int[], int, int);

//Question 11
void echange(int[], int, int);

//Question 12
void mirror(int[], int);


int main(){

  int tab[] ={3,4,5,9,7,8,9};
  int max;
  int oc = set_max(tab,7,&max);

  printf("les occurences %d, le max %d\n", oc, max);


  printf("la table         >");
  for(int i=0; i<7; i++){
    printf("%d ",tab[i]);
  }
  puts("\n");

  mirror(tab,7);
  printf("la table miroiter>");
  for(int i=0; i<7; i++){
    printf("%d ",tab[i]);
  }

  puts("\n");


  int newt = remove_elem(tab,7,9);
  printf("la table: element 9 supprime> ");
  for(int i=0; i<newt; i++){
    printf("%d ",tab[i]);
  }

  puts("\n");
  
}


/*
  definition des fonctions
  
 */

int tab_equal(int tab1[], int tab2[], int taille){
  //Supposons que les 2 tableau sont tries
  for(int i=0; i<taille; i++){
    if(tab1[i] != tab2[i])
      return 0;
  }

  return 1;
}

int set_max(int tab[], int taille, int *adrmax){
  int max;
  max = tab[0];

  int oc = 1;

  for(int i=1; i<taille; i++){
    if(max < tab[i]){
      max = tab[i];
      oc =1;
    }else if(max == tab[i])
      oc++;
  }

  *adrmax = max;
  
  return oc;
}

void echange(int tab[],int i, int j){
  int tmp = tab[i];
  tab[i]  = tab[j];
  tab[j]  = tmp;
}

void decalage_gauche(int tab[], int taille,  int index){
  for(int i=index; i<taille-1; i++){
    tab[i] = tab[i+1];
  }
}

int remove_elem(int tab[], int taille, int x){

  int oc =0;
  int newtaille = taille;

  //faire le decalage
  for(int i=0; i<taille; i++){
    if(tab[i] == x){
      decalage_gauche(tab,taille,i);
      oc++;
      newtaille--;
    }
  }

  return newtaille;
}


void mirror(int tab[], int taille){
  for(int i=0; i<taille; i++){
    echange(tab,i,taille-i-1);
    //les 2 index gauche droite ce sont rencontre
    if( (taille-i-1-i) == 1 || (taille-i-1-i) == 0 )
      break;
  }
}
