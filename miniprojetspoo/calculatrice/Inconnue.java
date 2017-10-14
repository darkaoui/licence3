final class Inconnue extends Expression{
    
    private final String nom;

    public Inconnue(String nom){
	this.nom = nom;
    }

    public String toString(){
	return getNom();
    }

    public Expression subst(Expression other, Expression inconnue){
	if(inconnue.toString().equals(nom))
	    return other;
	else
	    return this;
    }
}
