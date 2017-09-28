#include <stdio.h>
#include <stdlib.h>

enum color{TREFLE, PIQUE, CARRE, COEUR};

typedef struct Carte{
  int color;
  int rang;
} Carte;

int suite(Carte tab[]){
  for(int i=1; i<5; i++){
    if(tab[i].rang<tab[i-1].rang)
      return -1;
  }
  return 0;
}

int couleur(Carte tab[]){
  for(int i=1; i<5; i++)
    if(tab[i-1].color != tab[i].color)
      return -1;
  return 0;
}

int quinteFlush(Carte tab[]){
  if(couleur(tab) == 0 && suite(tab) == 0)
    return 0;
  else
    return -1;
}

int carre(Carte tab[]){
  int inc  = 1;
  int rang = tab[0].rang;
  for(int i=1; i<5; i++){
    if(tab[i] == rang)
      inc++;
    else{
      rang = tab[i];
      inc  =0;
    }
  }

  if(inc >= 4)
    return 0;

  else
    return -1;
}

int main(){
}
