
(* EXERCICE 1  *)
let rec l_length l = match l with
  |[]  -> 0
  |h::t-> 1+l_length t;;

let rec l_produit l = match l with
  |[]  -> 1
  |h::t-> h*l_produit t;;

let rec mem x l = match l with
  |[]   -> false
  |h::t -> h=x || mem x t;;

let rec map f l = match l with
  |[]   -> []
  |h::t -> (f h)::map f t;;

let succ x = x+1 in map succ [1;2;3];;

let rec filter f l= match l with
  |[]   ->[]
  |h::t ->if f h then h::filter f t else filter f t;;

let rec l_min l = match l with
  |[]   -> failwith "liste vide"
  |h::t -> min h (l_min t);;

let rec is_sorted l = match l with
  |[]   -> true
  |[h]  -> true
  |h1::h2::t -> h1<=h2 && is_sorted (h2::t);;

let rec append l1 l2 = match l1 with
  |[]   -> l2
  |h::t -> h::append t l2;;

append [2;4;6] [3;4;5];;

let rec last l = match l with
  |[]   -> []
  |[h]  -> h
  |h::t -> last t;;

let rec rev l =
  let rec rev_bis l1 acc = match l1 with
    |[]   -> acc
    |h::t -> rev_bis t (h::acc)
  in rev_bis l [];;

let rec rev2 l = match l with
  |[]   -> []
  |h::t -> [h]@rev2 t;;

let rec flatten l = match l with
  |[]   -> []
  |h::t -> append h (flatten t);;

let rec moyenne l =
  let rec som l1 n ac = match l1 with
    |[]   -> n,ac
    |h::t -> som t (h+n) (ac+1)
  in let s,n = som l 0 0 in s/n;;

let rec nth l n = match l with
  |[]   -> failwith "liste vide"
  |h::t -> if n=0 then h else nth t (n-1);;

let choose l = match l with
  |[]  -> failwith "liste vide"
  |_   -> let n = l_length l in let ch = Random.int n in nth l ch;;

 
choose [1;2;4;3;6;9];;

  (* EXERCICE 2 *)
let rec insert el l = match l with
  |[]   -> [el]
  |h::t when h<el -> h::(insert el t)
  |h::t when h=el -> h::t
  |h::t -> el::h::t;;

insert 2 [1;2;3;5];;

let rec sort l = match l with
  |[]   -> []
  |[h]  -> [h]
  |h::t -> insert h (sort t);;

let s = sort [5;4;3;2;1];;

  (* A corriger *)
let rec mem_sorted el l= match l with
  |[]   -> false
  |h::t -> if h=el then true else mem_sorted el t;;

let rec union_sorted l1 l2 = match l1,l2 with
  |([],[])   -> []
  | (h::t,_) -> insert h (union_sorted t l2)
  | (_,h::t)-> insert h (union_sorted t []);;

union_sorted [1;2;3] [3;4;5];;

let rec inter_sorted l1 l2 = match l1 with
  |[]   -> []
  |h::t when (mem_sorted h l2) ->  h::(inter_sorted t l2)
  |h::t -> inter_sorted t l2;;

inter_sorted [1;2;3] [];;

let rec quick_sort l = match l with
  |[]   -> []
  |[a]  -> [a]
  |h::t -> let l1,l2 =
             let rec divide h t d1 d2 = match t with
               |[]    -> d1,d2
               |a::b  when h>=a -> divide h b (a::d1) d2  
               |a::b            -> divide h b d1 (a::d2)
             in divide h t [] []
           in (quick_sort l1)@[h]@(quick_sort l2);;

quick_sort [4;56;2;3;4];;
