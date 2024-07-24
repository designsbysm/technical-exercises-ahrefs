[@react.component]
let make =
    (
      ~className: string,
      ~country as defaultCountry: option(string),
      ~onChange: Types.Country.t => unit,
    ) => {
  let initialCountries: list(Types.Country.t) = [];
  let (countries, setCountries) = React.useState(() => initialCountries);
  let (selected, setSelected) = React.useState(() => None);

  React.useEffect0(() => {
    Js.Promise.(
      Bindings.Fetch.fetch(
        "https://gist.githubusercontent.com/rusty-key/659db3f4566df459bd59c8a53dc9f71f/raw/4127f9550ef063121c564025f6d27dceeb279623/counties.json",
      )
      |> then_(Bindings.Fetch.Response.json)
      |> then_(json => json |> Js.Json.decodeArray |> resolve)
      |> then_(opt => opt |> Belt.Option.getExn |> resolve)
      |> then_(items => {
           items
           |> Array.map(item =>
                item |> Types.Country.fromJson |> Belt.Option.getExn
              )
           |> Array.to_list
           |> resolve
         })
      |> then_(items => {
           let countries =
             items
             |> List.sort((a: Types.Country.t, b: Types.Country.t) => {
                  b.amount -. a.amount |> int_of_float
                });
           setCountries(_ => countries);
           countries |> resolve;
         })
    )
    |> ignore;

    None;
  });

  React.useEffect2(
    () => {
      defaultCountry
      |> (
        fun
        | Some(value) => {
            let match = Belt.List.getBy(countries, c => c.value == value);
            setSelected(_ => match);
          }
        | None => ()
      );

      None;
    },
    (countries, defaultCountry),
  );

  // [ ] move onChange
  selected
  |> (
    fun
    | Some(country) => country |> onChange
    | None => ()
  )
  |> ignore;

  // [ ] add react-select
  <div className>
    {React.string("Selected: ")}
    {selected
     |> (
       fun
       | Some({amount, label, _}) =>
         label ++ ": " ++ (amount |> Types.Amount.formatInKs)
       | None => "none"
     )
     |> React.string}
    {countries
     |> List.map(({amount, label, value}: Types.Country.t) => {
          <p key=value>
            {label |> React.string}
            {": " |> React.string}
            {amount |> Types.Amount.formatInKs |> React.string}
          </p>
        })
     |> Array.of_list
     |> React.array}
  </div>;
};
