 final class LongImmuable extends Nombre{
    private final long valeur;

    public LongImmuable(long valeur){
	this.valeur = valeur;
    }

    public Expression plus(Expression other){
	if(other instanceof LongImmuable){
	    LongImmuable o = other;
	    return new LongImmuable(valeur+o.getValeur());
	}
	else if(other instanceof Rationnel){
	    Rationnel o = other;
	    return new Rationnel(o.getNum()+(valeur*o.getDen()),o.getDen());
	}
	else if(other instanceof DoubleImmuable){
	    DoubleImmuable o = other;
	    return new DoubleImmuable(valeur+o.getValeur());
	}else
	    return new Expression(this,other,Operateur.PLUS);
    }

    public Expression moins(Expression other){
	if(other instanceof LongImmuable){
	    LongImmuable o = other;
	    return new LongImmuable(valeur-o.getValeur());
	}
	else if(other instanceof Rationnel){
	    Rationnel o = other;
	    return new Rationnel(o.getNum()-(valeur*o.getDen()),o.getDen());
	}
	else if(other instanceof DoubleImmuable){
	    DoubleImmuable o = other;
	    return new DoubleImmuable(valeur-o.getValeur());
	}else
	    return new Expression(this,other,Operateur.MOINS);
    }

    public Expression fois(Expression other){
	if(other instanceof LongImmuable){
	    return new LongImmuable(valeur*((LongImmuable)other).getValeur());
	}
	else if(other instanceof Rationnel){
	    Rationnel o = other;
	    return new Rationnel(o.getNum()*valeur,o.getDen());
	}
	else if(other instanceof DoubleImmuable){
	    return new DoubleImmuable(valeur*((DoubleImmuable)other).getValeur());
	}else
	    return new Expression(this,other,Operateur.FOIS);
    }

    public Expression divise(Expression other){
	if(other instanceof LongImmuable){
	    return new LongImmuable(valeur/((LongImmuable)other).getValeur());
	}
	else if(other instanceof Rationnel){
	    Rationnel o = other;
	    return new Rationnel((o.getNum(),valeur*o.getDen()));
	}
	else if(other instanceof DoubleImmuable){
	    return new DoubleImmuable(valeur/((DoubleImmuable)other).getValeur());
	}else
	    return new Expression(this,other,Operateur.DIVISE);
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
