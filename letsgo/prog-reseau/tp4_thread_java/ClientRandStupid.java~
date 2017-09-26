import java.io.*;
import java.net.*;
import java.util.*;

public class ClientPlusMoins{

    public static void main(String argv[]){
	try{
	    
	    Socket s = new Socket("localhost",2222);

	    System.out.println(s.getLocalSocketAddress().toString());

	    BufferedReader pin = new BufferedReader(new InputStreamReader(s.getInputStream()));
	    PrintWriter   pout = new PrintWriter(new OutputStreamWriter(s.getOutputStream()));

	    String r = pin.readLine();

	    System.out.println("server: "+r);

	    Scanner sc = new Scanner(System.in);

	    while(true){
		
		System.out.print("Give value: ");
		String enter = sc.nextLine();
		
		pout.println(enter);
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
