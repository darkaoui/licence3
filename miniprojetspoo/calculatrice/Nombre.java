abstract class Nombre extends Expression{
    abstract public Expression plus(Expression other);
    abstract public Expression moins(Expression other);
    abstract public Expression fois(Expression other);
    abstract public Expression divise(Expression other);
}
