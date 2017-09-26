import java.io.*;
import java.net.*;
import java.util.*;

public class ClientRandGenious{

    public static void main(String argv[]){

	try{
	    
	    Socket s = new Socket("localhost",2222);

	    System.out.println(s.getLocalSocketAddress().toString());

	    BufferedReader pin = new BufferedReader(new InputStreamReader(s.getInputStream()));
	    PrintWriter   pout = new PrintWriter(new OutputStreamWriter(s.getOutputStream()));

	    String r = pin.readLine();

	    System.out.println("server: "+r);

	    //Scanner sc = new Scanner(System.in);

	    int min = 0;
	    int max = 100;
	    int v   = -1;

	    String result = null;

	    while(true){
		
		System.out.print("Give value: ");
		Thread.sleep(1000);

		if(result == null || v == -1){
		    v = 50;
		    pout.println(v);
		    pout.flush();
		}else{

		    if(result.equals("Plus")){
			min =v;
			v = (max-min)/2 + min;
			pout.println(v);
			pout.flush();
			
		    }else if(result.equals("Moins")){
			
			max = v;
			v = (max-min)%2 == 0 ? ((max-min)/2) + min : ((max-min)/2)+1+min;
			pout.println(v);
			pout.flush();
		    }
		}

		System.out.println(v);
		

		result = pin.readLine();

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
