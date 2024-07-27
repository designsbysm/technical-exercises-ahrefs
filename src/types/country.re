type t = {
  amount: float,
  label: string,
  value: string,
};

let decodeField = (~label, dict) =>
  label
  |> Js.Dict.get(dict)
  |> Option.map(Js.Json.decodeString)
  |> Option.join;

let fromJson = json =>
  json
  |> Js.Json.decodeObject
  |> (
    fun
    | Some(dict) => {
        let label = dict |> decodeField(~label="label");
        let value = dict |> decodeField(~label="value");
        let amount = Amount.mockAmount();

        switch (label, value) {
        | (Some(label), Some(value)) => Some({amount, label, value})
        | _ => None
        };
      }
    | None => None
  );
