[@mel.deriving accessors]
type key =
  | ArrowDown
  | ArrowUp
  | Escape
  | PageDown
  | PageUp;

let fromString =
  fun
  | "ArrowUp" => ArrowUp |> Option.some
  | "ArrowDown" => ArrowDown |> Option.some
  | "Escape" => Escape |> Option.some
  | "PageDown" => PageDown |> Option.some
  | "PageUp" => PageUp |> Option.some
  | _ => None;

let getKey = e => e |> React.Event.Keyboard.key |> fromString;
