#include <stdio.h>

enum VAL {
    PLUS_INFINI,MOINS_INFINI, ERREUR
};

union VAL1{
  int v0;
  enum VAL v1;
};

typedef struct super_int{
  int indice;
  union VAL1 val;
} super_int;

int division(int a, int b){

  union VAL1 v;
  
  if(b == 0){
    if(a>0)
      return v.v1 = PLUS_INFINI;
    if(a<0)
      return v.v1 = MOINS_INFINI;
    return v.v1 = ERREUR;
  }else
    return v.v0 = a/b;
}

super_int addition(super_int a, super_int b){

  if(a.indice == 1 && b.indice == 0){
    return a;
  }

  if(b.indice == 1 && b.indice == 0){
    return b;
  }

  if(b.indice == 1 && b.indice == 1)
  {
    super_int v;
    if(b.val.v1 == ERREUR || b.val.v1 == ERREUR){
      v.indice = 1;
      v.val.v1 = ERREUR;
      return v;
    }
  }

  super_int v;
  v.indice =0;
  v.val.v0 = a.val.v0 + b.val.v0;
  
  return v;
}

int main(){

  super_int v1,v2,v3;

  v1.indice = 0;
  v1.val.v0 = 1;

  v2.indice = 0;
  v2.val.v0 = 1;

  //v3.indice = 0;
  //v3.val.v0 = 2;

  v3 = addition(v1,v2);
  
  printf("%d\n", division(0,0));
  printf("%d\n", v3.val.v0);

  if(v3.val.v0 == ERREUR)
    printf("Attention");

  return 0;
}
