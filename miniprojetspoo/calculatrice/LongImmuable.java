final class LongImmuable implements Nombre{
    private final long valeur;

    public LongImmuable(long valeur){
	this.valeur = valeur;
    }

    public Object plus(Object other){
	if(other instanceof LongImmuable){
	    return new LongImmuable(valeur+other.getValeur());
	}
	else if(other instanceof Rationnel){
	    return new Rationnel((other.getNum()+(valeur*other.getDen()),other.getDen()));
	}
	else{
	    return new DoubleImmuable(valeur+other.getValeur());
	}
    }

    public Object moins(Object other){
	if(other instanceof LongImmuable){
	    return new LongImmuable(valeur-other.getValeur());
	}
	else if(other instanceof Rationnel){
	    return new Rationnel((other.getNum()-(valeur*other.getDen()),other.getDen()));
	}
	else{
	    return new DoubleImmuable(valeur-other.getValeur());
	}
    }

    public Object fois(Object other){
	if(other instanceof LongImmuable){
	    return new LongImmuable(valeur*other.getValeur());
	}
	else if(other instanceof Rationnel){
	    return new Rationnel((other.getNum()*valeur,other.getDen()));
	}
	else{
	    return new DoubleImmuable(valeur*other.getValeur());
	}
    }

    public Object divise(Object other){
	if(other instanceof LongImmuable){
	    return new LongImmuable(valeur/other.getValeur());
	}
	else if(other instanceof Rationnel){
	    return new Rationnel((other.getNum(),valeur*other.getDen()));
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

    public LongImmuable ofString(String s){
	return new LongImmuable(Long.valueOf(s));
    }
}
