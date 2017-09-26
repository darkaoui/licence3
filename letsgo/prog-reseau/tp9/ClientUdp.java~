import java.net.*;
import java.io.*;
import java.util.*;

public class ServerUdp{
    public static void main(String argv[]){
	try{
	    DatagramSocket serv = new DatagramSocket(2222);
	    System.out.println("Server start..");
	
	    byte data[] = new byte[1024];
	    DatagramPacket paquet= new DatagramPacket(data,data.length);
	    serv.receive(paquet);

	    //DatagramPacket paquet1 = new DatagramPacket(paquet.getData(),paquet.getLength());
	    serv.send(paquet);
	
		String msg = new String(paquet.getData(),0,paquet.getLength());

	    System.out.println(paquet.getAddress()+":"+paquet.getPort()+" "+msg);
	}catch(Exception e){
	    System.out.println("Probleme");
	}
    }
}
