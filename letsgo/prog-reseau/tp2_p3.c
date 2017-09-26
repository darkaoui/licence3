#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

void show_mem_rep(char* start, int n){
  for(int i=0; i<n; i++){
    printf("  %.2x", start[i]);
  }
  printf("\n");
}

int devine(char* mot){
  char c;

  int size = strlen(mot);
  int len = size;
  int szi =0;

  char* tmp = malloc(size*sizeof(char));
  strcpy(tmp,mot);

  while(1){

    system("stty raw");
    system("stty -echo");
    c= getc(stdin);
    system("stty echo");
    system("stty cooked");
    
    szi++;

    if(c == '.'){
      return 0;
    }

    int sonde = len;
    for(int i=0; i<size; i++){
      if(*(tmp+i) == c){
        len--;
	*(tmp+i) = 0;
	break;
      }
    }

    if(sonde != len){
      printf("\n%c",c);
    }

    if(len == 0)
      return szi;  
  }
}

int main(){

  int i = 0x01234567;

  printf("Le n %d\n %d",i,sizeof(int));

  show_mem_rep((char*)&i, sizeof(int));

  printf("Jouer\n");
  int coups = devine("bonjour");
  if(coups != 0)
    printf("\ngagne en %d coups!\n",coups);
  else
    printf("\nPerdu!\n");
}
