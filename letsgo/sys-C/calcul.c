#include <stdio.h>


void communs(int tab1[], int tab2[], int taille){
  for(int i=0; i<taille;i++){
    for(int j=0; j<taille;j++){
      if(tab1[i] == tab2[j]){
	printf(" %d",tab1[i]);
	break;
      }
    }
  }
}

void fillTab(int n, int tab[]){
  tab[0] = n/1000;
  tab[1] = (n-tab[0]*1000)/100;
  tab[2] = (n - tab[0]*1000 - tab[1]*100)/10;
  tab[3] = (n - tab[0]*1000 - tab[1]*100 - tab[2]*10);
}

int inverse(int tab[]){
  return tab[0]*1000 + tab[1]*100 + tab[2]*10 + tab[3];
}

int main(){
  
  int a;
  int b;
  char c=' ';

  //int tab[4];
  //int *t = tab;
  //printf("bingo %d \n", t[0]);

  //test de la fonction communs
  int t1[5] = {2,4,6,7,8};
  int t2[5] = {4,7,9,1,2};
  communs(t1,t2,5);
  printf("\n");

  //test la fonction fillTab
  int t3[4];
  fillTab(1992,t3);
  printf("%d %d %d %d",t3[0],t3[1],t3[2],t3[3]);
  printf("\n");

  //test inverse
  printf("inverse %d\n", inverse(t3));
  
  printf("calcul basique\n");

  scanf("%d",&a);
  while(1)
  {
    //la capture de l'oprateur
    while(c == ' ' || c == '\n'){
      c = getchar();
    }

    scanf("%d",&b);

    switch(c){
    case '*': printf("%d",a*=b);
      break;
    case '-': printf("%d",a-=b);
      break;
    case '+': printf("%d",a+=b);
      break;
    case '/': printf("%d",a/=b);
      break;
    default:
      printf("operateur non conforme!");
    }
    c =' ';
  }
}
