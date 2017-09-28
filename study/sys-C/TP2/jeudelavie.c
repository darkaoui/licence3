#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int N = 5;
char m[N][N];


void init_univ(){
  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
      m[i][j] = rand()%2;
    }
  }
}

void affiche(){
  for(int i=0; i<N; i++){
    for(int j=0; j<N; i++){
      printf(" %d",m[i]m[j]);
    }
    printf("\n");
  }
}

char left(int i, int j){
  return m[i][j-1];
}
// direction: left(0) right(1) up(2) down(3) up_left(4) up_right(5)
//             down_left(6) down_right(7)
char voisine(int i,int j, int direction){
  switch(direction){
  case 0:
    return m[i][j-1];
    break;
  case 1:
    return m[i][j+1];
    break;
    case 2:
      return m[i+1][j];
    break;
    case 3:
      return m[i-1][j];
    break;
    case 4:
      return m[i+1][j-1];
    break;
    case 5:
      return m[i+1][j+1];
    break;
    case 6:
      return m[i-1][j-1];
    break;
  case 7:
    return m[i-1][j+1];
    break;
  }

  return -1;
}

void step(){
  for(int i=0; i<N;i++){
    for(int j=0; j<N; j++){
      if(m[i][j] == 0){
	
	int voisine = 0;
	for(int v=0; v<7;v++){
	  if(voisine(i,j,v) == 1)
	    voisine++;
	}

	if(voisine == 3)
	  m[i][j] = 1;
	  
      }else if(m[i][j] == 1){

	int voisine = 0;
	for(int v=0; v<7;v++){
	  if(voisine(i,j,v) == 1)
	    voisine++;
	}

	if(voisine != 2 && voisine != 3)
	  m[i][j] = 0;
	  
      }
    }
  }
}

int main(){
  srand(time(NULL));
  while(1){
    init_univ();
    affiche();
    sleep(1);
  }
}
