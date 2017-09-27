(* exercice 1*)
 
let rec length l = match l with
  |[]->0
  |a::t-> 1+length t;;

let rec list_produit l = match l with
  |[]   ->1
  |a::t -> a*(list_produit t);;

let rec mem el l = match l with
  |[]   -> false
  |a::t -> (a = el) || (mem el t);;

let rec map f l= match l with
  |[]   -> []
  |a::t -> [f(a)]@(map f t)
;;

let rec filter f l= match l with
  |[] -> []
  |a::t -> if (f a) then a::(filter f t) else filter f t;;

let rec list_min l= match l with
  |[]  -> failwith "tableau vide"
  |[a]      -> a
  |a::b::[] -> if a <= b then a else b
  |a::b::t  ->  if a <= b then list_min (a::t) else list_min (b::t);;

  list_min [2;1;3;6;-10];;

let rec is_sorted l =
  let rec compare f  l = match l with
    |[] -> false
    |[a]         -> true
    |a::b::[]    -> f a b = a 
    |a::b::t     -> if f a b = a then compare f (b::t) else false
  in
  (compare min l) || (compare max l)
;;


let rec append l1 l2  = match l1,l2 with
    _,[]       -> []
   |t,a::[]    -> t::a
   |l,a::t     -> append (l@[a]) t
;;

let rec last l = match l with
    []    -> []
   |a::[] -> a
   |a::t  -> last t
;;

let rec rev l= match l with
  |[]   -> []
  |a::t -> [a]@(rev t)
;;

let rec flatten l= match l with
  |[]   ->[]
  |a::t -> [a] @ (flatten t)
;;

let rotation_d l =
  if length l <= 2 then l
  else
    let first l = match l with
      |a::_ -> a
    in
    rotation l =
      
    ;;
  
let rec moyenne l =
  let sum l n = match l,n with
    |[],nb    ->0
    |a::t,nb  -> a+sum t  (nb+1)
  in
  let a,b = sum l 0 in a/b
;;

let rec nth l n = match l with
  |[]    -> failwith "liste vide"
  |a::t  -> if n=0 then a else nth t (n-1)
;;

let rec range n1 n2=
  if n1 > n2
	    
