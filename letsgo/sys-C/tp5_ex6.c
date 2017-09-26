#include <stdio.h>
#include <stdlib.h>

typedef struct pile_amortie{
  int occupation;
  int capacite;
  int *elements;
} pile_amortie;

pile_amortie* alloue_pile_amortie(){
  pile_amortie* p = malloc(sizeof(pile_amortie));
  p->occupation =0;
  p->capacite   =0;
  return p;
}


void libere_pile_amortie(pile_amortie* p){
  free(p->elements);
  p->occupation=0;
  p->capacite  =0;
}

void empile_pile_amortie(pile_amortie* p, int n){

  if(p->occupation < p->capacite){
    p->elements[p->occupation] = n;
    p->occupation+=1;
  }else{
    
    int s = sizeof(pile_amortie)*(p->occupation);
    p->elements = realloc(p->elements,s);

    p->elements[p->occupation] = n;
    p->occupation+=1;

    p->capacite= s;
    
  }
  
}

int depile_pile_amortie(pile_amortie* p){

  int vide = p->capacite - p->occupation;
  
  if(vide <= (p->occupation*3)){

    p->elements = realloc(p->elements,vide/2);
    p->capacite = vide/2;
    int i = p->occupation;
    p->occupation-=1;
    return p->elements[i-1];

  }else{

    int i = p->occupation;
    p->occupation-=1;
    return p->elements[i-1];

  }
}

int main(){
  pile_amortie* p = alloue_pile_amortie();

  printf("debut1\n");

  empile_pile_amortie(p,2);

  printf("debut2\n");
  
  empile_pile_amortie(p,5);

  printf("debut3\n");
  
  printf("%d\n", depile_pile_amortie(p));
  printf("%d\n", depile_pile_amortie(p));
}
