#include <stdio.h>

int streq(char s1[], char s2[]){
  if(s1 == NULL || s2 == NULL)
    return 1;

  int i=0;
  do{
    
    if(s1[i] != s2[i])
      return 1;
    
    if(s1[i] == '\0' && s2[i] == '\0')
      break;

    if(!s1[i] || !s2[i])
      return 1;

    ++i;
  }while(1);

  return 0;
}
