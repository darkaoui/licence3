#include <stdio.h>

int main(){
  int n;
  printf("entrez un nombre:\n");
  scanf("%d",&n);\
  int i=1;
  printf("les diviseurs de %d\n",n);
  while(i<n){
    if(n%i == 0)
      printf("%d\n",i);
    i++;
  }
}
