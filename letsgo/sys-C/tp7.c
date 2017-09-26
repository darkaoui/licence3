#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(){

  printf("start...\n");

  //printf("%+10d%+10d\n",234,22);

  //int c;
  FILE *file   = fopen("lipsum.txt","r");
  FILE *filew  = fopen("tp7.txt","w");
  FILE *fileb1  = fopen("lipsum_b1.txt","w");
  FILE *fileb2  = fopen("lipsum_b2.txt","w");

  double tabresult[2][5];
  int it = 1;
  int itab = 0;
  do{
    char buf[it];
    double m =0;
    for(int i=0; i<100; i++){
      clock_t deb  = clock();
      while(fread(buf,it,1,file) != 0)
	fwrite(buf,it,1,fileb1);
      clock_t fin = clock();
      m+= (double)(fin-deb)/CLOCKS_PER_SEC;
    }
    tabresult[0][itab] = m/100;
    //fprintf(filew,"%-10d%f\n",it,m/100);
    itab++;
    it*=10;
  }while(it != 100000);

  it =1;
  itab =0;
  fseek(file,0,SEEK_SET);
  do{

    char buf;
    double m =0;
    for(int i=0; i<100; i++){
      clock_t deb  = clock();
      while(fread(&buf,sizeof(buf),1,file) != 0)
	fputc(buf,fileb2);
      clock_t fin = clock();
      m+= (double)(fin-deb)/CLOCKS_PER_SEC;
    }

    //fprintf(filew,"%-10d%f\n",it,m/100);
    tabresult[1][itab] = m/100;
    itab++;

    it*=10;
  }while(it != 100000);

  int dd =1;
  for(int i=0; i<5;i++){
    fprintf(filew,"%-10d%-10f%f\n",dd,tabresult[0][i],tabresult[1][i]);
    dd*=10;
  }
  
  //fprintf("%f\n",(double)(fin-deb)/CLOCKS_PER_SEC);

  /*
  double m =0;
  char c;
  for(int i=0;i<1000;i++){
    clock_t deb = clock();

    while((c = fgetc(file)) != EOF)
      fputc(c,files);
  
    clock_t fin = clock();
    m+= (double)(fin-deb)/CLOCKS_PER_SEC;
  }
  
  printf("%f\n",m/100);

  */

  /*
  double m = 0;

  printf("start...\n");
  for(int i=0; i<100;i++){
  clock_t deb = clock();

  for(int i=0; i< nbEchantillon; i++)
    continue;
    
  clock_t fin = clock();
  }
  
  printf("%f\n",(double)(fin-deb)/CLOCKS_PER_SEC);
  */
  
}
