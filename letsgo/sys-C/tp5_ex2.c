#include <stdio.h>
#include <stdlib.h>

int main(){
  printf("%p\n", malloc(1));
  printf("%p\n", malloc(2));
  printf("%p\n", malloc(25));
  printf("%p\n", malloc(26));
  printf("%p\n", malloc(1));
}
