#include <stdio.h>
#include <string.h>

const int LIGNE_MAX = 30;

int grep(char* str, FILE* file, FILE* file2){

  char c;
  char chaine[LIGNE_MAX+1];
  int i=0;
  
  while((c=fgetc(file)) != EOF){
    
    if(i<LIGNE_MAX && c!='\n'){
      chaine[i] = c;
      ++i;
    }else{

      chaine[i] = '\0';
      
      if(strstr(chaine,str)){
	printf("bingo: %s\n",chaine);
	int j=0;

	do{
	  fputc(chaine[j],file2);
	  ++j;
	}while(chaine[j] != '\0');
	fputc('\n',file2);
      }
      
      i=0;
      
    }
  }

  return 0;
}

int main(){

  char *chaine = "bine ddlf d d";
  
  FILE *file  = fopen("fichier6src","r");
  FILE *file2 = fopen("fichier6des","a");

  if (file == NULL || file2 == NULL)
    perror("Erreur d'ouverture du fichier\n");

  grep("moyo",file,file2);

  if(file != NULL)
    fclose(file);

  if(file != NULL)
    fclose(file2);
  
  return 0;
}
