#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void aaa(char *s){
  while(*s) *(s++) = 'A';
}

int main(){
  char *s = "hello";

  s = malloc(10);

  strcpy(s,"hello");
  aaa(s);
  
  printf("%s\n",s);

  if(!s[10])
    printf("Waaaouu\n");

  char ss = '\0';
  printf("ss%css",ss);
  
}
