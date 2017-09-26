(* type int_tree =
  |Nil
  |Node of int*int_tree*int_tree;;
*)

let type 'a tree=
  |Nil
  |Node of 'a*'a tree*'a tree;;

let n0 = Nill;;
let n1 = Node(10,Node(2,Nil,Nil),Nil);;

let rec taille n = match n with
  |Nil -> 0
  |Node(n,g,d) -> 1+ taille g + taille d;;

let rec hauteur n = match n with
  |Nil -> 0
  |Node(n,g,d) -> 1+ max (hauteur g) (hauteur d);;

hauteur n1;;

let rec contient x n = match n with
  |Nil -> false
  |Node(n,g,d) -> x=n || (contient x g) || (contient x d);;

contient 3 n1;;

let rec somme n = match n with
  |Nil -> 0
  |Node(n,g,d) -> n + somme g + somme d;;

somme n1;;

let rec complet n = match n with
  |Nil -> true
  |Node(n,g,d) -> (hauteur g == hauteur d) && complet g && complet d;;

let n3 = Node(2,Node(3,Nil,Nil),Node(5,Nil,Nil));;
let n4 = Node(2,Node(3,Node(5,Nil,Nil),Nil),Node(5,Nil,Nil));;

complet n3;;
complet n4;;

(* Exercice 2 *)

let n5 = Node(45,Node(23,Node(12,Nil,Nil),Node(25,Nil,Nil)),Node(50,Node(46,Nil,Nil),Node(49,Nil,Nil)));;
  
let rec contient_abr x n = match n with
  |Nil -> false
  |Node(n,g,d) when x=n -> true
  |Node(n,g,d) when x<n -> contient_abr x g
  |Node(n,g,d) -> contient_abr x d
;;

let rec ajout_abr x a = match a with
  |Nil -> Node(x,Nil,Nil)
  |Node(n,g,d) when x=n -> a
  |Node(n,g,d) when x<n -> Node(n,ajout_abr x g,d)
  |Node(n,g,d) when x>n -> Node(n,g,ajout_abr x d)
;;

let v = ajout_abr 42 n5;;

let rec cons_abr l = match l with
  |[] -> Nil
  |h::t ->  ajout_abr h (cons_abr t);;

let v1 = cons_abr [2;3;5;6;7;8];;


  (* Exercices 3  *)
(*
type int_float_tree =
  |Nill
  |Node_int   of int*int_float_tree*int_float_tree
  |Node_float of float*int_float_tree*int_float_tree;;


type color=
  |Rouge
  |Blanc
  |Noir;;

  
type color_tree=
  |Nill
  |Node_rouge of color*color_tree*color_tree;;
*)
  (* Exercice 4 *)

 (*
type 'a tree=
  |Nil
  |Node of 'a*'a tree*'a tree;;
*)

(* Exo Bonus  *)
  
let rec forall_labels f t = match t with
  |Nil -> true
  |Node(a,g,d)     -> (f a) && forall_labels f g && forall_labels f d;;

let is_uniform a t = forall_labels (fun v-> v=a) t;;

is_uniform 4 n4;;
