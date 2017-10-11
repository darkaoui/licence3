import java.util.*;

class Calculatrice{

    LinkedList pile;
    Scanner sc;

    public Calculatrice(){
	pile = new LinkedList();
	sc   = new Scanner(System.in);
    }

    public empile(double d){
	pile.addLast(d);
    }

    public double depile(){
	return pile.remove();
    }

    public boolean isOperation(String s){
	return (s == "+" || s == "-" ||  s == "*" || s == "/");
    }


    public double opere(double a, double b, char op){

	if(op == '+'){
	    return a+b;
	}
	
	if(op == '*'){
	    return a*b;
	}
	
	if(op == '/'){
	    return a/b;
	}
	
	if(op == '-'){
	    return a-b;
	}
    }

    public calcule(){
	String entre = sc.nextLine();

	if(isOperation(entre.charAt(0))){
	    if(pile.size() >= 2){
		a=depile();
		b=depile();
		r=opere(a,b,entre.charAt(0));
		empile(r);
		Sytem.out.println("result: "+r);
	    }else
		System.out.println("Erreur");
	}else
	    empile(Double.valueOf(entre));
	calcule();
    }

    public static void main(){
	System.out.println("Calculatrice");
	calcule();
    }    
}
