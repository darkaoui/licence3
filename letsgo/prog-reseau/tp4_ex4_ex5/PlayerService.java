import java.util.*;
import java.net.*;
import java.io.*;
import java.lang.*;


public class PlayerService implements Runnable{

    private Socket socket;
    //-2 trouve
    private Game game;
    private int rand;

    public PlayerService(Socket s){
	socket = s;
	game = null;
    }

    public PlayerService(Socket s, Game g){
	socket = s;
	game = g;
    }

    public void run(){
	
	try{
	    while(true){

		int nb = -1;

		BufferedReader pin = new BufferedReader(new InputStreamReader(socket.getInputStream()));
		PrintWriter   pout = new PrintWriter(new OutputStreamWriter(socket.getOutputStream()));

		//Generer un nombre
		if(game == null){
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

			    if(game == null){

				if(n == nb)
				     result = "Egal";
				 else if(n>nb)
				     result = "Moins";
				 else
				     result = "Plus";

				 pout.println(result);
				 pout.flush();

			    }else{

				if(game.finded == true){
				    pout.println(".La valeur a ete deja trouve "+game.value);
				    pout.flush();
				}

				synchronized(game){

				    if(n == game.value)
					result = "Egal";
				    else if(n>game.value)
					result = "Moins";
				    else
					result = "Plus";

				    pout.println(result);
				    pout.flush();

				    if(result.equals("Egal"))
					game.finded = true;
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
