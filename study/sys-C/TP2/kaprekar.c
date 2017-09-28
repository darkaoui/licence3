#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int tabToInt(int tab[]){
  return tab[0]*1000+tab[1]*100+tab[2]*10+tab[3];
}

int tabToIntReverse(int tab[]){
 return tab[0]+tab[1]*10+tab[2]*100+tab[3]*1000;
}

void intToTab(int k,int tab[]){
  tab[3] =  k%10;
  tab[2] = (k%100)/10;
  tab[1] = (k%1000)/100;
  tab[0] = (k%10000)/1000;
}

void triCroissant(int tab[]){
  //tri selection
  for(int i=0; i<4; i++){
    for(int j=i; j<4; j++){
      if(tab[i] > tab[j]){
	int tmp = tab[i];
	tab[i]  = tab[j];
	tab[j]  = tmp;
      }
    }
  }
}

//verifie si une valeur v est present dans tab
int valueInTab(int v, int tab[], int limit){
  for(int i=0;i<limit; i++){
    if(tab[i] == v)
      return 0;
  }
  return -1;
}

//choisie de facon 2 a 2 different
int randomValue(){
  int tab[4];
  int inc = 0;
  int r;
  while(inc != 4){
    r =rand()%10;
    if(valueInTab(r,tab,inc+1) == 0)
      continue;
    tab[inc] = r;
    inc++;
  }
  return tabToInt(tab);
}


int main(){
  srand(time(NULL));
  
  int n =4;
  int tab[n];
  int k;
  char c = '3';
  
  printf("Pour une valeur random 0\n");
  printf("Pour une valeur saisie autre\n>");
  c =getchar();
  getchar();
    
  if(c == '0'){
    k = randomValue();
    printf("la valeur random trouve %d\n",k);
  }else{
    do{
      printf("entrez une valeur de 4 chiffres>");
      scanf("%d",&k);
    }while(k>9999);
  }
    

  int small, big, diff;
  
  while(1){

    intToTab(k,tab);
    triCroissant(tab);
  
    small = tabToInt(tab);
    big   = tabToIntReverse(tab);

    printf("small = %d\nbig = %d\n",small,big);

    diff = big - small;

    printf("diff = %d\n",diff);

    if(k != diff)
      k = diff;
    else{
      printf("la valeur de k est %d\n",k);
      break;
    }
  }
  
}

//Question

//Est-ce que les valeurs plus petites que 1000 sont admise
