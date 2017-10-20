import java.util.*;

final class Rationnel extends Nombre{
    private final long num;
    private final long den;

    private long pgcd(long a, long b){
	long r=a%b;
	if(r==0)
	    return b;
	else
	    return pgcd(b,r);
    }

    public Rationnel(long a, long b){
	long p=pgcd(Math.abs(a),Math.abs(b));
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

    public long getNum(){
	return num;
    }
    
    public long getDen(){
	return den;
    }

    public Expression plus(Expression other){
	if(other instanceof Rationnel){
	    Rationnel o = (Rationnel)other;
	    return new Rationnel((o.getDen()*num)+(den*o.getNum()),den*o.getDen());
	}
	else if(other instanceof DoubleImmuable){
	    return new DoubleImmuable(((double)num/(double)den)+((DoubleImmuable)other).getValeur());
	}
	else if(other instanceof LongImmuable){
	    return this.plus(new Rationnel(((LongImmuable)other).getValeur(),1));
	}else
	    return new Expression(this,other,Operateur.PLUS);
    }

    public Expression moins(Expression other){
	if(other instanceof Rationnel){
	    Rationnel o = (Rationnel)other;
	    return new Rationnel((o.getDen()*num)-(den*o.getNum()),den*o.getDen());
	}
	else if(other instanceof DoubleImmuable){
	    return new DoubleImmuable(((double)num/(double)den)-((DoubleImmuable)other).getValeur());
	}
	else if(other instanceof LongImmuable){
	    return this.moins(new Rationnel(((LongImmuable)other).getValeur(),1));
	}else
	    return new Expression(this,other,Operateur.MOINS);
    }

    public Expression divise(Expression other){
	if(other instanceof Rationnel){
	    Rationnel o = (Rationnel)other;
	    return new Rationnel(num*o.getDen(),den*o.getNum());
	}
	else if(other instanceof DoubleImmuable){
	    return new DoubleImmuable(((double)num/(double)den)/((DoubleImmuable)other).getValeur());
	}
	else if(other instanceof LongImmuable){
	    return this.divise(new Rationnel(((LongImmuable)other).getValeur(),1));
	}else
	    return new Expression(this,other,Operateur.DIVISE);
    }

    public Expression fois(Expression other){
	if(other instanceof Rationnel){
	    Rationnel o = (Rationnel)other;
	    return new Rationnel(num*o.getNum(),den*o.getDen());
	}
	else if(other instanceof DoubleImmuable){
	    return new DoubleImmuable((((double)num*((DoubleImmuable)other).getValeur())/(double)den));
	}
	else if(other instanceof LongImmuable){
	    return this.fois(new Rationnel(((LongImmuable)other).getValeur(),1));
	}else
	    return new Expression(this,other,Operateur.FOIS);
    }

    public Expression inverse(){
	return new Rationnel(den,num);
    }
    public Expression oppose(){
	return new Rationnel(-1*num,den);
    }    

    public boolean equals(Rationnel r){
	return (num==r.getNum() && den==r.getDen());
    }

    public String toString(){
	if(num<0)
	    return ("("+num+")/"+den);
	
	return (num+"/"+den);
    }

    public static Rationnel ofString(String s){
	String[] sp=s.split("/");
	return new Rationnel(Integer.valueOf(sp[0]),Integer.valueOf(sp[1]));
    }
}
