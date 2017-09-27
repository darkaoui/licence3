#include <stdio.h>

int main(){
  int x,y,z;
  printf("entrez 3 entier chacun suivi d'espace\n");
  scanf("%d %d %d",&x,&y,&z);
  if(x <= y && z <= y)
    printf("Le plus grand est: %d \n",y);
  else if(x<=z && y<=z)
    printf("Le plus grand est: %d \n",z);
  else
    printf("Le plus grand est: %d\n",x);
}
