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
  else if(d1.an < d2.an)
    return -1;
  else if(d1.an == d2.an &&  d1.mois < d2.mois)
    return -1;
  else if(d1.an == d2.an && d1.mois == d2.mois && d1.jour<d2.jour)
    return -1;
  else
    return 1;
}

int bissextile(date d){
  if((d.an%4 == 0 && d.an%100 != 0) || d.an%400 == 0)
    return 0;
  else
    return -1;
}


date demain(date d){

  int j=d.jour;
  int m=d.mois;
  int a=d.an;

  j++;

  if(j == 29 && bissextile(d) != 0 && m == 2){
    d.jour = 1;
    d.mois = m+1;
  }else if(j == 30 && bissextile(d) == 0 && d.mois == 2){
    d.jour = 1;
    d.mois = m+1;
  }else if(j == 31 && (m==4 || m==6 || m == 9 || m == 11) ){
    d.jour =1;
    d.mois = m+1;
  }else if(j == 32 && (m == 7 || m == 8 || m == 10) ){
    d.jour = 1;
    d.mois = m+1;
  }

  if(m == 13){
    d.mois = 1;
    d.an   = a+1;
  }

  return d;
}

int main(){
  date d = {28,02,2014};

  d = demain(d);
  
  printf("%d %d %d\n",d.jour,d.mois,d.an);

  date d0 = {27,02,2014};
  date d1 = {28,03,2014};

  printf("compare %d\n",dateCompare(d0,d));
  printf("compare %d\n",dateCompare(d1,d));
}
