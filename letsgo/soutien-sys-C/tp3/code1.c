#include <stdio.h>
#include <stdlib.h>

int main(){
  
  int *p = (int*)calloc(100,sizeof(int));
  
  for(int i=0; i<100; i++){  
    for(int j=0; j<i; j++) (*(p+j))++;
  }

  for(int i=0; i<100; i++){
    printf("%d\n",*(p+i));
  }
  
  free(p);

  return (EXIT_SUCCESS);
}
