#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]){
  if(argc < 3)
    return -1;

  FILE *fd = fopen(argv[2], "rb");

  if(fd == NULL){
    printf("Erreur d'ouverture de fichier\n");
    return -2;
  }

  char* memoire = malloc(sizeof(char));
  int size_mem  = 1;

  char oct;
  int taille = strlen(argv[1]);

  for(int i=0;i<taille;i++){
    
    int jsec1=0;
    int jsec2=0;
    
    while(fread(&oct,sizeof(oct),1,fd) == 1){

      //on a la valeur oct
      if(jsec1 == i+jsec2*taille){
	char crypt = oct^argv[1][i];
	memoire[size_mem-1] = crypt;	
	memoire = realloc(memoire,++size_mem);
	jsec2++;
      }

      jsec1++;
    }
  }

  memoire[size_mem-1] = '\n';
  printf("string:%s\n\n",memoire);

  printf("script out:\n");
  for(int i=0; i<size_mem; i++){
    printf("%d ",memoire[i]);
  }

  printf("\n");
}
