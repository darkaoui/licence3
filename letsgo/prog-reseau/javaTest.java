import java.net.*;
import java.io.*;

public class javaTest{
    public static void main(String argv[]){
	System.out.println("hello world");

	try{

	    Socket s = new Socket("localhost",22);
	    System.out.println("connexion reussie...");
	    System.out.println("local port "+s.getLocalPort());
	    s.close();

	}catch(Exception e){
	    System.out.println(e);
	    System.out.println("Connexion non reussie...");
	}
    }
}
