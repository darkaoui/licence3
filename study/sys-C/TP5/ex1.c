#include <stdio.h>
#include <stdlib.h>

#define affiche_nbr(a) printf("%p (%lx)\n", a, (unsigned long)a)

//Question 3
void f1(int* p){
  printf("******* f1 *********\n");
  int  v =7;
  char c ='A';

  printf("address contenu de p: %p\n",*p);
  printf("valeur de p: %p\n",p);
  printf("address de p: %p\n",&p);

  printf("address et contenu de v: (%p,%d)\n",&v,v);
  printf("address et contenu de c: (%p,%c)\n",&c,v);

  *p =8;
  p=NULL;
}

//Question 5
void f2(int* p){

  printf("******* f2 *******\n");
  int v1;
  int v2;

  printf("address parametre p: %p\n",&p);
  printf("address v1 et v2: (%p,%p)\n",&v1,&v2);
  printf("contenu de v1 et v2\n",v1,v2);
  
}

char global1;
char global2;

char *pglobal1;
char *pglobal2;

int main(){

  char localchar1;
  char localchar2;

  int localint1;
  int localint2;

  int* plocalint1;
  int* plocalint2;

  printf("char global\n");
  affiche_nbr(&global1);
  affiche_nbr(&global2);

  printf("\np char global\n");
  affiche_nbr(pglobal1);
  affiche_nbr(pglobal2);

  printf("\nlocal int\n");
  affiche_nbr(&localint1);
  affiche_nbr(&localint2);

  printf("\np local int\n");
  affiche_nbr(plocalint1);
  affiche_nbr(plocalint2);


  //Question 2
  printf("int=%d char=%d int*=%d\n",sizeof(int),sizeof(char),sizeof(int*));

  //Question 4
  plocalint1 = &localint1;
  f1(plocalint1);
  printf("address et valeur de plocalint1: (%p,%p)\n",&plocalint1,plocalint1);
  printf("la valeur de localint1: %d\n",localint1);

  //Question 5
  //Question 4
  f2(plocalint1);
  printf("address et valeur de plocalint1: (%p,%p)\n",&plocalint1,plocalint1);
  printf("la valeur de localint1: %d\n",localint1);
  
}
