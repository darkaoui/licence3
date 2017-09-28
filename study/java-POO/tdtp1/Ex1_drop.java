import java.util.Scanner;
import java.util.Arrays;
 
public class Ex1_drop{

    static String[] lireChaines(){
	String list[] = new String[10];
	Scanner sc = new Scanner(System.in);
	int n=10;
	while(n != 0){
	    System.out.print("Entrez une valeur: ");
	    list[n-1] = sc.nextLine();
	    n--;
	}

	return list;
    }

    static void enMajuscules(String tab[]){
	for(int i=0;i<tab.length; i++){
	    tab[i] = tab[i].toUpperCase();
	}
    }

    static void affiche(String tab[]){
	for(String ch: tab){
	    System.out.println(ch);
	}
    }


    public static void main(String args[]){
	String l[] = null;
	l = lireChaines();
	enMajuscules(l);
	Arrays.sort(l);
	affiche(l);
    }
}
