#include "fractions.h"

fraction heron(int a, int n){
  int u0 = 1;
  fraction fUn= of_int(u0);
  fraction fA = of_int(a);
  fraction f2 = of_int(2);
  
  while(n >=0){
    
    fUn = reduit( div_frac( add_frac(fUn,div_frac(fA,fUn)), f2) );
    
    printf("heron %d>",n);
    affiche_fraction(fUn);

    n--;
  }

  return fUn;
}


//Question sur le debordement
