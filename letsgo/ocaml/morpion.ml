type joueur = Croix| Rond;;
 
type case = Vide | J of joueur;;

type line = case*case*case;;

type grille = line*line*line;;

let stringCase = function
    Vide -> " "
  | J Croix -> "X"
  | J Rond  -> "O"
;;
  
let afficheCase case  =
    print_string (stringCase case)
;;

let stringLine = fun
    (c1,c2,c3) ->"| "^(stringCase c1)^" | "^(stringCase c2)^" | "^(stringCase c3)^" |\n";;

let afficheLine x = print_string (stringLine x);; 

let afficheGrille = function
    (l1,l2,l3) ->
    print_string "\n     a   b   c\n";
    print_string "   +---+---+---+\n";
    print_string " 1 ";
    afficheLine l1;
    print_string "   +---+---+---+\n";
    print_string " 2 ";
    afficheLine l2;
    print_string "   +---+---+---+\n";
    print_string " 3 ";
    afficheLine l3;
    print_string "   +---+---+---+\n"
                                          
;;

exception MoveForbidden;;
exception NoMoreMove;;
  
(* choix1*choix2 grille joueur *)
let  move (l,c) ((l1,l2,l3):grille) (j:joueur) =
  let move_line c (c1,c2,c3) j =
    match c with
    | 'a' -> if c1=Vide then (J j, c2, c3) else raise MoveForbidden
    | 'b' -> if c2=Vide then (c1, J j, c3) else raise MoveForbidden
    | 'c' -> if c3=Vide then (c1, c2, J j)  else raise MoveForbidden
    |  _  -> raise MoveForbidden
  in match l with
     | 1 -> (move_line c l1 j,l2,l3)
     | 2 -> (l1,move_line c l2 j,l3)
     | 3 -> (l1,l2,move_line c l3 j)
     | _ -> raise MoveForbidden
;;
  
let aVide ((l1,l2,l3):grille) =
  let aVide_line (c1,c2,c3) = c1=Vide||c2=Vide||c3=Vide in
  aVide_line l1 || aVide_line l2 || aVide_line l3
;;

let gagne (( (c1,c2,c3),(c4,c5,c6),(c7,c8,c9) ):grille) =
  match c1 with
  | J j when (c1=c2 && c2=c3) || (c1=c4 && c4=c7) || (c1=c5 && c5=c9) -> J j
  |  _ ->
      match c2 with
      | J j when (c2=c5 && c5=c8) ->  J j
      |  _  ->
          match c3 with
          |J j when (c3=c6 && c6=c9) || (c3=c5 && c5=c7) -> J j
          | _  ->
             match c4 with
             |J j when (c4=c5 && c5=c6) -> J j
             | _  ->
                match c7 with
                | J j when (c7=c8 && c8=c9) -> J j
                |  _ -> if aVide ( (c1,c2,c3),(c4,c5,c6),(c7,c8,c9)) then Vide
                        else raise NoMoreMove
;;

let rec read_coordonnees g j =
  try
    begin
      print_string "Line? :";
      let l=read_int() in
      print_string "Colonne? :";
      let c= (read_line()).[0] in
      move (l,c) g j
    end
  with
  | MoveForbidden -> (print_endline "Choix interdit! refaire\n"; read_coordonnees g j)
;;

let tour g j =
  afficheGrille g;
  print_string "Bonjour "; afficheCase (J j); print_newline();
  read_coordonnees g j
;;

let autre j = if j=Croix then Rond else Croix;;

let rec morpion g j=
  try
    begin
      let x = gagne g in
      match x with
      | J winner -> print_string "Bravo : "; afficheCase (J winner); print_endline " a gagne !"
      | Vide -> let g_next = (tour g j) in morpion g_next (autre j)
    end
  with
  | NoMoreMove -> print_endline ("Aucun gagnant, desole! ")
;;

let init = ((Vide,Vide,Vide),(Vide,Vide,Vide),(Vide,Vide,Vide));;

morpion init Croix;;
