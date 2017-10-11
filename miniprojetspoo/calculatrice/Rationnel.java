import java.util.*;

final class Rationnel{
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

	public Rationnel plus(Rationnel r){
		return new Rationnel((r.getDen()*num)+(den*r.getNum()),den*r.getDen());
	}

	public Rationnel moins(Rationnel r){
		return new Rationnel((r.getDen()*num)-(den*r.getNum()),den*r.getDen());		
	}

	public Rationnel divise(Rationnel r){
		return new Rationnel(num*r.getDen(),den*r.getNum());
	}

	public Rationnel fois(Rationnel r){
		return new Rationnel(num*r.getNum(),den*r.getDen());
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
