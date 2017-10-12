
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define LIGNE 10
#define COLONNE 15
#define MINES 10

#define DEJAVU 1
#define PASVU 0



typedef struct parcelle {
  int mine; /* -1 s'il y a une mine, nombre de voisins mines sinon */
  int statut; /* DEJAVU si deja vu, PASVU sinon */
} parcelle;

typedef struct champs {
  int largeur;  /* nombre de lignes */
  int longueur; /* nombre de colonnes */
  parcelle **p;
} champs;


champs init(int ligne, int colonne, int mines){
  champs C;
  int i, j, posees=0;

  C.largeur = ligne;
  C.longueur = colonne;

  parcelle **p = (parcelle**)calloc(ligne,sizeof(parcelle*));
  C.p = p;
  
  for(i=0; i<ligne; i++)
    C.p[i] = (parcelle*)calloc(colonne, sizeof(parcelle));

  srand((int) time(NULL));
  while(posees<mines+1){
    i = 1+(int) ((ligne-1.0)*rand()/(RAND_MAX+1.0));
    j = 1+(int) ((colonne-1.0)*rand()/(RAND_MAX+1.0));
    if(C.p[i][j].mine != -1){
      C.p[i][j].mine = -1;
      posees++;
      }
  }

  return C;
}



void affichage(champs C){
  int i, j;

  printf("    ");
  for(j=0; j<C.longueur; j++)
    printf("%d ", j%10);
  printf("\n   ");
  for(j=0; j<2*C.longueur; j++)
    printf("-");
  printf("\n");

  for(i=0; i<C.largeur; i++){
    printf("%d | ", i%10);
    for(j=0; j<C.longueur; j++){
      if(C.p[i][j].statut==PASVU)
	printf("x ");
      else printf("%d ", C.p[i][j].mine);
    }
    printf("\n");
  }
}



void tricheur(champs C){
  int i, j;

  printf("    ");
  for(j=0; j<C.longueur; j++)
    printf("%d ", j%10);
  printf("\n   ");
  for(j=0; j<2*C.longueur; j++)
    printf("-");
  printf("\n");

  for(i=0; i<C.largeur; i++){
    printf("%d | ", i%10);
    for(j=0; j<C.longueur; j++){
      if(C.p[i][j].mine==-1)
	printf("m ");
      else printf("%d ", C.p[i][j].mine);
    }
    printf("\n");
  }
}



int voisin(champs C, int i, int j){
  int valeur=0, k, l;

  for(k=-1; k<2; k++){
    for(l=-1; l<2; l++){
      if(i+k>=0 && i+k<C.longueur && j+l>=0 && j+l<C.largeur && C.p[i+k][j+l].mine==-1)
	valeur++;
    }
  }

  return valeur;
}



int jeu(champs C, int nontrouvees){
  int i=-1, j=-1;


  while(i>C.largeur || j>C.longueur || i<0 || j<0){
    printf("coordonnees du point : ");
    scanf("%d%d", &i, &j);
  }

  if (C.p[i][j].mine==-1)
    return -1;
  C.p[i][j].mine = voisin(C, i, j);
  if(C.p[i][j].statut==PASVU)
    printf("\nil reste %d case(s) non minee(s) a trouver\n\n", nontrouvees-1);
  C.p[i][j].statut = DEJAVU;
  
  if (nontrouvees-1!=0)
    return 0;
  else return 1;
}



int main(){
  champs C;
  int nontrouvees = COLONNE*LIGNE-MINES, res;

  C = init(LIGNE, COLONNE, MINES);
  tricheur(C);

  while((res=jeu(C, nontrouvees)) == 0){
    nontrouvees--;
    affichage(C);
  }

  if(res == -1)
    printf(" !!! BOUM !!!\n");
  else
    printf("BRAVO!\n");

  return 0;
}
