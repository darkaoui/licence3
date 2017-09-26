#include <stdio.h>

 void affiche(int a ,int b ,int c , int *p1, int *p2){
   printf("a=%d  b=%d  c=%d  p1=%p  *p1=%d  p2=%p *p2=%d\n", a,b,c,p1,*p1,p2,*p2);
 }

int main(){
  int a=1, b=2, c=3;
  int *p1,*p2;

  p1= &a;
  p2 = &c;

  printf("1 "); affiche(a,b,c,p1,p2);

  *p1 = (*p2)++;
  printf("2 "); affiche(a,b,c,p1,p2);

  p1=p2;
  printf("3 "); affiche(a,b,c,p1,p2);

  p2 = &b;
  printf("4 "); affiche(a,b,c,p1,p2);

  *p1 -= *p2;
  printf("5 "); affiche(a,b,c,p1,p2);

  ++*p2;
  printf("6 "); affiche(a,b,c,p1,p2);

  a = ++*p2 * *p1;
  printf("7 "); affiche(a,b,c,p1,p2);

  p1=&a;
  printf("8 "); affiche(a,b,c,p1,p2);

  *p2 = *p1/=*p2;
  printf("9 "); affiche(a,b,c,p1,p2);
}

