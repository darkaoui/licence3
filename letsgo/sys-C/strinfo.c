#include <stdio.h>
#include "strtests.h"

int main(){
  
  char chaine[10] = "\0\0\0\0\0\0\0\0\0\0";
  printf("Une chaine: ");
  fgets(chaine,sizeof chaine,stdin);
  printf("La chaine entree: %s",chaine);

  int alphanum =1;

  for(int i=0; i<10; i++){
    if(alpha(chaine[i]) != 1 && num(chaine[i] != 1)){
      alphanum = 0;
    }
  }
  
  if(alphanum == 1){
    printf("\nDes simboles alphanumeriques\n");
  }else
    printf("\nNo alphanumerique\n");

  return 0;
}
