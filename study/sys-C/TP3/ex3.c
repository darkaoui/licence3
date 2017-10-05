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
  printf("hello world");
}


int tab_equal(int tab1[], int tab2[], int taille){
  //Supposons que les 2 tableau sont tries
  for(int i=0; i<taille; i++){
    if(tab1[i] != tab2[i])
      return 0;
  }

  return 1;
}

int set_max(int tab[], int taille, int *adrmax){
  int *max;
  max = tab;

  int oc =0;

  for(int i=1; i<taille; i++){
    if(*max < tab[i]){
      max = (tab+i);
      oc =0;
    }else if(*max == tab[i])
      oc++;
  }

  return oc;
}

void echange(int tab[],int i, int j){
  int tmp = tab[i];
  tab[i]  = tab[j];
  tab[j]  = tmp;
}

int decalage_gauche(int tab[], int taille,  int index){
  for(int i=index; i<taille-1; i++){
    tab[i] = tab[i+1];
  }
}

int remove_elem(int tab[], int taille, int x){

  int oc =0;
  int newtaille = taille;
  
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
  for(int i=0; i<taille-1; i++){
    echange(i,taille-i);
    if(i == (taille-i))
      break;
  }
}



