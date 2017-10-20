 final class DoubleImmuable extends Nombre{
    private final double valeur;

    public DoubleImmuable(double valeur){
	this.valeur = valeur;
    }

    public Expression plus(Expression other){

	if(other instanceof DoubleImmuable){
	    return new DoubleImmuable(valeur+((DoubleImmuable)other).getValeur());
	}else if(other instanceof LongImmuable){
	    return new DoubleImmuable(valeur + ((LongImmuable)other).getValeur());
	}
	else if(other instanceof Rationnel){
	    Rationnel o = (Rationnel)other;
	    return new DoubleImmuable((o.getNum()/o.getDen())+valeur);
	}else
	    return new Expression(this,other,Operateur.PLUS);
    }

    public Expression moins(Expression other){

	if(other instanceof DoubleImmuable){
	    return new DoubleImmuable(valeur - ((DoubleImmuable)other).getValeur());
	}else if(other instanceof LongImmuable){
	    return new DoubleImmuable(valeur - ((LongImmuable)other).getValeur());
	}
	else if(other instanceof Rationnel){
	    Rationnel o = (Rationnel)other;
	    return new DoubleImmuable((o.getNum()/o.getDen())-valeur);
	}else
	    return new Expression(this,other,Operateur.MOINS);
    }

    public Expression fois(Expression other){
	
	if(other instanceof DoubleImmuable){
	    return new DoubleImmuable(valeur * ((DoubleImmuable)other).getValeur());
	}else if(other instanceof LongImmuable){
	    return new DoubleImmuable(valeur * ((LongImmuable)other).getValeur());
	}
	else if(other instanceof Rationnel){
	    Rationnel o = (Rationnel)other;
	    return new DoubleImmuable((o.getNum()/o.getDen())*valeur);
	}
	else{
	    return new Expression(this,other,Operateur.FOIS);
	}
    }

    public Expression divise(Expression other){

	if(other instanceof DoubleImmuable){
	    return new DoubleImmuable(valeur / ((DoubleImmuable)other).getValeur());
	}else if(other instanceof LongImmuable){
	    return new DoubleImmuable(valeur / ((LongImmuable)other).getValeur());
	}
	else if(other instanceof Rationnel){
	    Rationnel o = (Rationnel)other;
	    return new DoubleImmuable((o.getNum()/o.getDen())/valeur);
	}
	else{
	    return new Expression(this,other,Operateur.DIVISE);
	}
    }

    //inverse et oppose

     public Expression inverse(){
	 return new DoubleImmuable(1/valeur);
     }
     
     public Expression oppose(){
	 return new DoubleImmuable(-1*valeur);
     }

    public double getValeur(){
	return this.valeur;
    }

    public String toString(){
	if(valeur <0.0)
	    return "("+valeur+")";
	
	return valeur+"";
    }

    public static DoubleImmuable ofString(String s){
	return new DoubleImmuable(Double.valueOf(s));
    }
}
