import java.net.*;
import java.io.*;
import java.util.*;

public class ClientUdp{
    public static void main(String argv[]){
	try{
	    DatagramSocket serv = new DatagramSocket();
	    System.out.println("Client start..\nenvoyer: ");
	    Scanner sc = new Scanner(System.in);

	    String msg = sc.nextLine();
	    
	    DatagramPacket paquet= new DatagramPacket(msg.getBytes(),msg.getBytes().length,
						      InetAddress.getByName("localhost"),2222);

	    //DatagramPacket paquet1 = new DatagramPacket(paquet.getData(),paquet.getLength());
	    serv.send(paquet);
	    serv.receive(paquet);
	
	    msg = new String(paquet.getData(),0,paquet.getLength());
	    System.out.println("recu: "+msg);
	     
	}catch(Exception e){
	    System.out.println("Probleme");
	}
    }
}
