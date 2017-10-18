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

    private Expression calcul(){
	switch(this.operateur){
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

    public boolean contains(Inconnue inconnue){
	return this.toString().contains(inconnue.toString());
    }

    public Expression subst(Expression other, Expression inconnue){

	if(this.expression2 != null){

	    Expression exp2 = this.expression2.subst(other,inconnue);
	    Expression exp1 = this.expression1.subst(other,inconnue);

	    if(exp1 instanceof Nombre && exp2 instanceof Nombre)
		return new Expression(exp1,exp2,this.operateur).calcul();
	    else
		return new Expression(exp1,exp2,this.operateur);
	    
	}else{
	    
	    Expression exp1 = this.expression1.subst(other,inconnue);
	    
	    if(exp1 instanceof Nombre)
		return new Expression(exp1,this.operateur).calcul();
	    else
		return new Expression(exp1,this.operateur);
	}
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
	    return operateurString(this.operateur)+"("+this.expression1+")";
	else
	    return "("+expression1+""+operateurString(this.operateur)+""+expression2+")";
    }
}
