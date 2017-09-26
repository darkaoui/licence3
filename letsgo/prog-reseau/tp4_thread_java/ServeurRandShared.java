import java.net.*;
import java.io.*;
import java.util.*;


public class ServeurRandShared{

    public static void main(String argv[]){

	try{

	    ServerSocket server = new ServerSocket(2222);
	    System.out.println("Server: "+server.getLocalSocketAddress().toString());

	    Random r = new Random();
	    int n = r.nextInt(101);

	    SharedValue v = new SharedValue(n);

	    while(true){
		Socket s = server.accept();
		Thread t = new Thread(new PlayerService(s,v));
		t.start();
		System.out.println("Un client vient de se connecter");
	    }

	}catch(Exception e){
	    System.out.println("Probleme servenu");
	}
    }
}
