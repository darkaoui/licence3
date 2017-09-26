#include <stdio.h>
#include <string.h>
#include "tp6_ex1.h"

#ifdef VERSION
#undef VERSION
#define VERSION 1
#endif

#define then
#define begin {
#define end ;}

#define JOIN(a,n) a##n

#define MULT(a,b) ((a)*(b))

char valPrint(char* s){
  if(strcmp(s,"int") == 0)
    return 'd';
  else
    return 's';
}

#define PRINT(type,variable) if(strcmp(#type,"int") == 0)\
    printf("%d",variable);\
  else if(strcmp(#type,"string") == 0)\
    printf("%s",variable);

#define VAL 9

int main(){

  char* a1 = "premier";
  char* a2 = "deuxieme";

  printf("%s\n",JOIN(a,1));
  printf("%s\n",JOIN(a,2));
  
  printf("version %d\n",VERSION);
  printf("fichier courant :%s\n",__FILE__);

  int i=0, a,b;
  if(i>0) then
	 begin
	    a=0;
             b=1
	 end
  printf("Bien jouer\n");
	     printf("Result: %d\n",MULT(2+3,1));
	     PRINT(int,i);
}
