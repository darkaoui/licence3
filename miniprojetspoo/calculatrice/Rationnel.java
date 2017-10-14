import java.util.*;

final class Rationnel implements Nombre{
    private final int num;
    private final int den;

    private int pgcd(int a, int b){
	int r=a%b;
	if(r==0)
	    return b;
	else
	    return pgcd(b,r);
    }

    public Rationnel(int a, int b){
	int p=pgcd(a,b);
	if(b<0){
	    num=-(a/p);
	    den=-(b/p);
	}
	else{
	    num=a/p;;
	    den=b/p;
	}
    }

    /*private Rationnel( Rationnel r){
      Rationnel(r.getNum(),r.getDen());
      }

      public static Rationnel fabrique(int a, int b){
      return new Rationnel(a,b);
      }*/

    public int getNum(){
	return num;
    }
    
    public int getDen(){
	return den;
    }

    public Expression plus(Expression other){
	if(other instanceof Rationnel){
	    Rationnel o = other;
	    return new Rationnel((o.getDen()*num)+(den*o.getNum()),den*o.getDen());
	}
	else if(other instanceof DoubleImmuable){
	    return new DoubleImmuable((num/den)+((DoubleImmuable)other).getValeur());
	}
	else if(other instanceof LongImmuable){
	    return this.plus(new Rationnel(((LongImmuable)other).getValeur(),1));
	}else
	    return new Expression(this,other,Operateur.PLUS);
    }

    public Expression moins(Expression other){
	if(other instanceof Rationnel){
	    Rationnel o = other;
	    return new Rationnel((o.getDen()*num)-(den*o.getNum()),den*o.getDen());
	}
	else if(other instanceof DoubleImmuable){
	    return new DoubleImmuable((num/den)-((DoubleImmuable)other).getValeur());
	}
	else if(other instanceof LongImmuable){
	    return this.moins(new Rationnel(other.getValeur(),1));
	}else
	    return new Expression(this,other,Operateur.MOINS);
    }

    public Expression divise(Expression other){
	if(other instanceof Rationnel){
	    Rationnel o = other;
	    return new Rationnel(num*o.getDen(),den*o.getNum());
	}
	else if(other instanceof DoubleImmuable){
	    return new DoubleImmuable(((double)num/den)/((DoubleImmuable)other).getValeur());
	}
	else if(other instanceof LongImmuable){
	    return this.divise(new Rationnel(((LongImmuable)other).getValeur(),1));
	}else
	    return Expression(this,other,Operateur.DIVISE);
    }

    public Expression fois(Expression other){
	if(other instanceof Rationnel){
	    Rationnel o = other;
	    return new Rationnel(num*o.getNum(),den*o.getDen());
	}
	else if(other instanceof DoubleImmuable){
	    return new DoubleImmuable(((double)num/den)*((DoubleImmuable)other).getValeur());
	}
	else if(other instanceof LongImmuable){
	    return this.fois(new Rationnel(((LongImmuable)other).getValeur(),1));
	}else
	    return Expression(this,other,Operateur.FOIS);
    }

    public boolean equals(Rationnel r){
	return (num==r.getNum() && den==r.getDen());
    }

    public String toString(){
	return (num+"/"+den);
    }

    public static Rationnel ofString(String s){
	String[] sp=s.split("/");
	return new Rationnel(Integer.valueOf(sp[0]),Integer.valueOf(sp[1]));
    }
}
