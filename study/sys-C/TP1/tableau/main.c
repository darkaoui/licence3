#include <stdio.h>

#ifndef NB_ELEM
#define NB_ELEM 5
#endif

void  permutation(int tab_perm[], int tab[]){
  int i=0;
  while(i<NB_ELEM){
    tab_perm[i] = tab[tab_perm[i]-1];
    i++;
  }
}

void saisieValeur(int tab[]){
  int inc =0;
  int n =0;
  while(inc < NB_ELEM){
    printf("entrez une valeur:");
    scanf("%d",&n);
    tab[inc] = n;
    inc++;
  }
}


int main(){
  
  int tab[NB_ELEM];
  int tab_perm[NB_ELEM];

  printf("saisire les valeurs\n");
  saisieValeur(tab);
  
  printf("saisire les permutation\n");
  saisieValeur(tab_perm);

  permutation(tab_perm,tab);
  
  printf("les valeurs apres permutation\n");
  for(int i=0; i<NB_ELEM; i++){
    printf(" %d",tab_perm[i]);
  }
  
  printf("\n");
}
