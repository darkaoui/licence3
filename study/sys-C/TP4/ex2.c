#include <stdio.h>
#include <stdlib.h>


typedef struct ensemble{
  unsigned int taille;
  int* tab;
}ensemble;


emsemble* allouer_ensemble(int i){
  ensemble* e = malloc(sizeof(ensemble));
  e->tab = malloc(sizeof(int)*i);
  return e;
}

void liberer_ensemble(ensemble *e){
  free(e.tab);
  free(e);
}

void saisir_ensemble(ensemble* e){
  int n; 
  printf("taille de l'ensemble: ");
  scanf("%d",&n);
  
  e->tab = malloc(sizeof(int)*n);

  for(int i=0; i<n; i++){
    printf("val>");
    scanf("%d",(e->tab+i));
  }
}

void affiche_ensemble(ensemble *e){
  int inc =0;
  int i   =0;
  while(1){
    
    if(inc == e->tab[i]){
      printf("*");
      i++;
    }else
      printf(" ");
    
    inc++;

    if(taille == i)
      break;
  }
}


ensemble union_ensembles(ensemble e1, ensemble e2){
  int i1;
  int i2;

  ensemble e;
  e.taille= 1; 
  e.tab   = malloc(sizeof(int));

  if(e1.tab[0] < e2.tab[0]){
    e.tab[0] = e1.tab[0];
    i1++;
  }else if(e1.tab[0] > e2.tab[0]){
    e.tab[0] = e2.tab[0];
    i2++;
  }else{
    e.tab[0] = e1.tab[0]
    i1++;
    i2++;
  }
  
  while(1){

    if(i1<taille && i2<taille){

      if(e1.tab[0] < e2.tab[0]){
	
	e.tab    = realloc(e.tab,(++(e.taille))*sizeof(int));
	e.tab[e.taille-1] = e1.tab[i1];
	i1++;
	
      }else if(e1.tab[0] > e2.tab[0]){

	e.tab    = realloc(e.tab,(++(e.taille))*sizeof(int));
	e.tab[e.taille-1] = e2.tab[i2];
	i2++;

      }else{
	
	e.tab    = realloc(e.tab,(++(e.taille))*sizeof(int));
	e.tab[e.taille-1] = e1.tab[i2];
	i1++;
	i2++;
      }
      
    }else if(i1<taille){

      e.tab    = realloc(e.tab,(++(e.taille))*sizeof(int));
      e.tab[e.taille-1] = e2.tab[i2];
      i2++;
      
    }else if(i2<taille){

      e.tab    = realloc(e.tab,(++(e.taille))*sizeof(int));
      e.tab[e.taille-1] = e1.tab[i1];
      i1++;
      
    }

    if(i1==taille && i2==taille)
      break
  }

  return e;
}


int main(){

}
