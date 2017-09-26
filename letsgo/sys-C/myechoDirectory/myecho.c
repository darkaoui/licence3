#include <stdio.h>
#include "strlib.h"

int main(int argc, char* argv[]){

  if(argc == 1){
    printf("\n");
    return 1;
  }

  char space = '\0';
  char fin   = '\0';

  if(argc > 3){
    
    if( streq(argv[1],"-s") || streq(argv[2],"-s") )
      space = ' ';
    else if( streq(argv[1], "-n") || streq(argv[2],"-n") )
      fin = '\n';
    
  }else{
    printf("\n");
    return 1;
  }
    for(int i=1; i<argc; i++){
      printf("%s",argv[i]);
      if((i+1) < argc)
	printf("%c", space);
    }
    printf("%c",fin);
}
