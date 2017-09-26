#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void intToTab(int tab[], int n){
  tab[0] = n/1000;
  tab[1] = (n - tab[0]*1000)/100;
  tab[2] = (n - tab[0]*1000 - tab[1]*100)/10;
  tab[3] = (n - tab[0]*1000 - tab[1]*100 - tab[2]*10);
}

int tabToInt(int tab[]){
  return tab[0]*1000+tab[1]*100+tab[2]*10+tab[3];
}

int invTabToInt(int tab[]){
  return tab[3]*1000+tab[2]*100+tab[1]*10+tab[0];
}

void croissant(int tab[], int n){
  for(int i=0; i<n; i++){
    for(int j=i+1; j<n; j++){
      if(tab[i]>tab[j]){
	int tp = tab[i];
	tab[i] = tab[j];
	tab[j] = tp;
      }
    }
  }
}

void decroissant(int tab[], int n){
  for(int i=0; i<n; i++){
    for(int j=i+1; j<n; j++){
      if(tab[i]<tab[j]){
	int tp = tab[i];
	tab[i] = tab[j];
	tab[j] = tp;
      }
    }
  }
}

int main(){

  printf("rand max: %d \n", RAND_MAX);

  int n;
  int tab[4];

  do{
    
    printf("Entier de 4 chiffres: ");
    scanf("%d",&n);

    if(n/10000 != 0)
      printf("Pas un entier 4 chiffres!!\n");

  }while(n/10000 != 0);

  while(1){
    intToTab(tab,n);

    decroissant(tab,4);
    int big   = tabToInt(tab);

    croissant(tab,4);
    int small = tabToInt(tab);

    int diff  = big-small;
    printf("big:%d small:%d diff:%d\n",big,small,diff);

    if (n == diff)
      break;
    
    n = diff;
  }
}
