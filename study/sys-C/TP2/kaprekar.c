#include <stdio.h>

int tabToInt(int tab[]){
  int r;
  r += tab[0]*1000;
  r += tab[1]*100;
  r += tab[2]*10;
  r += tab[3];
  return r;
}

int tabTonIntRevers(int tab[]){
  int r;
  r+= tab[0];
  r+= tab[1]*10;
  r+= tab[2]*100;
  r+= tab[3]*1000;
  return r;
}

void intTotab(int k,int tab[]){
  
}

int main(){
  int n =4
  int tab[n];
  
}
