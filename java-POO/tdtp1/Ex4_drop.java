class A{
    void g(){}
}

class B extends A{
    
    void g(){}
    void f(){}
}

class C extends A{}

public class Ex4_drop{
    public static void main(String[] args){
	//System.out.println((int)true);
	System.out.println((int)'a');
	System.out.println((byte)'a');

	System.out.println((byte)257);
	System.out.println((char)98);
	System.out.println((double)98);
	System.out.println((long)98.12);
	//System.out.println((boolean)98);
	
	System.out.println((B)new A());
	//System.out.println((C)new B());
	System.out.println((A)new C());
	System.out.println((A)new B());
    }
}
