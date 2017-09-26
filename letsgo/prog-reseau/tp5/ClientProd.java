import java.io.*;
import java.net.*;
import java.util.*;

public class ClientProd{

    public static void main(String argv[]){
	try{
	    
	    Socket s = new Socket("localhost",2221);

	    System.out.println(s.getLocalSocketAddress().toString());

	    BufferedReader pin = new BufferedReader(new InputStreamReader(s.getInputStream()));
	    PrintWriter   pout = new PrintWriter(new OutputStreamWriter(s.getOutputStream()));

	    String r = pin.readLine();

	    System.out.println("server: "+r);

	    Scanner sc = new Scanner(System.in);

	    while(true){

		System.out.println("Entrer une chaine: ");
		String chaine = sc.nextLine(); 

		if(chaine.equals("QUIT"))
		    break;
		
		pout.println(chaine);
		pout.flush();
	    }

	    s.close();
	    System.out.println("See you later");
	    
	}catch(Exception e){
	    System.out.println("Probleme de connection");
	}
    }
}
