type formule =
  |Var of string
  |Neg of formule
  |Et  of formule*formule
  |Ou  of formule*formule;;


let rec string_of_formule f = match f with
  |Var(v)     -> v
  |Neg(f)     -> "Neg"^(string_of_formule f)
  |Et(f1,f2)  -> "("^(string_of_formule f1)^" Et "^(string_of_formule f2)^")"
  |Ou(f1,f2)  -> "("^(string_of_formule f1)^" Ou "^(string_of_formule f2)^")"
;;


let f1 = Et(Var "p", Neg(Ou(Var "q",Var "r")));;

string_of_formule f1;;

let rec union l1 l2 =
  let rec content x l = match l with
      | [] -> false
      | a::t -> a=x || content x t
  in let rec uni l acc = match l with
       | [] -> acc
       | a::t -> if content a acc then uni t acc else (uni t (acc@[a]))
     in uni (l1@l2) []
;;

union [1;2;4;4] [2;6;7];;
    
let rec list_of_vars f =  match f with
  | Var(v) -> [v]
  | Neg(f) -> list_of_vars f
  | Ou(f1,f2) | Et(f1,f2) -> union (list_of_vars f1) (list_of_vars f2);;

list_of_vars f1;;

let rec eval_formule f l = match f with
  |Var s  -> List.assoc s l
  |Neg(f) -> not(eval_formule f l)
  |Et(f1,f2) -> (eval_formule f1 l) && (eval_formule f2 l)
  |Ou(f1,f2) -> (eval_formule f1 l) || (eval_formule f2 l)
;;

let rec add_to_all x l =
  let rec map x l f = match l with
    |[]   -> []
    |a::t -> (f x a)@(map x t f)
  in map x l (fun x l -> [x::l])
;;

add_to_all 3 [[3;4];[5;7]];;

let add_ x l = List.map (fun t -> t@[x]) l;;

add_ 3 [[2];[4]];;

let rec affectations_vars l = match l with
  |[]     -> [[]]
  |a::t   -> let le = affectations_vars t in
             (add_to_all (a,true) le)@(add_to_all (a,false) le)
;;

let rec affec l =
  let rec aff l' ac = match l' with
    | [] -> ac
    | a::t -> aff t ((add_ (a,true) ac)@(add_ (a,false) ac))
in aff l [[]]
;;
  
affectations_vars ["a";"b"];;
affec ["a";"b"];;

let affectations f = affectations_vars (list_of_vars f)
;;


let satisfaisable f =
  let eval l =
    eval_formule f l
  in List.exists eval (affectations f)
;;

let tautologie f =
  let eval l =
    eval_formule f l
  in List.for_all eval (affectations f)
;;

let sat = satisfaisable (Et(Var "p", Neg(Var "p")));;
let tau = tautologie (Ou(Var "p", Neg(Var "p")));;

let consequence f1 f2 =
  let rec conseq l = match l with
    |[]   -> false
    |[a]  -> if (eval_formule f1 a)=true && (eval_formule f2 a)=true then true else false
    |a::t when (eval_formule f1 a)=true -> if (eval_formule f2 a) then true else false
    |a::t -> conseq t
  in conseq (affectations f1)
;;

let equivalentes f1 f2 = (consequence f1 f2) && (consequence f2 f1)
;;

(*Correction de consequence*)
let conseq f1 f2 =
  let v1 = list_of_vars f1 and v2 = list_of_vars f2
  in let v = union v1 v2
     in let affs = affectations_vars v in
        List.for_all (fun e -> not(eval_formule f1 e) || (eval_formule f2 e )) affs
;;


(* Exercice 5 *)
let rec desc_neg f = match f with
  | Neg(Neg g)   -> desc_neg g
  | Neg(Ou(g,h)) -> Et(desc_neg(Neg g), desc_neg(Neg f))
  | Neg(Et(g,h)) -> Ou(desc_neg(Neg g), desc_neg(Neg f))
  | Ou(g,h)  -> Ou(desc_neg g, desc_neg h)
  | f -> f
;;

let rec desc_ou f = match f with
  | Et(g,h) -> Et(desc_ou g ,desc_ou h)
  | Ou(g,h) ->
     let g' = desc_ou g
     and h' = desc_ou h in
     (match g' ,h' with
        _,Et(g,h) -> Et(desc_ou (Ou(g',g)), desc_ou (Ou(g',h)) )
      | Et(f,g),_ -> Et(desc_ou (Ou(f,h')), desc_ou (Ou(g,h')) )
      | _         -> Ou (g', h'))
  |f -> f
;;
