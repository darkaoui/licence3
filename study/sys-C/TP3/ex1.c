/*
  Question 1: la taille minimal en memoire serait {un entier compte 32 bits(4 octet)} pour les 4 reponses on a 16 octet pour
              pour chaque individu donc au total on a: 64 octet(512bits)

*/


//Question 2
const char teteDeVeau   = 0b0001;
const char vin          = 0b0010;
const char caviar       = 0b0100;
const char eauMinerale  = 0b1000; 

//Question 3
char Jacques   =0;
char Nicolas   =0;
char JeanLouis =0;
char Olivier   =0;

char teteDeVeauEtVin(char);

int main(){

}

char texteDeVeauEtVin(char i){
  if ((teteDeVeau & i) == 0 || (vin & i) == 0 )
    return 0;
  else
    return 1;
}
