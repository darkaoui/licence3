import java.io.*;
import java.net.*;


public class Jdaytime{

    public static void main(String argv[]){

	if(argv.length != 1){
	    System.out.println("Parametres non valide");
	    return;
	}
	
	try{
	    
	    String host = argv[0];
	    Socket s = new Socket(host,13);
	    //s.setSoTimeout(10);

	    BufferedReader b = new BufferedReader(
	      new InputStreamReader(s.getInputStream()));

	    while(true){
		
		String daytime = b.readLine();

		if(daytime != null)
		    System.out.println("Daytime "+daytime);
		else{
		    System.out.println("Server closed");
		    s.close();
		    return;
		}

	    }
	    //s.close();
	    
	}catch(Exception e){
	    System.out.println("Probleme");
	}
    }

}
