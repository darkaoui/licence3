
public enum Operateur{PLUS,MOINS,FOIS,DIVISE,OPP,INV}

final class Expression{

    final private Expression expression1;
    final private Expression expression2;
    
    final private Operateur operateur;

    public Expression(Expression expression, Operateur operateur){
	this.expression1 = expresion;
	this.expression2 = null;
	this.operateur   = operateur;
    }

    public Expression(Expression expression1, Expression expression2, Operateur operateur){
	this.expression1 = expression1;
	this.expression2 = expression2;
	this.operateur   = operateur;
    }

    public Expression plus(Expression other){
	return new Expression(this,other,Operateur.PLUS);
    }

    public Expression mois(Expression other){
	return new Expression(this,other,Operateur.MOINS);
    }

    public Expression fois(Expression other){
	return new Expression(this,other,Operateur.FOIS);
    }

    public Expression divise(Expression other){
	return new Expression(this,other,Operateur.DIVISE);
    }

    public Expression inverse(Expression other){
	return new Expression(this,Operateur.OPP);
    }

    public Expression oppose(Expression other){
	return new Expression(this,Operateur.INV);
    }

    public Expression calcul(Operateur op){
	switch(op){
	case PLUS:
	    this.expression1.plus(expression2);
	    break;
	case MOINS:
	    this.expression1.moins(expression2);
	    break;
	case FOIS:
	    this.expression1.fois(expression2);
	    break;
	case DIVISE:
	    this.expression1.divise(expression2);
	    break;
	case OPP:
	    this.expression1.oppose(expression2);
	    break;
	case INV:
	    this.expression1.inverse(expression2);
	}
    }

    public Expression subst(Expression other, Expression inconnue){
         if(this.expression2 != null && this.expression1 instanceof Number && this.expression2 instanceof Number)
	     return calcul(this.operateur);
	 else if(this.expression2 == null && this.expression1 instanceof Number)
	     return calcul(this.operateur);
	 else if(this.expression2 != null)
	     return new Expression(this.expression1.subst(other,inconnue),this.expression2.subst(other,inconnue),this.operateur);
	 else
	     return new Expression(this.expression1.subst(other,inconnue));
    }

    public String toString(){
	if(expression2 == null)
	    return operateur+this.expression1;
	else
	    return "("+expression1+" "+operateur+" "+expression2+")";
    }
}
