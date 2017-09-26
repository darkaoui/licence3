#include <stdlib.h>
#include <time.h>


//limit -> le nombre d'objet restants
//coups -> le nbre d'elements par coups limites

int jouer(int limit,int coups){
  srand(time(NULL));
  return (rand()%coups)+1;
}
