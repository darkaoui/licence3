#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <time.h>
#include <sys/types.h>


int main(){

  
 FILE *fdGamer;
 FILE *fdOther;

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

 int nb_player =1;
 printf("player number>");
 //scanf("%d",&nb_player);
 printf("olala");
 

 if(nb_player == 1){
   fdGamer = fopen("/tmp/usr1","r");
   fdOther = fopen("/tmp/usr2","w");
 }

 if(nb_player == 2){
   fdGamer = fopen("/tmp/usr2","r");
   fdOther = fopen("/tmp/usr1","w");
 }

 int a,b;



 srand(time(NULL));

 if(nb_player == 1){  
  
   a = 10+(rand()%91);
   b = 2 +(rand()%7);

   printf("random initialisation...\n");

   fprintf(fdOther,"%d %d",a,b);
   while(1){
     
     int c;
     fscanf (fdGamer,"%d %d",&a, &c);
     printf("Votre adversaire a choisi %d et il reste %d",&c,&a);

     //applique la regle de jeu
     if(a == -1000){
       printf("Vous avez gagner");
       break;
     }

     if(a <= 0){
       printf("Vous avez perdu");
       fprintf(fdOther,"%d",-1000);
       break;
     }

     printf("Donner une valeur [1-%d]>",b);
     scanf("%d",&c);
     a = a-c;

     printf("Vous avez jouer(reste,choix) %d : %d",a,c);
     fprintf(fdOther,"%d %d",a,c);
     sleep(2);
     
   }
   
 }else{

   printf("entree du joueur ....");
   fscanf(fdGamer,"%d %d",&a,&b);
   
   while(1){
     //fscanf(fdGamer,"%d %d",&a,&b);

     //applique la regle de jeu
     int c;
     printf("Donner une valeur [1-%d]>",b);
     scanf("%d",&c);
     a = a-c;

     printf("Vous avez jouer(reste,choix) %d : %d",a,c);
     fprintf(fdOther,"%d %d",a,c);
     
     fscanf (fdGamer,"%d %d",&a, &c);
     printf("Votre adversaire a choisi %d et il reste %d",&c,&a);
     
     if(a == -1000){
       fprintf(fdOther,"Vous avez gagner");
       break;
     }

     if(a <= 0){
       printf("Vous avez perdu");
       fprintf(fdOther,"%d",-1000);
       break;
     }
    
     sleep(2);
   }
   
 }
 
}
