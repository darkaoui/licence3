#include <stdio.h>

void bonjour2(int i){
  printf("Bonjour l'utilisateur %d\n",i);
}

int main(){
  int id = 0;
  printf("Donner votre id :");
  scanf("%d",&id);
  bonjour2(id);
}
