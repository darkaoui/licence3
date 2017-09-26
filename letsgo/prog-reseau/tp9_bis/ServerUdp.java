import java.net.*;
import java.io.*;
import java.util.*;

public class ServerUdp{
    public static void main(String argv[]){
	try{
	    DatagramSocket serv = new DatagramSocket(2222);
	    System.out.println("Server start..");

	    ArrayList<InetSocketAddress> address = new ArrayList<InetSocketAddress>();
	
	    byte data[] = new byte[1024];

	    while(true){
		
		DatagramPacket paquet= new DatagramPacket(data,data.length);
		serv.receive(paquet);

		if(!address.contains((InetSocketAddress)paquet.getSocketAddress()))
		    address.add((InetSocketAddress)paquet.getSocketAddress());
	       
	    
		String msg = new String(paquet.getData(),0,paquet.getLength());
		System.out.println(paquet.getAddress()+":"+paquet.getPort()+" "+msg);
	    

		for(int i=0; i<address.size(); i++){
		    DatagramPacket paq = new DatagramPacket(paquet.getData(),paquet.getLength(),address.get(i));
		    serv.send(paq);
		}

	    }
	
	}catch(Exception e){
	    System.out.println(e.getMessage());
	}
    }
}
