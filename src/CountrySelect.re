[@react.component]
let make =
    (
      ~className: string,
      ~country as defaultCountry: option(string),
      ~onChange: Types.Country.t => unit,
    ) => {
  let (selected, setSelected) = React.useState(() => None);
  let (isOpen, setIsOpen) = React.useState(() => false);
  let countries = Fetch.countries();

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
    // Js.Dict.set(obj, "Option", <Components.Option />);

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
