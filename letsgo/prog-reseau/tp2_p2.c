#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int verifier(FILE* file){
  int c;
  while((c=fgetc(file)) != EOF){
    if(c < '0' || c > '9')
      return -1;
  }

  return 0;
}

int main(int argc, char* argv[] ){

  FILE *file;
  int alire;
  int pivot;
  
  if(argc == 4){

    if(strcmp(argv[1],"-I") == 0)
      file = stdin;
    else
      file = fopen(argv[1],"r");
    
    if((alire = atoi(argv[2])) == 0)
      return -1;

    if((pivot = atoi(argv[3])) == 0)
      return -1;

    char *chaine =  malloc((alire+1)*sizeof(char));
    char *chaines = malloc(sizeof(char));
    
    char *chaineDer = malloc((alire+1)*sizeof(char));
    int lus = 0;
    int size =1;

    chaines[0] = '\0';

    printf("bingogo:%s\n",chaines);

    while( (chaine = fgets(chaine,alire+1,file)) != NULL){
      
      int p = atoi(chaine);

      //printf("chaine  %s\n",chaine);

      //printf("v: %s taille %d\n",chaine,strlen(chaine));

      if( p == 0)
	continue;

      if(p<pivot && strlen(chaine) == alire){
	strcpy(chaineDer,chaine);
	printf("chaine choisie %s\n",chaineDer);
	lus++;

	size+= alire;
	chaines = realloc(chaines,size*(sizeof(char)));
	strcat(chaines,chaine);
      }
      
    }

    if(lus == 0){
      printf("lecture non faite\n");
      return 0;
    }

    printf("lus: %d derniers caracteres lus: %s\n",lus,chaineDer);
    printf("%s\n",chaines);
  }

  return 0;
}

int vmain(){

  int *tab_entier = malloc(sizeof (int));
  char* v;
  int size = 0;
  
  
  while(1){
    printf("entrez un entier %d :",size);
    scanf("%s",v);

    int e;

    if(strcmp(v,"quit") == 0){
      printf("Quit\n");
      break;
    }

    if( (e = atoi(v)) != 0){
      tab_entier = realloc(tab_entier, (++size)*(sizeof (int)) );
      tab_entier[size-1] = e;
    }
    
  }

  return 0;
}
