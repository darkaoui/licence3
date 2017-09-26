#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
  char* nom;
  char* prenom;
  char  num[10];
} ETUDIANT;

void affiche(ETUDIANT e){
  printf("%s\n", e.nom);
  printf("%s\n", e.prenom);
  printf("%s\n\n", e.num);
}

ETUDIANT* lecture(ETUDIANT *e){

  //printf("Bonjour");
  
  int i=0;
  char c;
  char len[50];

  char* chain[3];

  do{
    
    int j = 0;
    while((c = getchar()) != '\n'){
      if(c == EOF){
	return NULL;
      }
      *(len+(j++)) = c;
    };
    *(len+j) = '\0';

    //Recupere la chaine
    char *chaine = malloc(strlen(len)+1);
    for(int t=0; t<strlen(len);t++)
      *(chaine+t) = len[t];

    *(chaine+(strlen(len))) = '\0';
    //printf("chaine -> %s ; taille-> %d\n",chaine,strlen(len));

    chain[i] = chaine;
   
    ++i;
  }while(i <3);

  //free(e->nom);
  //free(e->prenom);
  
  //e->nom    = chain[0];
  //e->prenom = chain[1];

  //printf("Recuperation 1\n");
  //printf("%s\n",chain[0]);
  e->nom= chain[0];
  e->prenom= chain[1];

  //printf("Recuperation 2\n");

  //printf("Coude\n");
  for(int i=0;i<10;i++){
    e->num[i] = (chain[2][i]); //fuite de memoire apres
  }

  e->num[10] = '\0';

  //printf("A bientot");

  return e;
}

int main(int argc, char* argv[]){


  //ETUDIANT liste[100];
  ETUDIANT *etudiants = malloc(sizeof(ETUDIANT));


  if(etudiants == NULL)
    return 1;
  
  int stop = 0;
  int nb=0;

  
  do{
    
    if(lecture(etudiants+nb) != NULL){
      nb+=1;
      etudiants =  realloc(etudiants, (nb+1)*sizeof(ETUDIANT)); 
      if(etudiants == NULL)
	break;
      
    }else{

      //nb-=1;
      stop =1;
      etudiants = realloc(etudiants, nb*sizeof(ETUDIANT)); 
      if( etudiants == NULL)
	break;
      
    }
    
  }while(stop == 0);

  

  if(argc >= 2){

    if(strcmp(argv[1],"-r") == 0){

       for(int i=0; i<nb; i++){
	 if(strstr((etudiants+i)->nom,argv[2]) != NULL || strstr((etudiants+i)->prenom, argv[2]) != NULL)
	   affiche(*(etudiants+i));
       }
       printf("Rechercher\n");
       
    }else{
	
       for(int i=0; i<nb; i++)
	 affiche(*(etudiants+i));
       
       printf("Tout le monde\n");
       
    }
    
  }else{
    
    for(int i=0; i<nb; i++)
      affiche(*(etudiants+i));
    
    printf("Tout le monde\n");
    
  }
  
     
  /*
    premiere lecture

  //lecture
  for(int i=0; i<100; i++){
    lecture(&liste[i]);
  }

  if(argc >= 2){
    
    if(strcmp(argv[1],"-r") == 0){
      for(int i=0; i<100; i++){
	if(strstr(liste[i].nom, argv[2]) != NULL || strstr(liste[i].nom,argv[2]) != NULL)
	  affiche(liste[i]);
	
      }
      printf("Recherche\n");
    
    }else{
      for(int i=0; i<100; i++){
	affiche(liste[i]);
      }
      printf("Tout le monde\n");
    }
  }else{
    
    for(int i=0; i<100; i++){
	affiche(liste[i]);
      }
      printf("Tout le monde\n");
  }

  */
  
  printf("Bien Terminer Etudiant\n");
}
