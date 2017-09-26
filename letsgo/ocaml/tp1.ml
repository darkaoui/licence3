let estnul x = match x with
  |0 -> "null"
  |_ -> "non null";;

estnul 6;;

let max_triple x y z   = max (max x y) z;;
let max_quadru x y z t = max (max_triple x y z) t;;
  max_quadru 3 6 8 1;;
let rec somme x = if x<=0 then 0 else x + somme (x-1);;
  somme 200;;
let rec fibo x = if x<=1 then 1 else fibo (x-1) + fibo (x-2);;
  fibo 50;;

let rec pasA n =
  if n=0 then 0 else 1+pasB (n-1)
and pasB n = if n=0 then 0 else let nbis = if n mod 2 = 0 then n-2 else n-1
             in 1+pasA nbis;;
