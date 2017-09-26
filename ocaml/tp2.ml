let rec last l = match l with
  |[]    -> failwith "liste vide"
  |a::[] -> a
  |a::t  -> last t
;;
  

let rotation_d l=
  let rec rotation l1= match l1 with
    |a::[] -> []
    |a::t  -> a::rotation t
  in
  rev (rotation l 0)
;;

rotation_d [1;2;3;4];;

      