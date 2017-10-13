final class DoubleImmuable implements Nombre{
    private final double valeur;

    public DoubleImmuable(double valeur){
	this.valeur = valeur;
    }

    public Object plus(Object other){
	if(other instanceof DoubleImmuable){
	    return new DoubleImmuable(valeur+other.getValeur());
	}
	else if(other instanceof Rationnel){
	    return new DoubleImmuable((other.getNum()/other.getDen())+valeur);
	}
	else{
	    return new DoubleImmuable(valeur+other.getValeur());
	}
    }

    public Object moins(Object other){
	if(other instanceof DoubleImmuable){
	    return new DoubleImmuable(valeur-other.getValeur());
	}
	else if(other instanceof Rationnel){
	    return new DoubleImmuable((other.getNum()/other.getDen())-valeur);
	}
	else{
	    return new DoubleImmuable(valeur-other.getValeur());
	}
    }

    public Object fois(Object other){
	if(other instanceof DoubleImmuable){
	    return new DoubleImmuable(valeur*other.getValeur());
	}
	else if(other instanceof Rationnel){
	    return new DoubleImmuable((other.getNum()/other.getDen())*valeur);
	}
	else{
	    return new DoubleImmuable(valeur*other.getValeur());
	}
    }

    public Object divise(Object other){
	if(other instanceof DoubleImmuable){
	    return new DoubleImmuable(valeur/other.getValeur());
	}
	else if(other instanceof Rationnel){
	    return new DoubleImmuable((other.getNum()/other.getDen())/valeur);
	}
	else{
	    return new DoubleImmuable(valeur/other.getValeur());
	}
    }

    public getValeur(){
	return this.valeur;
    }

    public String toString(){
	return valeur+"";
    }

    public DoubleImmuable ofString(String s){
	return new DoubleImmuable(Double.valueOf(s));
    }
}
