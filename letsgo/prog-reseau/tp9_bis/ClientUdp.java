import java.net.*;
import java.io.*;
import java.util.*;
import java.lang.*;

public class ClientUdp{

    public class ClientRecepter implements Runnable{

	DatagramSocket gramSocket;

	public ClientRecepter(DatagramSocket sock){
	    gramSocket = sock;
	}

	public void run(){

	    System.out.println("Receveur lancer...");
	    try{
		byte[] buf = new byte[1024];
		DatagramPacket p = new DatagramPacket(buf,buf.length);
		
		while(true){
		    gramSocket.receive(p);
		    String msg = new String(p.getData(),0,p.getLength());
		    System.out.println("msg recu: "+msg);
		}
		
	    }catch(Exception e){
		System.out.println("Problem ou fin");
	    }
	}
    }

    public void run(){
	try{
	    
	    DatagramSocket sock = new DatagramSocket();
	    ClientRecepter c = new ClientRecepter(sock);
	    
	    System.out.println("Client start..\n");
	    
	    Thread t = new Thread(c);
	    t.start();
	    Scanner sc = new Scanner(System.in);

	    System.out.println("Saisir pour envoyer a tout moment:");
	    while(true){
		
		String msg = sc.nextLine();
	    
		DatagramPacket paquet= new DatagramPacket(msg.getBytes(),msg.getBytes().length,
							  InetAddress.getByName("localhost"),2222);
		sock.send(paquet);
	    } 
	}catch(Exception e){
	    System.out.println("Probleme");
	}
    }
    
    public static void main(String argv[]){
	new ClientUdp().run();
    }
}
