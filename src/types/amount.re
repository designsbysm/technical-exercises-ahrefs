let convertToThousands = value => value /. 1000.0;

let formatInKs = value => (value |> Js.Float.toFixed(~digits=1)) ++ "K";

let getRandomBetween = (min, max) => Js.Math.random() *. (max -. min) +. min;

let reduceDigits = value =>
  value |> Js.Float.toFixed(~digits=4) |> Js.Float.fromString;

let mockAmount = () =>
  getRandomBetween(1_000., 300_000.) |> convertToThousands |> reduceDigits;
