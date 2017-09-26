import java.net.*;
import java.io.*;


public class ServeurMajuscule{

    public static void main(String argv[]){
	try{
	    
	    ServerSocket s = new ServerSocket(2222);

	    System.out.println("Port:"+s.getLocalPort()+" Address:"+s.getLocalSocketAddress().toString());
	    Socket c = s.accept();

	    BufferedReader pin = new BufferedReader(new InputStreamReader(c.getInputStream()));
	    PrintWriter   pout = new PrintWriter(new OutputStreamWriter(c.getOutputStream()));

	    pout.print("Hello, don't forget the endline \n");
	    pout.flush();

	    String r = "";
	    while(true){
		r = pin.readLine();

		System.out.println("msg recu: "+r);

		if(r == null)
		    break;

		if(r.equals("."))
		    break;

		pout.println(r.toUpperCase());
		pout.flush();
	    }

	    c.close();
	    s.close();

	    System.out.println("See you later");
	    
	}catch(Exception e){
	    System.out.println("Echec de communication");
	}
    }
}
