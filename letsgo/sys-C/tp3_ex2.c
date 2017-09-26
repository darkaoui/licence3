#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rand_(int a, int b){
  return rand()%(b-a+1)+a;
}

char* genere(unsigned int l){
  char* chaine  = malloc((l+1)*sizeof(char));
  
  //srand(time(NULL));

  for(unsigned int i=0; i<l-1; i++){
    int r = rand_(33,127); //printf("%d\n",r);
    char c = (char)(r);
    chaine[i] = c;
  }

  chaine[l] ='\0';

  return chaine;
}

char* genere2(unsigned int l){

  if(l<4){
    printf("la longueur n'est pas respectee\n");
    return NULL;
  }
  
  char* ch;

  ch = genere(l);

  int crit[4] ={0,0,0,0};
  
  while(crit[0] == 0 || crit[1] == 0 || crit[2] == 0 || crit[3] == 0){

    ch = genere(l);
    for(int i=0; i< l-1; i++){
      if(crit[0] == 1 && crit[1] == 1 && crit[2] == 1 && crit[3] == 1)
	return ch;

      //verification des minuscules
      if(ch[i] >= 97 && ch[i] <=122)
	crit[0] = 1;

      //verification des majuscules
      else if(ch[i] >= 65 && ch[i] <= 96)
	crit[1] = 1;

      //verification des chifres
      else if(ch[i] >= 48 && ch[i]<=57)
	crit[2] = 1;

      //caracteres speciales
      else
	crit[3] = 1;
    }

    free(ch);
    crit[0]=0;
    crit[1]=0;
    crit[2]=0;
    crit[3]=0;
  }

  return ch;
}

int main(){

  srand(time(NULL));

  printf("val1: %s\n",genere(20));
  printf("val2: %s\n",genere2(4));

  return 0;
}
