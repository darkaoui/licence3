#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{

  int key;
  struct node *fg;
  struct node *fd;
  
} node;

void arroser(node* abr){
  
  if(abr->fg != NULL && abr->fd != NULL){
    arroser(abr->fg);
    arroser(abr->fd);
  }
  else{
    
    node* n = malloc(sizeof (node));
    node* t = malloc(sizeof (node));
    
    n->key = 4; n->fg = NULL; n->fg = NULL;
    t->key = 5; t->fd = NULL; t->fd = NULL;
    
    abr->fg  = n;
    abr->fd  = t;
  }

}

void greffer(node *a, int p[], node *b ){
  int i=0;
  do{

    if(p[i] == 0){

      //printf("key= %d",n->key);
      if(a->fg == NULL){
	a->fg = b;
	printf(" Done %d",i);
	break;
      }else
	a = a->fg;
      
    }else if(p[i] == 1){

      //printf("key= %d",n->key);
      if(a->fd == NULL){
	a->fd = b;
	printf("Done");
	break;
      }else
	a = a->fd;
    }
    
    i+=1;
  }while(1);
}

void affiche(node *n ){
  printf(",Node(%d",n->key);

  if(n->fg != NULL)
    affiche(n->fg);
  else
    printf(",NULL");

  if(n->fd != NULL)
    affiche(n->fd);
  else
    printf(",NULL");

  printf(")");
  
}

int main(){


  node n = {6,NULL,NULL};
  node n1 = {8,NULL,NULL};
  int p[5] = {0,1,0,1,1};

  arroser(&n1);
  arroser(&n);

  affiche(&n);
  printf("\n");
  affiche(&n1);

  greffer(&n,p,&n1);
  //gref(&n,&n1);
  printf("\n");
  
  affiche(&n);
  printf("\n");
}
