#include <stdio.h>

int found(char c){
  switch(c){
  case '+':
  case '-':
  case '*':
  case '%':
  case '/':
    return 1;
  default:
      return 0;
  }
}

int main(){
  int a,b;
  char c;
    
  if(scanf("%d",&a) == EOF){
    printf("Erreur d'entier\n");
    return -1;
  }
  while(1){
    while(1){
      if(found(c=getchar()) == 1)
	break;
      if(c != ' ' && c != '\n'){
	printf("Erreur d'operateur<%c>\n",c);
	return -1;
      }
    }
    if(scanf("%d",&b) == EOF){
      printf("Erreur d'entier\n");
      return -1;
    }
    switch(c){
    case '+': a=a+b;
      break;
    case '-': a=a-b;
      break;
    case '*' : a=a*b;
      break;
    case '%': a=a%b;
      break;
    case '/': a=a/b;
      break;
    default:
      printf("Erreur operateur\n");
      return -1;
    }
    printf("%d",a);
  }
}
  
