(* exercice 1 *)

type int_tree =
  | Nil
  | Node of int*int_tree*int_tree
;;

Nil;;
let n = Node(12,Node(3,Node(5,Nil,Nil),Node(4,Nil,Nil)),Nil);;

let rec taille a= match a with
  | Nil        -> 0
  | Node(n,g,d)-> 1 + taille g + taille d;;

taille n;;

let rec hauteur a= match a with
  | Nil             -> 0
  | Node(n,g,d)     -> 1 + max (hauteur g) (hauteur d) 
;;

hauteur n;;

let rec somme a= match a with
  | Nil         -> 0
  | Node(n,g,d) -> n + somme g + somme d
;;

somme n;;

let rec elements a= match a with
  | Nil -> []
  | Node(n,g,d) -> match elements g with
                   |[]   -> elements d
                   |a::t -> n::a::t
;;

elements n;;

  (* exercice 2  *)

let rec contient_abr e a= match a with
  |Nil         -> false
  |Node(n,g,d) -> n = e || contient_abr e g || contient_abr e d;;

contient_abr 5 n;;
contient_abr 9 n;;

let rec ajout_abr e a = match a with
  |Nil             -> Node(e,Nil,Nil)
  |Node(n,g,d)     -> Node(n,ajout_abr e g, ajout_abr e d)
;;

ajout_abr 9 n;;

let rec cons_abr l = match l with
