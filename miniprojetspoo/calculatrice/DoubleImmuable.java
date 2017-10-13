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

    public Object plus(Object other){
	if(other instanceof Rationnel){
	    return new Rationnel((other.getDen()*num)+(den*other.getNum()),den*other.getDen());
	}
	else if(other instanceof DoubleImmuable){
	    return new DoubleImmuable((num/den)+other.getValeur());
	}
	else{
	    return this.plus(new Rationnel(other.getValeur(),1));
	}
    }

    public Object moins(Object other){
	if(other instanceof Rationnel){
	    return new Rationnel((other.getDen()*num)-(den*other.getNum()),den*other.getDen());
	}
	else if(other instanceof DoubleImmuable){
	    return new DoubleImmuable((num/den)-other.getValeur());
	}
	else{
	    return this.moins(new Rationnel(other.getValeur(),1));
	}
    }

    public Object divise(Object other){
	if(other instanceof Rationnel){
	    return new Rationnel(num*other.getDen(),den*other.getNum());
	}
	else if(other instanceof DoubleImmuable){
	    return new DoubleImmuable((num/den)/other.getValeur());
	}
	else{
	    return this.divise(new Rationnel(other.getValeur(),1));
	}
    }

    public Object fois(Object other){
	if(other instanceof Rationnel){
	    return new Rationnel(num*other.getNum(),den*other.getDen());
	}
	else if(other instanceof DoubleImmuable){
	    return new DoubleImmuable((num/den)*other.getValeur());
	}
	else{
	    return this.fois(new Rationnel(other.getValeur(),1));
	}
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
