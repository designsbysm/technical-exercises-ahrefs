let countries = () => {
  let (countries, setCountries) = React.useState(() => []);

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

  countries;
};
