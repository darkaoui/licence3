import java.net.*;
import java.io.*;
import java.lang.*;


public class ThreaderServer{

    public static void main(String argv[]){

	try{
	    
	    ServerSocket server = new ServerSocket(2222);

	    System.out.println("Server: "+server.getLocalSocketAddress().toString());

	    while(true){
		Socket s = server.accept();
		Thread t = new Thread(new PlayerService(s));
		t.start();
		System.out.println("Un client vient de se connecter");
		
	    }
	    
	}catch(Exception e){
	    System.out.println("Probleme survenu");
	}
    }
}
