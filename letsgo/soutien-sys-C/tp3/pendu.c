#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(){

  FILE *fd = fopen("pendu.txt","r");

  if(fd == NULL){
    printf("ouverture pendu.txt impossible\n");
    return -1;
  }

  char** memoire = malloc(sizeof(char*));
  memoire[0] = NULL;
  int size_mem = 1;

  char* mot = malloc(1024*sizeof(char)); // on suppose qu'un mot ne depasse 1024
   
  while(fscanf(fd,"%s\n",mot) != EOF){
   
    memoire[size_mem-1]=  mot;
    mot = malloc(1024*sizeof(char));
    memoire = realloc(memoire,(++size_mem)*sizeof(char*));
    
  }

  srand(time(NULL));
  int choice = rand()%(size_mem-1); printf("choice %d\n",choice);
  char* strchoice = memoire[choice];

  
  //printf("%s:%d\n",strchoice,strlen(strchoice));
  //printf("%s\n",memoire[choice]);

  //compter le nombre de lettre
  int nb_lettre =0;
  for(int i=0; i<(int)strlen(strchoice); i++){

    int j= 0;
    
    do{

      if(strchoice[i] == strchoice[j] && j == i){
	nb_lettre++;
	break;
      }

      if(strchoice[i] == strchoice[j])
	break;

      if(i == j)
	break;

      j++;

    }while(1);
    
  }

  printf("le mot comporte %d lettre\n",nb_lettre);

  int find[strlen(strchoice)];
  for(int i=0; i<strlen(strchoice); i++)
    find[i] = 0;
  
  int c;
  int allfind = 0;
  int coups;

  printf("entre nb coups>");
  scanf("%d",&coups);
  getchar();
  
  while(coups != 0){
    printf("caract>");
    c=getchar();

    for(int i=0; i<(int)strlen(strchoice); i++){

      if(strchoice[i] == c && find[i] == 0){
	find[i] = 1;
	allfind++;
	printf("%c",c);
      }else if(find[i] == 1)
	printf("%c",strchoice[i]);
      else
	printf("_");

    }
    
    getchar();
    printf("\n");
    //printf("\n%d\n",allfind);
    if(allfind == strlen(strchoice)){
      printf("Trouve: %s \n",strchoice);
      break;
    }

    coups--;
  }

  if(coups == 0)
    printf("Perdu...\n");

  fclose(fd);
}
