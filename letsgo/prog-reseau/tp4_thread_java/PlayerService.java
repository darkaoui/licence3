import java.util.*;
import java.net.*;
import java.io.*;
import java.lang.*;


public class PlayerService implements Runnable{

    private Socket socket;
    //-2 trouve
    private SharedValue shared;
    private int rand;

    public PlayerService(Socket s){
	socket = s;
	shared = null;
    }

    public PlayerService(Socket s, SharedValue v){
	socket = s;
	shared = v;
    }

    public void run(){
	
	try{
	    while(true){

		int nb = -1;

		BufferedReader pin = new BufferedReader(new InputStreamReader(socket.getInputStream()));
		PrintWriter   pout = new PrintWriter(new OutputStreamWriter(socket.getOutputStream()));

		//Generer un nombre
		if(shared == null){
		   Random rand = new Random();
		   nb = rand.nextInt(101);
		}

		pout.print("Deviner le nombre entre 0 et 100\n");
		pout.flush();

		String r;
		while(true){
		    
		    r = pin.readLine();

		    if(r == null){
			System.out.println("Un client est parti");
			return;
		    }

		    try{

			int n = Integer.parseInt(r);

			String result;

			    if(shared == null){

				if(n == nb)
				     result = "Egal";
				 else if(n>nb)
				     result = "Moins";
				 else
				     result = "Plus";

				 pout.println(result);
				 pout.flush();

			    }else{

				if(shared.finded == true){
				    pout.println(".La valeur a ete deja trouve "+shared.value);
				    pout.flush();
				}

				synchronized(shared){

				    if(n == shared.value)
					result = "Egal";
				    else if(n>shared.value)
					result = "Moins";
				    else
					result = "Plus";

				    pout.println(result);
				    pout.flush();

				    if(result.equals("Egal"))
					shared.finded = true;
				}
			    }

			    if(result.equals("Egal")){
				System.out.println("Valeur trouvee par un client");
				break;
			    }

		    }catch(Exception e){
			pout.println("Entre un valeur valide");
			pout.flush();
		    }
		}

		if(socket != null)
		  socket.close();
	    }

	    //s.close();

	    //System.out.println("See you later");
	    
	}catch(Exception e){
	    System.out.println("Communication Terminer ou Probleme");
	}
    }
}
