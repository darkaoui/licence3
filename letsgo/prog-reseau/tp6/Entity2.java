import java.io.*;
import java.net.*;
import java.util.*;

public class Entity2{
    public static void main(String argv[]){
	try{
	    
	    String address = "127.0.0.1";
	    String port    = "2221";
	    
	    Socket s = new Socket("localhost",2222);

	    //BufferedReader pin = new BufferedReader(new InputStreamReader(s.getInputStream()));
	    PrintWriter   pout = new PrintWriter(new OutputStreamWriter(s.getOutputStream()));

	    pout.println(address+" "+port);
	    pout.flush();

	    System.out.println("Message envoyer: "+address+ " "+port);

	    int p = Integer.parseInt(port);
	    ServerSocket serv = new ServerSocket(p);

	    //Thread.sleep(2000);
	    s.close();
	    
	    s = serv.accept();
	    BufferedReader pin = new BufferedReader(new InputStreamReader(s.getInputStream()));
	    pout = new PrintWriter(new OutputStreamWriter(s.getOutputStream()));

	    String msg = pin.readLine();

	    while(!msg.equals("CONFIRM")){
		msg = pin.readLine();
	    }

	    pout.println("ACKCONFIRM");
	    pout.flush();
	    
	}catch(Exception e){
	    System.out.println("probleme survenu...");
	}
	
    }
}
