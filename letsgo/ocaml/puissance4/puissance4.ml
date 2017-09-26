(* #load "graphics.cma";; *)
#load "graphics.cma";
open Graphics;;

type player  = Red  | Yellow;;
type cell    = Empty | Pawn of player;;
type outcome = Win of player | Draw | Open;;
type board   = cell array array;;
type state   = Play | Two_players | One_player | Choose | Quit;;

(* nombre de jetons alignes necessaires pour gagner -
   cette constante devrait etre passee en parametre
   aux fonctions ci-dessous *)

let k_max = 4;;

(* les fonctions play et eval ne dependent plus des 
   dimensions choisies pour le plateau, mais le code
   qui les suit reste du code ad-hoc *)
let play (b : board) (p : player) c =
  let i  = ref 0 in
  let lb = Array.length b in
  while !i + 1 < lb && b.(!i + 1).(c) = Empty do
    i := !i + 1
  done;
  b.(!i).(c) <- Pawn p;
  !i
;;
	    
let eval (b : board) =
  let res = ref Open in
  let check i_min i_max j_max dir =
    for i = i_min to i_max do
      for j = 0 to j_max do
	let r = 
          match b.(i).(j) with
	    Empty -> Open
	  | Pawn p ->
	     let rec aux k (i, j) =
	       if k = k_max then Win p
	       else
		 if b.(i).(j) <> Pawn p
		 then Open
		 else aux (k + 1) (dir (i, j))
	     in aux 1 (dir (i, j)) in
	if r <> Open
	then res := r
      done
    done in
  let ph = Array.length b - 1
  and pw = Array.length b.(0) - 1
  and pk = k_max - 1 in
  let checks =
    [ 0,  pk, 0,  1, 0; (* S  *)
      0,  0,  pk, 0, 1; (* E  *)
      0,  pk, pk, 1, 1; (* SE *)
      pk, 0,  pk,-1, 1  (* NE *)
    ] in
  List.iter
    (fun (i_min, oi, oj, di, dj) ->
      if !res = Open then
	let dir = fun (i, j) -> (i + di, j + dj) in
	check i_min (ph - oi) (pw - oj) dir)
    checks;
  if !res = Open then
    begin
      res := Draw;
      for j = 0 to pw do
      if b.(0).(j) = Empty
      then res := Open
    done;
    end;
  !res
;;

let rec strategie_2_ans b p =
  let j = Random.int 7 in 
  if b.(0).(j) = Empty
  then (play b p j, j)
  else strategie_2_ans b p
;;

(* choix de la couleur associee a chaque joueur *)
let set_player_color p = 
  set_color
    (if p = Red
     then red
     else yellow)
;;

(* affichage du damier vide *)
let draw_empty_board () =
  clear_graph();
  set_color (rgb 80 80 255);
  fill_rect 20 200 560 480;
  set_color white;
  for i = 0 to 6 do
    let x = 60 + i * 80 in
    for j = 0 to 7 do
      let y = 240 + j * 80 in
      fill_circle x y 30
    done
  done
;;

(* affichage d'un pion *)
let draw_symbol i j p =
  set_player_color p;
  let x =  60 + j * 80
  and y = 240 + (5 - i) * 80 in 
  fill_circle x y 30
;;

(* effacement de la partie inferieur de la fenetre *)
let clear_bottom () =
  set_color white;
  fill_rect 0 0 600 200
;;

(* simulation d'un composant bouton/label *)
type button = {
  x : int;
  y : int;
  w : int;
  h : int;
  l : string;
  in_bounds : int -> int -> bool;
  draw : unit -> unit
};;

(* simulation d'un constructeur de composamt *)
let new_button x y w h framed l =
  let in_bounds xe ye =
    x <= xe && xe <= x + w &&
      y <= ye && ye <= y + h
  and draw () =
    if framed
    then draw_rect x y w h;
    if l <> "" then
      begin
	let wt, ht = text_size l in
	let xt, yt =
	  x + (w - wt)/2,
	  y + (h - ht)/2 in
	moveto xt yt;
	draw_string l
      end in
  { x = x; y = y;
    w = w; h = h;
    l = l;
    in_bounds = in_bounds;
    draw = draw
  }
;;

(* ecran de demarrage *)
let start_game =
  let b2 =
    new_button 100 400 400 100 true "Deux joueurs" in
  let b1 =
    new_button 100 250 400 100 true "Un joueur" in
  fun () ->
    clear_graph();
    b1.draw();
    b2.draw();
    let choice = ref Play in
    while !choice = Play do
      let e = wait_next_event[Button_down] in
      let x = e.mouse_x
      and y = e.mouse_y in
      if b1.in_bounds x y then choice := One_player;
      if b2.in_bounds x y then choice := Two_players;
    done;
    !choice
;;

(* attente du coup suivant *)
let next_move =
  let b_red =
    new_button 100 100 400 100 false
      "Joueur Rouge"
  and b_yellow =
    new_button 100 100 400 100 false
      "Joueur Jaune"
  and b_play =
    new_button 100 0 400 100 false
      "Cliquez sur une colonne non pleine"
  and b_columns =
    let t = Array.make 7
      (new_button 0 0 0 0 false "") in
    for i = 0 to 6 do
      t.(i) <-
	new_button (20 + i * 80) 200 80 480
	false ""
    done; t in
  fun b p ->
    clear_bottom();
    set_color black;
    (if p = Red then b_red else b_yellow).draw();
    b_play.draw();
    let c = ref (-1) in
    while (!c < 0) do
      let e = wait_next_event[Button_down] in
      let x = e.mouse_x
      and y = e.mouse_y in
      for j = 0 to 6 do
	if b_columns.(j).in_bounds x y &&
	  b.(0).(j) = Empty
	then c := j;
      done
    done;
    !c
;;

(* gestion de la fin du jeu *)
let rec end_of_game =
  let win_red =
    new_button 100 100 400 100 false
      "Le joueur Rouge gagne !"
  and win_yellow =
    new_button 100 100 400 100 false
      "Le joueur Jaune gagne !"
  and no_winner =
    new_button 100 100 400 100 false
      "Match nul !"
  and b_quit =
    new_button 20 20 260 100 true
      "Terminer"
  and b_replay =
    new_button 320 20 260 100 true
      "Rejouer" in
  fun (o : outcome) ->
    clear_bottom();
    set_color black;
    begin
      match o with
	Draw          ->  no_winner.draw()
      | Win (Red)     ->  win_red.draw()
      | Win (Yellow)  ->  win_yellow.draw()
      | _-> ()
    end;
    b_quit.draw();
    b_replay.draw();
    let c = ref Choose in
    while (!c = Choose) do
      let e = wait_next_event[Button_down] in
      let x = e.mouse_x
      and y = e.mouse_y in
      if b_quit.in_bounds x y   then c := Quit;
      if b_replay.in_bounds x y then c := Play; 
    done;
    !c
;;

(* fonction principale *)
let _ =
  open_graph(" 600x700");
  set_window_title("Puissance 4");
  let state = ref Play in
  while (!state <> Quit) do
    state := start_game ();
    draw_empty_board();
    let b = Array.make_matrix 6 7 Empty  
    and p = ref Red  
    and o = ref Open in
    while !o = Open do
      set_player_color !p;
      let i, j =
	if !state = Two_players ||
	  (!state = One_player && !p = Red) then
	  let jq = next_move b (!p) in
	  let iq = play b !p jq in
	  iq, jq
	else strategie_2_ans b !p in
      draw_symbol i j !p;
      p := if !p = Red then Yellow else Red;
      o := eval b
    done;
    state := end_of_game !o
  done;
  close_graph();
;;
