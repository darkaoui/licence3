import java.net.*;
import java.io.*;
import java.util.*;

public class Entity1{

    public static void main(String argv[]){
	try{
	    
	    ServerSocket serv = new ServerSocket(2222);
	    Socket s = serv.accept();

	    BufferedReader pin = new BufferedReader(new InputStreamReader(s.getInputStream()));
	    String msg = pin.readLine();

	    System.out.println("Recu "+msg);

	    //Thread.sleep(1000);
	    s.close();
	    serv.close();

	    String addressPort[] = msg.split(" ");
	    String address = addressPort[0].trim();
	    String port    = addressPort[1].trim();

	    s = new Socket(address,Integer.parseInt(port));
	    PrintWriter pout = new PrintWriter(new OutputStreamWriter(s.getOutputStream()));
	    pin              = new BufferedReader(new InputStreamReader(s.getInputStream()));
	    
	    pout.println("CONFIRM");
	    pout.flush();
	    
	    msg = pin.readLine();

	    while(!msg.equals("ACKCONFIRM")){

		System.out.println("msg recu: "+msg);
		msg = pin.readLine();
	    }
	    System.out.println("message recu "+ msg);
	    System.out.println("A bientot");
	    
	}catch(Exception e){
	    System.out.println("Probleme survenu...");
	}
    }

}
