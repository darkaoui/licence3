#include "fractions.h"

fraction heron(unsigned int,int);

int main(){
  fraction ex_fractions[] = {{1,1},{1,2},{2,4},{15,10},{-9,3},{-5,-10},{1,-3}};
  int taille = sizeof(ex_fractions)/sizeof(ex_fractions[0]);
  for(int i=0; i<taille;i++)
    affiche_fraction(ex_fractions[i]);

  int a,n;
  printf("\nSuite de hereon\na=");
  scanf("%d",&a);
  printf("n=");
  scanf("%d",&n);
  printf("heron>\n");
  affiche_fraction(heron(a,n));
}


//Question pour le denominateur egale a 0
//Question sur le debordement du heron
