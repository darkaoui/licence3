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

let rec rotation_d l = match l with
  |[]  -> []
  |[a] -> [a]
  |a::t-> match rotation_d t with
          |a'::t' -> a'::a::t'
          |[]-> failwith "impossible"
;;

rotation_d [1;2;3;4];;
  
let rec moyenne l =
  let rec sum l s n = match l with
    |[]    -> 0,0
    |[a]   -> a+s,n+1
    |a::t  -> sum t (s+a) (n+1)
  in
  let a,b = (sum l 0 0) in a/b
;;

moyenne [4;2;2;4];;

let rec nth l n = match l with
  |[]    -> failwith "liste vide"
  |a::t  -> if n=0 then a else nth t (n-1)
;;

nth [1;3;6;3] 2;;

let rec range a b =
  let rec range_bis a b =
    if a=b then [] else
      if a<b
      then (a+1)::range_bis (a+1) b else (a-1)::range_bis (a-1) b
  in
  a::range_bis a b                                                                

;;

range 2 2;;


let choose l = nth l (Random.int (length l));;

choose [1;2;3;4;5];;

let rec chooseelements l n =
  match n with
  |0 -> []
  |n -> if if(mem (choose l) l) l::chooseelements l (n-1)
;;
  
chooseelements [1;2;3;5;;7;8] 3;;

(* Exercice 2  *)

let rec insert e l=
  match l with
  |[]  -> []
  |a::t-> if a<=e then a::insert e t else e::a::t
;;

insert 5 [1;3;4;8];;

let rec sort l=
  match l with
  |[]   -> []
  |[a]  -> [a]
  |a::t -> insert a (sort t)
;;

sort [7;8;5;2;8];;

let rec mem_sorted e l=
  match l with
  |[]   -> false
  |a::t -> if a=e then true else mem_sorted e t
;;
  

let rec union_sorted l1 l2=
  match l1,l2 with
  |[],[]    -> []
  |[],[a] | [a],[] -> [a]
  |a::t,a'::t'  when a =a' -> a::union_sorted t t'
  |a::t,a'::t'  when a<a'  -> a::union_sorted t (a'::t')
  |a::t,a'::t'  when a>a'  -> a'::union_sorted (a::t) t'
  |_,a::t |a::t,_ -> a::union_sorted [] t
;;
  
  union_sorted [1;3;5] [2;5;8];;

let rec inter_sorted l1 l2= match l1,l2 with
  |[],[]    -> []
  |[],[a] | [a],[] -> []
  |a::t,a'::t'  when a =a' -> a::inter_sorted t t'
  |a::t,a'::t'  when a<a'  -> inter_sorted t (a'::t')
  |a::t,a'::t'  when a>a'  -> inter_sorted (a::t) t'
  |_,a::t |a::t,_ -> []
;;

  inter_sorted [1;3;5] [2;5;8];;

let rec f g ls x=
  match ls with
  |[] -> x
  |h::t -> g (f g t x) h
;;
  
