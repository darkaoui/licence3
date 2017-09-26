import java.net.*;
import java.io.*;
import java.util.*;
import java.util.concurrent.*;
import java.lang.*;


public class Serv{

    CopyOnWriteArrayList<String> list;

    public Serv(){
	list = new CopyOnWriteArrayList<String>();

	Thread t1 = new Thread (new ServCons());
	Thread t2 = new Thread (new ServProd());

	t1.start();
	t2.start();
    }

    class ServCons implements Runnable{
	public void run(){
	    try{
		ServerSocket server = new ServerSocket(2222);
		System.out.println("ServProd: "+server.getLocalSocketAddress().toString());
		Socket s = server.accept();

		BufferedReader pin = new BufferedReader( new InputStreamReader(s.getInputStream()) );
		PrintWriter    pout= new PrintWriter( new OutputStreamWriter( s.getOutputStream()  ) );

		pout.println("Bienvenue Consomateur");
		pout.flush();
		
		while(true){
		    Thread.sleep(1000);
		    if(list.size() > 0){
			pout.println(list.get(0));
			pout.flush();
			list.remove(0);
		    }
		}
	    }catch(Exception e){
		System.out.println("Probleme survenu");
	    }
	}
    }

    class ServProd implements Runnable{
	public void run(){
	    try{
		ServerSocket server = new ServerSocket(2221);
		System.out.println("ServProd: "+server.getLocalSocketAddress().toString());
		Socket s = server.accept();
	    
		BufferedReader pin = new BufferedReader( new InputStreamReader(s.getInputStream()) );
		PrintWriter    pout= new PrintWriter( new OutputStreamWriter( s.getOutputStream()  ) );

		pout.println("Bienvenue Producteur");
		pout.flush();
	    
		while(true){
		    String result = pin.readLine();
		    list.add(result);
		    pout.println("Bien recu");
		    pout.flush();
		}
	    }catch(Exception e){
		System.out.println("Un probleme survenu");
	    }
	}
    }

    public static void main(String argv[]){
	new Serv();
    }
}
