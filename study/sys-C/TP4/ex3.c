#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

  return tab;
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

  if(t->taille>t->nb_max){
    t->nb_max = t->nb_max*2;
    t->tab = (int*)realloc(t->tab,sizeof(int)*t->nb_max);
    t->tab[t->taille-1] = a;
  }else
    t->tab[t->taille-1] = a;
  
}

//number 4
void add_pos(tableau *t, int a, int pos){

  if(pos>t->taille-1)
    return;

  if(t->taille > t->nb_max){
    t->nb_max *=2;
    t->tab = (int*)realloc(t->tab,sizeof(int)*t->nb_max);
  }

  memmove(t->tab+pos+1,t->tab+pos,t->taille-pos);

  t->taille++;
  t->tab[pos] = a;
  
  return;
}

//number 5
void del_pos(tableau *t, int pos){
  if(pos>t->taille-1)
    return;

  if(pos != t->taille-1)
    memmove(t->tab+pos,t->tab+pos+1,t->taille-pos);
  
  t->taille--;
}

//number 6
void change_pos(tableau *t, int a, int pos){
  if(t->taille<pos)
    return;
  
  t->tab[pos] = a;
}

//number 7
int find(tableau *t, int a){
  for(int i=0; i<t->taille; i++){
    if(t->tab[i] == a)
      return 1;
  }

  return 0;
}


int main(){
  tableau *t = init(5);
  int c;
  
  while(1){

    printf("0:sortir\n1:ajout\n2:ajout pos\n3:supprimer pos\n4:remplace pos\n5:recherche valeur\n>");
    scanf("%d",&c);

    if(c == 0)
      break;

    printf("valeur>");
      
    if(c == 1){

      int v;
      scanf("%d",&v);
      add(t,v);

    }else if(c == 2){

      int v;
      int pos;
      scanf("%d",&v);
      printf("position>");
      scanf("%d",&pos);
      add_pos(t,v,pos);
      
    }else if(c == 3){

      int v;
      scanf("%d",&v);
      del_pos(t,v);
      
    }else if(c == 4){

      int v;
      int pos;
      scanf("%d",&v);
      printf("position>");
      scanf("%d",&pos);
      change_pos(t,v,pos);
      
    }else if(c == 5){

      int v;
      scanf("%d",&v);
      if(find(t,v) == 1)
	printf("\n************\n>> contient\n************");
      else
	printf("\n*************\n>> ne contient pas\n**************\n");
    }

    printf("\n*****************\ntableau: ");
    for(int i=0; i<t->taille; i++){
      printf("%d ",*(t->tab+i));
    }
    printf("\n*****************\n");
  }

  printf("\n");

  printf("A bientot\n");
  del(t);
  
}
