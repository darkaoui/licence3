#include <stdio.h>

int main(){
  int n;
  int grand = 0;
  int petit = 0;
  int inc =0;
  
  while(1){
    printf("entrez une valeur: ");
    scanf("%d",&n);
    if(n == 0)
      break;

    if(inc == 0){
      petit =n;
      grand =n;
      inc++;
      continue;
    }
    
    if(n>grand)
      grand = n;
    if(n<petit)
      petit = n;
  }

  printf("le plus grand est: %d\n",grand);
  printf("le plus petit est: %d\n",petit);
}
