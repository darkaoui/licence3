#include <stdio.h>
#include <time.h>
#include <stdlib.h>

typedef struct date{
  int jour;
  int mois;
  int an;
} date;


int dateCompare(date d1, date d2){
  if(d1.jour == d2.jour && d1.mois == d2.mois && d1.an == d2.an)
    return 0;
  else
    return
      -1;
}


date demain(date d){
    
}

int main(){
  
}
