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
      return 0;
  }
  return tab[4].rang;
}

int couleur(Carte tab[]){
  for(int i=1; i<5; i++)
    if(tab[i-1].color != tab[i].color)
      return 0;
  return tab[4].rang;
}

int quinteFlush(Carte tab[]){
  if(couleur(tab) != 0 && suite(tab) != 0)
    return tab[4].rang;
  else
    return 0;
}

int carre(Carte tab[]){
  int inc  = 1;
  int rang = tab[0].rang;
  
  for(int i=1; i<5; i++){
    if(tab[i].rang == rang || inc >=4)
      inc++;
    else{
      rang = tab[i].rang;
      inc  =0;
    }
  }

  if(inc >= 4)
    return tab[4].rang;

  else
    return 0;
}

int main(){
  Carte tab[]  = {{TREFLE,2},{PIQUE,4},{PIQUE,5},{COEUR,7},{TREFLE,9}};
  // Carte tab0[] = {};
  if(suite(tab) != 0)
    printf("la main tab est une suite\n");
  else
    printf("la main tab n'est pas une suite\n");

  if(couleur(tab) != 0)
    printf("la main tab est une couleur\n");
  else
    printf("la main tab n'est pas une couleur\n");

  Carte tab0[]  = {{PIQUE,2},{PIQUE,4},{PIQUE,5},{PIQUE,7},{PIQUE,9}};

  if(quinteFlush(tab0) != 0)
    printf("la main tab0 est une flush\n");
  else
    printf("la main tab0 n'est pas une flush\n");

  if(quinteFlush(tab) != 0)
    printf("la main tab est une flush\n");
  else
    printf("la main tab  n'est pas une flush\n");

  Carte tab1[]  = {{PIQUE,2},{PIQUE,2},{PIQUE,2},{PIQUE,2},{PIQUE,9}};
  if(carre(tab1) != 0)
    printf("la main tab1 est un carre\n");
  
}
