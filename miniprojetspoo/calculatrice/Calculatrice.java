import java.util.*;

class Calculatrice{

    LinkedList<Double> pile;
    Scanner sc;

    public Calculatrice(){
	pile = new LinkedList<Double>();
	sc   = new Scanner(System.in);
    }

    public void empile(double d){
	pile.addLast(d);
    }

    public double depile(){
	return pile.removeLast();
    }

    public boolean isOperation(char s){
	return (s == '+' || s == '-' ||  s == '*' || s == '/');
    }


    public double opere(double a, double b, char op){

	if(op == '+')
	    return a+b;
	
	if(op == '*')
	    return a*b;
	
	if(op == '/')
	    return a/b;
	
	return a-b;
	
    }

    public void calcule(){
	String entre = sc.nextLine();

	if(isOperation(entre.charAt(0))){
	    if(pile.size() >= 2){
		double a=depile();
		double b=depile();
		double r=opere(a,b,entre.charAt(0));
		empile(r);
		System.out.println("result: "+r);
	    }else
		System.out.println("Erreur");
	}else
	    empile(Double.valueOf(entre));
	calcule();
    }

    public static void main(String args[]){
	Calculatrice c = new Calculatrice();
	System.out.println("Calculatrice");
	c.calcule();
    }    
}
