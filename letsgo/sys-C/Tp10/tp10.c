#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <time.h>
#include <sys/types.h>
#include <string.h>

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
 printf("player number>");
 scanf("%d",&nb_player);

 if(nb_player == 1){
   fdOther = open("/tmp/usr2",O_WRONLY);
 }else if(nb_player == 2){
   printf("ouverture 2\n");
   fdGamer = open("/tmp/usr2",O_RDONLY);
   
 }else
   return -1;


 int a,b;
 
 char msg[10];
 int size =10;
   
 if(nb_player == 1){  
  
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
     printf("Donner une valeur [1-%d]>",b);
     scanf("%d",&c);
     a = a-c;

     printf("Vous avez jouer(reste,choix) %d : %d\n",a<=0?0:a,c);
     sprintf(msg,"%d %d",a,c);
     write(fdOther,msg,size);
     sleep(2);
     
   }
   
 }else{

   read(fdGamer,msg,size);
   sscanf(msg,"%d %d",&a,&b);
   
   fdOther = open("/tmp/usr1",O_WRONLY);

   printf("Le panier initial: %d\n",a);
   
   while(1){
     //fscanf(fdGamer,"%d %d",&a,&b);
     //applique la regle de jeu
     int c;
     printf("Donner une valeur [1-%d]>",b);
     scanf("%d",&c);
     a = a-c;

     printf("Vous avez jouer(reste,choix) %d : %d\n",a<=0?0:a,c);
     sprintf(msg,"%d %d",a,c);
     write(fdOther,msg,size);

     read(fdGamer,msg,size);
     sscanf (msg,"%d %d",&a, &c);
     
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
     sleep(2);
   }
   
 }
 
}
