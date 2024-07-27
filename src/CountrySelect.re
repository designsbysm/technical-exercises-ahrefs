type components = {children: React.element};

[@react.component]
let make = (~className, ~country as defaultCountry, ~onChange) => {
  let (selected, setSelected) = React.useState(() => None);
  let (isOpen, setIsOpen) = React.useState(() => false);

  let countries = Fetch.countries();
  let countries =
    React.useMemo1(
      () =>
        countries
        |> List.sort((a: Types.Country.t, b: Types.Country.t) =>
             b.amount -. a.amount |> int_of_float
           ),
      [|countries|],
    );

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

    Js.Dict.set(obj, "Control", ({children}) =>
      <Components.CountrySelect.Control>
        children
      </Components.CountrySelect.Control>
    );
    Js.Dict.set(obj, "DropdownIndicator", _ => React.null);
    // Js.Dict.set(obj, "DropdownIndicator", _ => <Icons.Search />);
    Js.Dict.set(obj, "IndicatorSeparator", _ => React.null);

    Obj.magic(obj);
  };

  let target =
    <Components.CountrySelect.Button onClick={_ => setIsOpen(prev => !prev)}>
      {selected
       |> (
         fun
         | Some({label, value, _}) =>
           <Components.CountrySelect.Country label value />
         | None => "Select a Country" |> React.string
       )}
    </Components.CountrySelect.Button>;

  <Components.CountrySelect.Dropdown
    className isOpen onClose={_ => setIsOpen(_ => false)} target>
    <Components.CountrySelect.Select
      autoFocus=true
      components
      // backspaceRemovesValue=false
      controlShouldRenderValue=false
      // hideSelectedOptions=false
      // isClearable=false
      formatOptionLabel={({amount, label, value}: Types.Country.t) =>
        <Components.CountrySelect.Country amount label value />
      }
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
  </Components.CountrySelect.Dropdown>;
};
