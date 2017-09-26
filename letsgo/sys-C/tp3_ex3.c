#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void lecture(){
  char c ;

  do{
    c= getchar();
    printf("%c",c);
  }while(c != EOF);
}

unsigned char* negatif(unsigned char* pixel_orig, int taille, int n){
  unsigned char* pixel_nega = (unsigned char*)malloc(taille);
  for(int i=0; i<taille; i++){
    *(pixel_nega+i)= n - *(pixel_orig+i);
  }

  return pixel_nega;
}

int main(int argc, char* argv[])
{
  char c;
  int compteur =1;
  int x=-1,y=-1,n=-1,i=0;
  int pix;

  //pour retenir les dimension x et y
  char* chrX = (char*)malloc(10*sizeof(*chrX));
  char* chrY = (char*)malloc(10*sizeof(*chrX));

  //buffer de 4 char
  char* ctmp = (char*)malloc(4*sizeof(*ctmp));

  unsigned char *pixels, *ptrpix;

  //boucle de lecture des pixels
  do{
    c = getchar();

    //passe les whitespaces sauf retour ligne
    while(isspace(c) && c!='\n'){
      c =getchar();
    }

    //passe les commentaire
    if(c == '#'){
      while(c != '\n')
	c =getchar();
    }


    if(compteur == 2){

      //on recupere X en chaine
      i=0;
      do{
	*(chrX+i) = c;
	i++;
	c= getchar();
      }while(!isspace(c));
      *(chrX+i) = '\0';

      //conversion de X en entier
      x = atoi(chrX);

      //on passe l'espace detecte precedemment
      c=getchar();

      //pareille pour Y
      i=0;
      do{
	*(chrY+i) =c;
	i++;
	c=getchar();
      }while(!isspace(c));

      *(chrY+i) ='\0';
      y = atoi(chrY);

      pixels = (unsigned char*)malloc(x*y*sizeof(*pixels));
      ptrpix = pixels;
    }

    // niveaux de gris
    if(compteur == 3){
      i=0;
      do{
	*(ctmp+i) =c;
	i++;
	c=getchar();
      }while(c!='\n');
      *(ctmp+i) = '\0';

      n = atoi(ctmp);
    }

    //pixels
    if(compteur > 3){

      if(x<0 || y<0 || n<0){
	fprintf(stderr,"Erreur, au moins une des variables x,y ou n n'a pas ete remplie !\n");
	exit(1);
      }

      i=0;
      ctmp = (char*) calloc(4,sizeof(*ctmp)); //efface le contenu de ctmp
      do{
	*(ctmp+i) = c;
	i++;
	c = getchar();
      }while(!isspace(c) && c!=EOF);

      pix = atoi(ctmp);
      *ptrpix = (unsigned char)pix;
      ptrpix++;
    }
    
    //question 3
    if(c=='\n')
      compteur++;

  }while(c != EOF);

  //conversion negatif
  pixels = negatif(pixels,x*y,n);

  //export(P + dimensions + n)
  printf("P2\n%d %d\n%d\n",x,y,n);

  //export pixels
  for(int j=0; j<x*y; j++){
    printf("%d ",*pixels);
    pixels++;
  }

  return EXIT_SUCCESS;
}
