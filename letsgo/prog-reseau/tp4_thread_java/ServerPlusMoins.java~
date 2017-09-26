import java.net.*;
import java.io.*;
import java.util.*;


public class ServerPlusMoins{

    public static void main(String argv[]){
	try{
	    
	    ServerSocket s = new ServerSocket(2222);

	    System.out.println("Port:"+s.getLocalPort()+" Address:"+s.getLocalSocketAddress().toString());
	    while(true){
		
		Socket c = s.accept();

		BufferedReader pin = new BufferedReader(new InputStreamReader(c.getInputStream()));
		PrintWriter   pout = new PrintWriter(new OutputStreamWriter(c.getOutputStream()));

		//Generer un nombre
		Random rand = new Random();
		int nb = rand.nextInt(101);

		pout.print("Deviner le nombre entre 0 et 100\n");
		pout.flush();

		String r = "";
		while(true){
		    
		    r = pin.readLine();

		    if(r == null){
			c.close();
			break;
		    }

		    try{

			int n = Integer.parseInt(r);

			String result;

			if(n == nb)
			    result = "Egal";
			else if(n>nb)
			    result = "Moins";
			else
			    result = "Plus";

			pout.println(result);
			pout.flush();

			if(result.equals("Egal"))
			    break;

		    }catch(Exception e){
			pout.println("Entre un valeur valide");
			pout.flush();
		    }
		}
	    }

	    //s.close();

	    //System.out.println("See you later");
	    
	}catch(Exception e){
	    System.out.println("Communication Terminer");
	}
    }
}
