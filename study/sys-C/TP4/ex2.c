#include <stdio.h>
#include <stdlib.h>


typedef struct ensemble{
  unsigned int taille;
  int* tab;
}ensemble;


ensemble* allouer_ensemble(int i){
  ensemble* e = (ensemble*)malloc(sizeof(ensemble));
  e->tab    = (int*)malloc(sizeof(int)*i);
  e->taille = i;
  return e;
}

void liberer_ensemble(ensemble *e){
  free(e->tab);
  free(e);
}

void saisir_ensemble(ensemble* e){
  printf("saisir l'ensemble:\n");
  for(int i=0; i<e->taille; i++){
    printf("val>");
    scanf("%d",(e->tab+i));
  }
}

void afficher_ensemble(ensemble *e){
  int inc =0;
  int i   =0;
  while(1){
    
    if(inc == e->tab[i]){
      printf("*");
      i++;
    }else
      printf(" ");
    
    inc++;

    if(e->taille == i)
      break;
  }
  puts("\n");
}


ensemble* union_ensembles(ensemble* e1, ensemble* e2){
  int i1 =0;
  int i2 =0;

  ensemble* e= allouer_ensemble(1);

  if(e1->tab[0] < e2->tab[0]){
    e->tab[0] = e1->tab[0];
    i1++;
  }else if(e1->tab[0] > e2->tab[0]){
    e->tab[0] = e2->tab[0];
    i2++;
  }else{
    e->tab[0] = e1->tab[0];
    i1++;
    i2++;
  }
  
  while(1){

    if(i1<e1->taille && i2<e2->taille){

      if(e1->tab[0] < e2->tab[0]){
	
	e->tab    = (int*)realloc(e->tab,(++(e->taille))*sizeof(int));
	e->tab[e->taille-1] = e1->tab[i1];
	i1++;
	
      }else if(e1->tab[0] > e2->tab[0]){

	e->tab    = (int*)realloc(e->tab,(++(e->taille))*sizeof(int));
	e->tab[e->taille-1] = e2->tab[i2];
	i2++;

      }else{
	
	e->tab    = (int*)realloc(e->tab,(++(e->taille))*sizeof(int));
	e->tab[e->taille-1] = e1->tab[i2];
	i1++;
	i2++;
      }
      
    }else if(i1<e1->taille){

      e->tab    = (int*)realloc(e->tab,(++(e->taille))*sizeof(int));
      e->tab[e->taille-1] = e1->tab[i2];
      i2++;
      
    }else if(i2<e2->taille){

      e->tab    = (int*)realloc(e->tab,(++(e->taille))*sizeof(int));
      e->tab[e->taille-1] = e2->tab[i1];
      i1++;
      
    }

    if(i1>=e1->taille && i2>=e2->taille)
      break;
  }

  return e;
}


int main(){
  ensemble *e1= allouer_ensemble(5);
  ensemble *e2= allouer_ensemble(5);
  
  saisir_ensemble(e1);
  afficher_ensemble(e1);

  saisir_ensemble(e2);
  afficher_ensemble(e2);

  printf("l'ensemble:\n");
  ensemble *e = union_ensembles(e1,e2);
  afficher_ensemble(e);

  liberer_ensemble(e1);
  liberer_ensemble(e2);
  liberer_ensemble(e);
}
