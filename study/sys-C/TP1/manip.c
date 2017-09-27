#include <stdio.h>

int main(){
  int n;
  printf("Entre un entier: ");
  scanf("%d",&n);
  if(n % 2 == 0)
    printf("Le nombre est pair\n");
  else
    printf("Le nombre est impair\n");
}
