[@react.component]
let make =
    (
      ~className: string,
      ~country as defaultCountry: option(string),
      ~onChange: Types.Country.t => unit,
    ) => {
  let (countries, setCountries) = React.useState(() => []);
  let (selected, setSelected) = React.useState(() => None);
  let (isOpen, setIsOpen) = React.useState(() => false);

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

  let components = {
    let obj = Js.Dict.empty();

    Js.Dict.set(obj, "DropdownIndicator", React.null);
    Js.Dict.set(obj, "IndicatorSeparator", React.null);
    Js.Dict.set(obj, "Option", <Components.Option />);

    Obj.magic(obj);
  };

  let target =
    <Components.Button selected onClick={_ => setIsOpen(prev => !prev)} />;

  <div className>
    <Components.Select
      onChange={selected => {
        setSelected(_ => selected |> Option.some);
        selected |> onChange;
      }}
      options={countries |> Array.of_list}
      placeholder="Search..."
      value=selected
    />
    <Components.Dropdown isOpen onClose={_ => setIsOpen(_ => false)} target>
      <Components.Select
        autoFocus=true
        components
        // backspaceRemovesValue=false
        controlShouldRenderValue=false
        // hideSelectedOptions=false
        // isClearable=false
        menuIsOpen=true
        onChange={selected => {
          setSelected(_ => selected |> Option.some);
          setIsOpen(_ => false);
          selected |> onChange;
        }}
        options={countries |> Array.of_list}
        placeholder="Search..."
        // unstyled=true
        value=selected
      />
    </Components.Dropdown>
  </div>;
};
