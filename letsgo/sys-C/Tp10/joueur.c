#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <time.h>
#include <sys/types.h>
#include <string.h>

int jouer(int limit,int coups);

int main(){

  srand(time(NULL));
  int fdGamer;
  int fdOther;

  if(access("/tmp/usr1",F_OK) == 0){
    printf("fichier existe 1\n");
  }else{
    //on cree le fichier
    mkfifo("/tmp/usr1", S_IRUSR| S_IWUSR);
  }

 if(access("/tmp/usr2", F_OK) == 0){
    printf("fichier existe 2\n");
 }else{
   //on cree le fichier
   mkfifo("/tmp/usr2", S_IRUSR| S_IWUSR);
 }

 printf("DEBUTER LE JEU\n");

 int nb_player =1;

 fdOther = open("/tmp/usr2",O_WRONLY);

 int a,b;
 
 char msg[10];
 int size =10;
   
 a = 10+(rand()%91);
 b = 2 +(rand()%7);

 printf("random initialised\n");

 printf("Le panier initial: %d\n",a);

 sprintf(msg,"%d %d",a,b);
 write(fdOther,msg,size);

 fdGamer = open("/tmp/usr1",O_RDONLY);
   
 while(1){
     
   int c;
   read(fdGamer,msg,size);
   sscanf (msg,"%d %d",&a, &c);
     
   //applique la regle de jeu
   if(a == 1000 && c == 1000){
     printf("Vous avez gagner\n");
     remove("/tmp/usr1");
     remove("/tmp/usr2");
     break;
   }

   if(a <= 0){
     printf("Vous avez perdu\n");
     char *s = "1000 1000";
     write(fdOther,s,strlen(s));
     break;
   }

   printf("Votre adversaire a choisi %d et il reste %d\n",c,a);
   //scanf("%d",&c);
   c = jouer(a,b);
   a = a-c;

   printf("Vous avez jouer(reste,choix) %d : %d\n",a<=0?0:a,c);
   sprintf(msg,"%d %d",a,c);
   write(fdOther,msg,size);
   sleep(2);
     
 }

 sleep(2);
 
}
