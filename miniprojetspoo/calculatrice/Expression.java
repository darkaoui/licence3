class Expression{

    private Expression expression1;
    private Expression expression2;
    
    private Operateur operateur;

    public Expression(){
    }

    public Expression(Expression expression, Operateur operateur){
	this.expression1 = expression;
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

    public Expression moins(Expression other){
	return new Expression(this,other,Operateur.MOINS);
    }

    public Expression fois(Expression other){
	return new Expression(this,other,Operateur.FOIS);
    }

    public Expression divise(Expression other){
	return new Expression(this,other,Operateur.DIVISE);
    }

    public Expression inverse(){
	return new Expression(this,Operateur.OPP);
    }

    public Expression oppose(){
	return new Expression(this,Operateur.INV);
    }

    public Expression calcul(Operateur op){
	switch(op){
	case PLUS:
	    return this.expression1.plus(expression2);
	case MOINS:
	    return this.expression1.moins(expression2);
	case FOIS:
	    return this.expression1.fois(expression2);
	case DIVISE:
	    return this.expression1.divise(expression2);
	case OPP:
	    return this.expression1.oppose();
	default: //INV:
	    return this.expression1.inverse();
	}
    }

    public Expression subst(Expression other, Expression inconnue){
         if(this.expression2 != null && this.expression1 instanceof Nombre && this.expression2 instanceof Nombre)
	     return calcul(this.operateur);
	 else if(this.expression2 == null && this.expression1 instanceof Nombre)
	     return calcul(this.operateur);
	 else if(this.expression2 != null)
	     return new Expression(this.expression1.subst(other,inconnue),this.expression2.subst(other,inconnue),this.operateur);
	 else
	     return new Expression(this.expression1.subst(other,inconnue),this.operateur);
    }

    private String operateurString(Operateur op){
	switch(op){
	case PLUS:
	    return "+";
	case MOINS:
	    return "-";
	case FOIS:
	    return "*";
	case DIVISE:
	    return "/";
	case OPP:
	    return "!";
	default: //INV:
	    return "#";
	}
    }

    public String toString(){
	if(expression2 == null)
	    return operateurString(this.operateur)+this.expression1;
	else
	    return "("+expression1+""+operateurString(this.operateur)+""+expression2+")";
    }
}
