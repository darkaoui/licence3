#include <stdio.h>
#include <stdlib.h>

typedef struct tableau{
  int nb_max;
  int taille;
  int *tab;
}tableau;


// numbrer 1
tableau* init(int c){
  tableau *tab = malloc(sizeof(tableau));
  tab->nb_max =c;
  tab->taille = 0;
  tab->tab    = malloc(c*sizeof(int));

  return tableau;
}

// number 2
void del(tableau* t){

  t->nb_max =0;
  t->taille =0;

  free(t->tab);
  free(t);
  
}

//number 3
void add(tableau* t, int a){
  t->taille++;

  if(t->taille>nb_max){
    t->nb_max++;
    t->tab = realloc(t->tab,sizeof(int)*t->taille);
    t->tab[t->taille-1] = a;
  }else
    t->tab[t->taille-1] = a;
  
}

//number 4
void add_pos(tableau *t, int a, int pos){

  if(pos>taille-1)
    return;
  
  t->taille++;

  if(t->taille > t->nb_max){
    t->tab = realloc(t->tab,sizeof(int)*t->taille);
    t->nb_max++;
  }

  memmove(t->tab+pos,t->tab+pos+1,t->taille-pos);
}

//number 5
void del_pos(tableau *t, int pos){
  if(pos>taille-1)
    return;

  if(pos != taille-1)
    memmove(t.tab+pos+1,t.tab+pos,t.taille-1-pos);
  
  t.taille--;
}

//number 6
void change_pos(tableau *t, int a, int pos){
  if(t->taille<pos)
    return;
  
  t->tab[pos] = a;
}

//number 7
void find(tableau *t, int a){
  for(int =0; i<t->taille; i++){
    if(t->tab[i] == a)
      return 1;
  }

  return 0;
}


int main(){

}
