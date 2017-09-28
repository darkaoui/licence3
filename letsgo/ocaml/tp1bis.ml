let rec pasA n =
  if n=0 then 0 else 1+pasB (n-1)
and pasB n = if n=0 then 0 else let nbis = if n mod 2 = 0 then n-2 else n-1
              in 1+pasA nbis;;
  pasA 11;;

let rec ack m n = match m,n with
  |0,n -> n+1
  |m,0 -> ack (m-1) 1
  |m,n -> ack (m-1) (ack m (n-1));;

  ack 1 1;;
  ack 2 2;;
