#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

char* mot_passe_simple(int taille){
  if(taille <1){
    fprintf(stderr,"Erreur, la taille est invalide\n");
  }

  char* s = (char*)malloc((taille+1)*sizeof(char));

  int cinf= '!', csup= '~'+1;
  for(int i=0; i<taille; i++){
    *(s+i) = cinf+rand()%(csup-cinf);
  }
  *(s+taille) = '\0';

  return s;
}

char* mot_passe_renforce(int taille){
  if(taille<4){
    fprintf(stderr,"Erreur,impossible d'avoir un mot de passe renforce pour cette longueur, renvoie d'un mot de passe simple!\n");
    return mot_passe_simple(taille);
  }

  char* chr = calloc(taille+1, sizeof(*chr));
  char* pchr;

  for(int i=0; i<taille; i++){
    do{
      pchr = chr+rand()%taille; //printf("%p\n",chr+rand()%taille);
    }while(*pchr != 0);

    

    if(i ==0)
      *pchr ='0' + rand()%('9'-'0'+1);
    else if(i == 1)
      *pchr = 'a' + rand()%('z'-'a'+1);
    else if(i ==2)
      *pchr = 'A' + rand()%('Z'-'A'+1);
    else if(i == 3){
      do{
	*pchr = '!' + rand()%('~'-'!'+1);
      }while(isalnum(*pchr));
    }else{
      *pchr = '!' + rand()%('~'-'!'+1);
    }
  }

  pchr = chr+taille;
  *pchr = '\0';

  return chr;
  
}

int main(){
  srand(time(NULL));

  char* simple, *renf1, *renf2, *renf3;
  simple = mot_passe_simple(8);
  renf1  = mot_passe_renforce(3);
  renf2  = mot_passe_renforce(8);
  renf3  = mot_passe_renforce(4);

  printf("Simple 8 carac:\n%s\n",simple);
  printf("Renforce 3 carac\n%s\n",renf1);
  printf("Renforce 8 carac\n%s\n",renf2);
  printf("Renforce 4 carac\n%s\n",renf3);

  char* ptr = simple+10;
  printf("Carac: %c",*ptr);

  free(simple);
  free(renf1);
  free(renf2);
  free(renf3);

  return EXIT_SUCCESS;
}
