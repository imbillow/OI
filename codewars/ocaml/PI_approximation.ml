let pi = 4.0 *. (atan 1.0)
let rnd10 x =
  (x *. 1E10 |> int_of_float |> float_of_int) /. 1E10

let rec iter x i epsilon =
  if abs_float (4. *. x -. pi) < epsilon
  then (i,4.*.x |> rnd10)
  else iter (x +. (-1. ** float_of_int i) /. (2. *. float_of_int i +. 1.)) (i+1) epsilon

let iter_pi epsilon =
  iter 0. 0 epsilon
