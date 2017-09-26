import java.net.*;
import java.io.*;
import java.util.*;


public class ServeurRandShared{

    public static void main(String argv[]){

	try{

	    ServerSocket server = new ServerSocket(2222);
	    System.out.println("Server: "+server.getLocalSocketAddress().toString());

	    Socket listSocket[] = new Socket[3]; 

	    while(true){

		Random r = new Random();
		int n = r.nextInt(101);
		Game g = new Game(n);

		System.out.println("Une nouvelle partie");

		for(int i=0; i<listSocket.length; i++){
		    listSocket[i] = server.accept();
		    System.out.println("Un client vient de se connecter: "+i);
		}

		for(int i=0; i<listSocket.length; i++){
		    Thread t = new Thread(new PlayerService(listSocket[i],g));
		    t.start();
		}

		while(true){
		    Thread.sleep(2000);
		    if(g.finded == true)
			break;
		}

		for(int i=0; i<listSocket.length; i++){
		    if(listSocket[i] != null)
			listSocket[i].close();
		}

		System.out.println("Fin de partie");
	    }

	}catch(Exception e){
	    System.out.println("Probleme servenu");
	}
    }
}
