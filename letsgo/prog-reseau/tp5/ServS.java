import java.net.*;
import java.io.*;
import java.util.*;
import java.util.concurrent.*;
import java.lang.*;


public class ServS{

    CopyOnWriteArrayList<String> list;
    Integer entier = new Integer(0);

    public ServS(){
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
		while(true){
		    Socket s = server.accept();
		    Thread t = new Thread(new ServConsService(s));
		    t.start();
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
		while(true){
		   Socket s = server.accept();
		   Thread t = new Thread(new ServProdService(s));
		   t.start();
		}
		
	    }catch(Exception e){
		System.out.println("Un probleme survenu");
	    }
	}
    }

    class ServProdService implements Runnable{
	Socket socket;
	public ServProdService(Socket s){
	    socket = s;
	}
	
	public void run(){
	    try{

		BufferedReader pin = new BufferedReader( new InputStreamReader(socket.getInputStream()) );
		PrintWriter    pout= new PrintWriter( new OutputStreamWriter( socket.getOutputStream()  ) );
	    
		pout.println("Bienvenue Producteur");
		pout.flush();
	    
		while(true){
		    String result = pin.readLine();
		    list.add(result);
		    pout.println("Bien recu");
		    pout.flush();
		}
		
	    }catch(Exception e){
		System.out.println("Un producteur parti");
	    }
	}
    }

    class ServConsService implements Runnable{
	Socket socket;
	public ServConsService(Socket s){
	    socket = s;
	}

	public void run(){
	    try{
		
		BufferedReader pin = new BufferedReader( new InputStreamReader(socket.getInputStream()) );
		PrintWriter    pout= new PrintWriter( new OutputStreamWriter( socket.getOutputStream()  ) );

		pout.println("Bienvenue Consomateur");
		pout.flush();
		int i =0;
		while(true){
		    Thread.sleep(1000);
		    if(list.size() > i){
			pout.println(list.get(i));
			pout.flush();
			i++;
		    }
		}
		
	    }catch(Exception e){
		//System.out.println("Un consommateur parti");
	    }
	}
    }

    public static void main(String argv[]){
	new ServS();
    }
}
