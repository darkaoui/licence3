/(* exercice 1 *)

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
  | Nil         -> []
  | Node(n,g,d) -> (elements g)@[n]@(elements d)
;;

elements n;;

  (* exercice 2  *)

let rec contient_abr e a= match a with
  |Nil         -> false
  |Node(n,g,d) -> n = e || contient_abr e g || contient_abr e d;;

contient_abr 5 n;;
contient_abr 9 n;;

let rec ajout_abr e a = match a with
  |Nil                  -> Node(e,Nil,Nil)
  |Node(n,g,d) when e=n -> a
  |Node(n,g,d) when e<n -> Node(n,ajout_abr e g,d)
  |Node(n,g,d) -> Node(n,g,ajout_abr e d)           
;;

let abr = Node(42,Node(10,Nil,Node(39,Nil,Nil)),Nil);;
ajout_abr 9 abr;;

let cons_abr l =
  let rec cons a l= match l with
  |[]   -> a
  |b::t -> cons (ajout_abr b a) t
  in cons Nil l
;;
  
  elements (cons_abr [1;2;7;6]);;
  hauteur (cons_abr [1;2;7;6]);;

let cons_abr_opt l=
  let rec


let est_abr a =
  let rec l_triee l = match l with
    |[]        -> true
    |[t]       -> true
    |t1::t2::q -> if(t1<=t2) then l_triee (t2::q) else false
  in
  l_triee (elements a)
;;

est_abr n;;

(* exercice 3  *)
  

type float_tree =
  | Nil
  | Node of float*int_tree*int_tree
;;

type color = Rouge|Blanc|Noir;;
  
type color_tree = color*color_tree*color_tree;;

  
type joker = Joker1|Joker2;;

type color = TREFLE|CARREAU|COEUR|PIQUE;;

type valeur= 1|..|10|Valet|Dame|Roi;;

type carte =
  |Joker1|joker2
  |color*valeur
;;

