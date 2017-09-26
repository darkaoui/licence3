#include <stdio.h>

int num(char c){
  if(c>47 && c< 58)
    return 1;
  else
    return 0;
}

int alpha(char c){
  if((c>64 && c<91) || (c>96 && c<123))
    return 1;
  else
    return 0;
}
