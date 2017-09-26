import java.io.*;
import java.net.*;

public class Ports{
    public static void main(String argv[]){

	System.out.println("nb arg "+argv[0]);

	if(argv.length == 3){
	    
	    int dep = Integer.parseInt(argv[0]);
	    int ari = Integer.parseInt(argv[1]);
	    String host = argv[2];

	    if(dep > ari){
		System.out.println("parametres non valide");
		return;
	    }

	    for(int i=dep; i<ari; i++){
		try{
		    Socket s = new Socket(host,i);
		    System.out.println("Ports ouverts "+i);
		    s.close();
		}catch(Exception e){
		    //   System.out.println("---------------");
		}
	    }
	    
	}else
	    System.out.println("parametres non valide");
    }
}
