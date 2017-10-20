final class LongImmuable extends Nombre{
    private final long valeur;

    public LongImmuable(long valeur){
	this.valeur = valeur;
    }

    public Expression plus(Expression other){
	if(other instanceof LongImmuable){
	    return new LongImmuable(valeur+((LongImmuable)other).getValeur());
	}
	else if(other instanceof Rationnel){
	    Rationnel o = (Rationnel)other;
	    return new Rationnel(o.getNum()+(valeur*o.getDen()),o.getDen());
	}
	else if(other instanceof DoubleImmuable){
	    return new DoubleImmuable(valeur+((DoubleImmuable)other).getValeur());
	}else
	    return new Expression(this,other,Operateur.PLUS);
    }

    public Expression moins(Expression other){
	if(other instanceof LongImmuable){
	    return new LongImmuable(valeur-((LongImmuable)other).getValeur());
	}
	else if(other instanceof Rationnel){
	    Rationnel o = (Rationnel)other;
	    return new Rationnel(o.getNum()-(valeur*o.getDen()),o.getDen());
	}
	else if(other instanceof DoubleImmuable){
	    return new DoubleImmuable(valeur-((DoubleImmuable)other).getValeur());
	}else
	    return new Expression(this,other,Operateur.MOINS);
    }

    public Expression fois(Expression other){
	if(other instanceof LongImmuable){
	    return new LongImmuable(valeur*((LongImmuable)other).getValeur());
	}
	else if(other instanceof Rationnel){
	    Rationnel o = (Rationnel)other;
	    return new Rationnel(o.getNum()*valeur,o.getDen());
	}
	else if(other instanceof DoubleImmuable){
	    return new DoubleImmuable(valeur*((DoubleImmuable)other).getValeur());
	}else
	    return new Expression(this,other,Operateur.FOIS);
    }

    public Expression divise(Expression other){
	if(other instanceof LongImmuable){
	    return new Rationnel(valeur,((LongImmuable)other).getValeur());
	}
	else if(other instanceof Rationnel){
	    Rationnel o = (Rationnel)other;
	    return new Rationnel(o.getNum(),valeur*o.getDen());
	}
	else if(other instanceof DoubleImmuable){
	    return new DoubleImmuable(valeur/((DoubleImmuable)other).getValeur());
	}else
	    return new Expression(this,other,Operateur.DIVISE);
    }

    public Expression inverse(){
	return new Rationnel(1,valeur);
    }
    
    public Expression oppose(){
	return new LongImmuable(-this.valeur);
    }

    public long getValeur(){
	return this.valeur;
    }

    public String toString(){
	if(valeur<0)
	    return "("+valeur+")";

	return valeur+"";
    }

    public static LongImmuable ofString(String s){
	return new LongImmuable(Long.valueOf(s));
    }
}
