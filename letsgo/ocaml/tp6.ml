type 'a stack = 'a list ref;;

exception Empty_stack;;
  
let create (): 'a stack = ref [];;

let empty (s:'a stack) = !s=[];;

let pop (s: 'a stack) = match !s with
  | []   -> raise Empty_stack
  | h::t -> s:=t; h
;;

let peek (s: 'a stack) = match !s with
  | []   -> raise Empty_stack
  | h::t -> h
;;

let  push e (s: 'a stack)  = s:= e::(!s)
;;

let is_equal (s1: 'a stack) s2 = !s1 = !s2
;;

let clone (s: 'a stack) : 'a stack = ref (!s)
;;
  
let t1 = let t = create() in push 3 t; push 4 t; t;;
let t2 = let t = create() in push 3 t; push 4 t; push 1 t; t;;

is_equal t1 t2;;
is_equal t1 t1;;
    
let _ = pop t2 in is_equal t1 t2;;

let t3 =  clone t2;;

is_equal t2 t3;;

let _ = pop t2 in is_equal t2 t3;;

let pop_n n s =
  for i=1 to n do
    pop s
  done; s

type 'a slllist =
  { mutable first: 'a sllelement option;
    mutable last : 'a sllelement option
  }
 and 'a sllelement =
   {
     value : 'a;
     mutable next : 'a sllelement option
   }
;;

let create_sll() =
  { first = None;
    last  = None
  }
;;

let app_sll e l =
  let c = {value = e; next = l.first} in
  l.first <- Some c;
  match l.last with
    None -> l.last <- Some c; l
  | _    -> l
;;

let head_sll l = match l.first with
    None  -> failwith "empty list"
  | Some a  -> a.value
;;

let tail_sll l = match l.first with
    None  -> failwith "empty list"
  | Some a -> l.first <- a.next; l
;;

let is_equal l1 l2 =
  let rec aux e1 e2 =
    match (e1,e2) with
      None,None -> true
    | (Some f1, Some f2) -> f1.value = f2.value && aux f1.next f2.next
    | _,_                -> false
  in aux l1.first l2.first
;;

  
let map f l1 =
  let l2 = create_sll() in
  let rec aux f e =
    match e with
      None -> l2
    | Some e-> app_sll (f e.value) (aux f e.next)
  in aux f l1.first
;;

  
let from_list l =
  let l1 = create_sll() in
  let rec aux l=
    match l with
      [] -> l1
    | h::t -> let l = aux t in app_sll h l
  in aux l
;;

  
let to_list l=
  let rec aux e =
    match e with
      None -> []
    | Some e1 -> e1.value::(aux e1.next) in
  aux l.first
;;
  

