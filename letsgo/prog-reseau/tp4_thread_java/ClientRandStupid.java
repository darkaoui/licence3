import java.io.*;
import java.net.*;
import java.util.*;

public class ClientRandStupid{

    public static void main(String argv[]){
	try{
	    
	    Socket s = new Socket("localhost",2222);

	    System.out.println(s.getLocalSocketAddress().toString());

	    BufferedReader pin = new BufferedReader(new InputStreamReader(s.getInputStream()));
	    PrintWriter   pout = new PrintWriter(new OutputStreamWriter(s.getOutputStream()));

	    String r = pin.readLine();

	    System.out.println("server: "+r);

	    while(true){

		int choix = (int)(Math.random()*(101));
		
		System.out.print("Give value: ");
		Thread.sleep(1000);
		System.out.println(choix);
		
		pout.println(choix);
		pout.flush();

		String result = pin.readLine();

		if(result == null)
		    break;
		
		System.out.println("Server: "+result);

		if(result.equals("Egal") || result.charAt(0) == '.')
		    break;
	    }

	    s.close();
	    System.out.println("See you later");
	    
	}catch(Exception e){
	    System.out.println("Probleme de connection");
	}
    }
}
