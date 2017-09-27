#include <stdio.h>

int identification(){
  int id = 0;
  printf("Donner votre id :");
  scanf("%d",&id);
  return id;
}

void bonjour2(int i){
  printf("Bonjour l'utilisateur %d\n",i);
}

int main(){
  bonjour2(identification());
}
