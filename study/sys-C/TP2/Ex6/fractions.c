#include "fractions.h"

void affiche_fraction(fraction f){
  printf("%d/%d ~ (%f)\n",f.numerateur,f.denominateur,to_float(f));
}

//on supposera que a<b
unsigned int pgcd(unsigned int a, unsigned int b){
  int r = a%b;
  if(r == 0)
    return b;
  else
    return pgcd(b,r);
}

fraction reduit(fraction f){
  int a,b;
  a = f.numerateur;
  b = f.denominateur;

  if(b == 0 && a == 0)
    return f;

  if(b == 0 && a>0){
    f.numerateur =1;
    return f;
  }

  if(b == 0 && a<0){
    f.numerateur =-1;
    return f;
  }

  if(a == b){
    f.numerateur    =1;
    f.denominateur =1;
    return f;
  }

  int pg;
  
  if(a<b)
    pg =  pgcd(b,a);
  else
    pg =  pgcd(a,b);

  f.numerateur   = f.numerateur/pg;
  f.denominateur = f.denominateur/pg;

  return f;
}

fraction add_frac(fraction f1, fraction f2){
  fraction f;
  f.numerateur   = f1.numerateur*f2.denominateur + f1.denominateur*f2.numerateur;
  f.denominateur = f1.denominateur*f2.denominateur;

  return reduit(f);
}

fraction sub_frac(fraction f1, fraction f2){
  fraction f;
  f.numerateur   = f1.numerateur*f2.denominateur - f1.denominateur*f2.numerateur;
  f.denominateur = f1.denominateur*f2.denominateur;

  return reduit(f);
}

fraction div_frac(fraction f1, fraction f2){
  fraction f;
  f.numerateur   = f1.numerateur*f2.denominateur;
  f.denominateur = f1.denominateur*f2.numerateur;

  return reduit(f);
}

unsigned int  frac_eq(fraction f1, fraction f2){
  f1 = reduit(f1);
  f2 = reduit(f2);

  if(f1.numerateur == f2.numerateur && f1.denominateur == f2.denominateur)
    return 1;
  else
    return -1;
}

float to_float(fraction f){
  return (float)f.numerateur/f.denominateur;
}

fraction of_int(unsigned int i){
  fraction f;
  f.numerateur   = i;
  f.denominateur = 1;

  return f;
}

//Question sur affichage des fractions
