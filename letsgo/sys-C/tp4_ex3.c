#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
  char *chaine;
  int len;
} super_str;

int cmpstr(void const *a, void const *b){
  return strcmp((char*)a,(char*)b);
}

int cmpstr_super(void const *a, void const *b){
  return strcmp( ((super_str*)a)->chaine, ((super_str*)b)->chaine );
}

int cmpstr_super1(void const *a , void const *b){
  return ((super_str*)a)->len - ((super_str*)b)->len;
}

void map(int tab[], int nb, int (*f)(int) ){
  for(int i=0; i<nb; i++)
    tab[i] = f(tab[i]);
}

int fpointer(int a){
  return (-a);
}

int main(int argc, char* argv[]){

  const int taille = 5;
  char chaines[5][10] = {"world","hello","wild","alpha","Wonjourle"};
  super_str *super_chaine = malloc(4*sizeof(*super_chaine));

  //On remplie la super chaine
  super_str *ch = NULL;
  
  for(int i=0; i<taille; i++){
    ch = malloc(sizeof *ch);
    ch->chaine = chaines[i];
    ch->len    = strlen(chaines[i]);
    
    *(super_chaine+i) = *ch; //fuite de memoire
  }

  //printf("point %d ,non point %d  sur %d",sizeof(super_str*), sizeof(super_str), sizeof(*super_chaine));


  //printf("taille individuelle %d \n", sizeof(*chaines));
  //qsort(chaines,4,10,cmpstr);

  //for(int i=0; i<4; i++){
  //  printf("%s\n",chaines[i]);
  //}

  if(argc >= 2){

    if(strcmp(argv[1],"-t") == 0){

      qsort(super_chaine,taille,sizeof (super_str),cmpstr_super1);
      for(int i=0; i<taille;i++){
	printf("%s\n" ,(super_chaine+i)->chaine);
      }
      printf("Parametre -t\n");

    }else if(strcmp(argv[1],"--crazy") == 0){
      
      qsort(super_chaine,taille,sizeof (super_str),cmpstr_super);

      //Mettre les conditions
      
      //affiche la taille 4
      for(int i=0; i<taille; i++){
	
	if( (super_chaine+i)->len == 4)
	  printf("%s\n", (super_chaine+i)->chaine );
	
      }

      //Ceux qui commence par W
      for(int i=0; i<taille; i++){
	
	if( (super_chaine+i)->len != 4 && (super_chaine+i)->chaine[0] == 'W')
	  printf("%s\n", (super_chaine+i)->chaine );
	
      }

      //Le reste
      for(int i=0; i<taille; i++){
	
	if( (super_chaine+i)->len != 4 && (super_chaine+i)->chaine[0] != 'W' )
	  printf("%s\n", (super_chaine+i)->chaine );
	
      }
      
      printf("Parametre --crazy");
    } 
  }

  //Pour la derniere question
  int tableau [5] = {2,3,5,6,7};
  map(tableau,5,fpointer);
  
  for(int i=0; i<5; i++){
    printf("%d\n",tableau[i]);
  }
  
}
