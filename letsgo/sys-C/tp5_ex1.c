#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

char c1;
char c2;

int i1;
int i2;

int* pi1;
int* pi2;

void f1(int *p){
  static int n =9;
  int i  = 7;
  char c = 'A';

  printf(" -> fonction 1\n");
  
  printf("adress pointee %p\n", &(*p));
  printf("param %d %p\n", *p, &p);

  printf("entier %d %p\n", i, &i);
  printf("caract %d %p\n", c, &c);

  printf("static %d %p\n", n, &n);

  *p = 0;
  p=NULL;

  n++;
  printf("static %p n=%d\n",&n, n);
  
  printf(" -> fonction 2\n");
}

void f2(int* p){
  int v1;
  int v2;

  f1(&v1);

  printf("%p %p %p\n", &p, &v1, &v2);
  printf("%d %d %d\n", *p, v1, v2);
}



int main(){


  char mc1;
  char mc2;

  int mi1 = 2;
  int mi2;

  int* mpi1;
  int* mpi2;

  printf("%p\n", &c1);
  printf("%p\n", &c2);
  printf("%p\n", &i1);
  printf("%p\n", &i2);
  printf("%p\n", pi1);
  printf("%p\n", pi2);

  printf("%p\n", &mc1);
  printf("%p\n", &mc2);
  printf("%p\n", &mi1);
  printf("%p\n", &mi2);
  printf("%p\n", mpi1);
  printf("%p\n", mpi2);

  printf("%d %d %d\n", sizeof(char), sizeof(int), sizeof(int*));

  printf("%d %d %d\n", sizeof(c1), sizeof(i1), sizeof(pi1));

  printf("%d %d %d\n", sizeof(mc1), sizeof(mi1), sizeof(mpi1));

  mpi1 = &mi1;
  f1(mpi1);

  printf("apres appel\n");
  printf("%d %p %d\n", *mpi1, mpi1, mi1);
  printf("Apel f2\n");
  f2(mpi1);
}
