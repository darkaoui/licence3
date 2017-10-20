import java.util.*;

class Calculatrice{

    LinkedList<Expression> pile;
    Scanner sc;

    public Calculatrice(){
	pile = new LinkedList<Expression>();
	sc   = new Scanner(System.in);
    }

    public void empile(Expression d){
	pile.addLast(d);
    }

    public Expression depile(){
	return pile.removeLast();
    }

    public char findInconnue(String s){
	String str[] = s.split(" ");
	if(str.length != 2 || !str[0].equals("subst") || str[1].length()>2)
	    return ' ';
	return str[1].charAt(0);
    }

    public boolean isOperationBinaire(char s){
	return (s == '+' || s == '-' ||  s == '*' || s == '/');
    }

    public boolean isOperationUnaire(char s){
	return (s == '!' || s == '#');
    }

    public boolean isVariable(char c){
	int v = (int)c;
	//code ASCII
	return (v>=65 && v<=90) || (v>=97 && v<=122);
    }


    public Expression opere(Expression a, Expression b, char op){

	if(op == '+')
	    return a.plus(b);
	
	if(op == '*')
	    return a.fois(b);
	
	if(op == '/')
	    return a.divise(b);

	//Moins
	return a.moins(b);
    }

    public Expression opere(Expression a, char op){
	if(op == '!')
	    return a.inverse();
	else
	    return a.oppose();
    }

    public void calcule(){

	while(true){
	    
	    System.out.print("calc>");
	    String entre = sc.nextLine();

	    if(entre.isEmpty())
		continue;
	    else if(entre.contains("subst")){
		//Operateur subst
		char c = findInconnue(entre);
		if(c == ' ')
		    System.out.println("Erreur");
		else{

		    Inconnue x = new Inconnue(findInconnue(entre)+"");
		    if(pile.size()>=2){
			
			Expression b = depile();
			Expression a = depile();
		    	
			if(a.contains(x)){
			    Expression r = a.subst(b,x);
			    empile(r);
			    System.out.println("result> "+r);
			}else{
			    System.out.println("Erreur");
			    empile(a);
			    empile(b);
			}
	      
		    }else
			System.out.println("Erreur");
		    
		}
	    }else if(isOperationBinaire(entre.charAt(0))){
		//les operateurs binaires
		if(pile.size() >= 2){
		    Expression b=depile();
		    Expression a=depile();
		    Expression r=opere(a,b,entre.charAt(0));
		    empile(r);
		    System.out.println("result> "+r);
		}else
		    System.out.println("Erreur");
	    }else if(isOperationUnaire(entre.charAt(0))){
		//les operateur unaires
		Expression a = depile();
		Expression r = opere(a,entre.charAt(0));
		empile(r);
		System.out.println("result> "+r);
	    }else{

		if(entre.contains(".")){
		    //On a faire avec un double

		    try{
			empile(DoubleImmuable.ofString(entre));
		    }catch(Exception e){
			System.out.println("Erreur");
		    }

		}else if(entre.contains("/")){
		    //On a faire avec un Rationnel
		    try{
			empile(Rationnel.ofString(entre));
		    }catch(Exception e){
			System.out.println("Erreur");
		    }
		}else{

		    try{
			empile(LongImmuable.ofString(entre));
		    }catch(Exception e){
			//On traite le cas d'une variable
			if(entre.length() > 2 || !isVariable(entre.charAt(0)))
			    System.out.println("Erreur");
			else
			    empile(new Inconnue(entre.charAt(0)+""));
		    }
		}
	    }
	}
    }

    public static void main(String args[]){
	Calculatrice c = new Calculatrice();
	System.out.println("Calculatrice");
	c.calcule();
    }    
}
