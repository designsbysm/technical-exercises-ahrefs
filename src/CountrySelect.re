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
    Js.Dict.set(obj, "Option", <Components.Option />);

    Obj.magic(obj);
  };

  let target =
    <Components.CountrySelect.Button
      selected
      onClick={_ => setIsOpen(prev => !prev)}
    />;

  <div className>
    <Bindings.ReactSelect.Select
      onChange={selected => {
        setSelected(_ => selected |> Option.some);
        selected |> onChange;
      }}
      options={countries |> Array.of_list}
      placeholder="Search..."
      value=selected
    />
    <Components.CountrySelect.Dropdown
      isOpen onClose={_ => setIsOpen(_ => false)} target>
      <Bindings.ReactSelect.Select
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
    </Components.CountrySelect.Dropdown>
  </div>;
};
