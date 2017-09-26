let rec list_produit l = match l with
    []   -> 1
  | h::t -> h*list_produit t
;;

list_produit [2;2;2]
;;

let rec is_sorted l =
  let rec croissant = function
      []  -> true
    | [h] -> true
    | h1::h2::t -> h1<=h2 && croissant (h2::t)
  in
  let rec dcroissant = function
      []  -> true
    | [h] -> true
    | h1::h2::t -> h1>=h2 && dcroissant (h2::t)
  in
    croissant l || dcroissant l                     
;;

is_sorted [2;9;4;7;8];;
is_sorted [5;6;7;9;20];; 

let rec rotation_d  l=
  let rec rotation l1 l2 = match l1 with
      []  -> l2
    | [h] -> rotation [] (h::l2)
    | h::t-> rotation t (l2@[h])
  in
  rotation l [];;

rotation_d [2;3;5;8;9];; 
    
