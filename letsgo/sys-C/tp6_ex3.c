#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void copy(FILE *file, FILE *image){
  char c ;

  int lineTotal =0;

  while((c=fgetc(file)) != EOF){
    if(c == '\n')
      lineTotal++;
  }

  rewind(file);

  char v[10];
  sprintf(v,"%d",lineTotal); //conversion de la chiffre
  lineTotal = strlen(v);
  
  //printf("longueur des chiffres: %d\n",strlen(v));

  //fprintf(image,"%*d ",lineTotal,1);

  int line =0;
  
  while((c=fgetc(file)) != EOF){
    if(c == '\n'){
      fputc('\n',image);
      fprintf(image,"%*d ",lineTotal,(++line));
    }else
      fputc(c,image);
  }

  fputc('\n',image);
}

void copy2(FILE *file, FILE *image){
  char c ;

  int lineTotal =0;

  while((c=fgetc(file)) != EOF){
    if(c == '\n')
      lineTotal++;
  }

  rewind(file);

  char v[10];
  sprintf(v,"%d",lineTotal); //conversion de la chiffre
  lineTotal = strlen(v);
  
  //fprintf(image,"%*d ",lineTotal,1);

  int line =0;
  int pos  =0;

  char s[4];
  int retour =0;
  int posretour=(-1);

  while(1){

    pos = ftell(file);

    fgets(s,4,file);

    if(strcmp(s,"||:") == 0){
      posretour = pos;
    }

    if(strcmp(s,":||") == 0){

      if(retour == 0){
	fseek(file,posretour,SEEK_SET);
	
	fprintf(image,":||\n");
	fprintf(image,"%*d ",lineTotal,(++line));

	retour = 1;
      }else{
	retour = 0;
	fseek(file,pos,SEEK_SET);
      }	
      
    }else
      fseek(file,pos,SEEK_SET);

    if((c=fgetc(file)) == EOF)
      break;
    
    if(c == '\n'){
      fputc('\n',image);
      fprintf(image,"%*d ",lineTotal,(++line));
    }else
      fputc(c,image);
  }

  fputc('\n',image);
    
}

int main(int argc, char* argv[]){

  char *f1;
  char *f2;

  FILE* file;
  FILE* image;
  
  if(argc == 3){
    
    f1 = argv[1];
    f2 = argv[2];

    file  = fopen(f1,"r");
    image = fopen(f2,"w");

  }else if(argc == 2){

    f1 = argv[1];
    file  = fopen(f1,"r");
    image = stdout;
    
  }else{
    
    fprintf(stderr,"erreur d'argument\n");
    return 1;
  }

  copy2(file,image);

  printf("bingo bingo\n");

  return 0;
}
