#include <stdlib.h>
#include <time.h>

int jouer(int limit,int coups){
  srand(time(NULL));
  return (rand()%coups)+1;
}
