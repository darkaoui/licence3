#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char* argv[]){

  char* tab[3];

  tab[1] = "-l";
  tab[2] = "-w";
  tab[3] = "-c";

  int nbmots=0;
  int nbline=0;
  int lastspace = 0;
  int nbchar=0;
  char c;
  
  while(c != EOF){
    
    c = getchar();
    ++nbchar;
    
    if(isspace(c) || c == EOF){
      if(lastspace == 0)
	++nbmots;
      if(c == '\n' || (lastspace ==0 && c == EOF))
	++nbline;
    }

    if(isspace(c)){
      lastspace = 1;
    }else
      lastspace =0;
    
    //printf("%c\n",c);
    
  }

  //printf("ligne: %d mots:%d", nbline, nbmots);
  //printf("\nTerminer\n");

  if(argc <= 1){
    printf("%d  %d  %d",nbchar, nbmots, nbline); printf("\n");
  }else{
    
    for(int i=1; i<argc; i++){

      //printf("chaine %s",argv[i]);

      if(strcmp("-c", argv[i]) == 0)
	printf("%d  ",nbchar);

      if(strcmp("-w", argv[i]) == 0)
	printf("%d  ",nbmots);

      if(strcmp("-l",argv[i]) == 0)
	printf("%d  ",nbline);
    }
    
  }

  printf("\n");
  
  return 0;
}
