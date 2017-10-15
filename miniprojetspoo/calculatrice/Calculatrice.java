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

    public boolean isOperationBinaire(char s){
	return (s == '+' || s == '-' ||  s == '*' || s == '/');
    }

    public boolean isOperationUnaire(char s){
	return (s == '!' || s == '#');
    }


    public Expression opere(Expression a, Expression b, char op){

	if(op == '+')
	    return a.plus(b);
	
	if(op == '*')
	    return a.fois(b);
	
	if(op == '/')
	    return a.divise(b);
	
	return a.moins(b);
	
    }

    public Expression opere(Expression a, char op){
	if(op == '!')
	    return a.inverse();
	else
	    return a.oppose();
    }

    public void calcule(){
	System.out.print("calc>");
	String entre = sc.nextLine();
	if(isOperationBinaire(entre.charAt(0))){
	    if(pile.size() >= 2){
		Expression b=depile();
		Expression a=depile();
		Expression r=opere(a,b,entre.charAt(0));
		empile(r);
		System.out.println("result> "+r);
	    }else
		System.out.println("Erreur");
	}else if(isOperationUnaire(entre.charAt(0))){
	    Expression a = depile();
	    Expression r = opere(a,entre.charAt(0));
	    empile(r);
	    System.out.println("result> "+r);
	}else{
	    //On empile selon la saisie
	    empile(new DoubleImmuable(Double.valueOf(entre)));
	}
	calcule();
    }

    public static void main(String args[]){
	Calculatrice c = new Calculatrice();
	System.out.println("Calculatrice");
	c.calcule();
    }    
}
