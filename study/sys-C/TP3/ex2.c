//Question 5
void echange(int *adra, int *adrb){

  int tmp = *adra;
  *adra = *adrb;
  *adra = tmp;
  
}

//Question 6
// & sert d'acces a l'address de la variable l'accompagnant


//Question 7
int read_int(int *adr){
  
  //suppons que la suite ce limite a 10 chiffre
  char entier[11];
  char c;

  int inc =0;

  while(c=getchar() != EOF && inc<10){

    if(c == '\n')
      break;
    
    if((c < '0' || c > '9'))
      return 0;

    entier[inc++] = c;
    
  }

  entier[inc+1] = '\0';
  *adr = atoi(entier);

  return 1;
}

