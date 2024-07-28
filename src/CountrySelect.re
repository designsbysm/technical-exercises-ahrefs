type component = {
  children: array(React.element),
  maxHeight: int,
};

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

  let listRef = React.useRef(Js.Nullable.null);
  // [ ] remove
  React.useEffect1(
    () => {
      listRef |> Js.log;
      None;
    },
    [|listRef|],
  );

  let components = {
    let obj = Js.Dict.empty();

    Js.Dict.set(obj, "DropdownIndicator", _ => <Icons.Search />);
    Js.Dict.set(obj, "IndicatorSeparator", _ => React.null);
    Js.Dict.set(obj, "MenuList", ({children, maxHeight}) =>
      {
        "children": children,
        "listRef": listRef,
        "maxHeight": maxHeight,
        "selected": selected,
      }
      |> Components.CountrySelect.MenuList.make
    );

    Obj.magic(obj);
  };

  let styles: Bindings.ReactSelect.styles = {
    control: (style, _) =>
      ReactDOM.Style.combine(
        style,
        ReactDOM.Style.make(
          ~borderBottom="1px solid rgba(0, 0, 0, 0.08)",
          ~borderRadius="3px 3px 0 0",
          ~flexDirection="row-reverse",
          ~fontSize="14px",
          ~marginBottom="5px",
          ~paddingLeft="12px",
          (),
        ),
      ),
    input: (style, _) =>
      ReactDOM.Style.combine(
        style,
        ReactDOM.Style.make(~marginLeft="10px", ()),
      ),
    menu: (style, _) =>
      ReactDOM.Style.combine(
        style,
        ReactDOM.Style.make(
          ~boxShadow="none",
          ~borderRadius="0 0 3px 3px",
          ~marginTop="0",
          ~position="relative",
          (),
        ),
      ),
    noOptionsMessage: (style, _) =>
      ReactDOM.Style.combine(
        style,
        ReactDOM.Style.make(~fontSize="14px", ~paddingBottom="4px", ()),
      ),
    option: (style, state) =>
      ReactDOM.Style.combine(
        style,
        ReactDOM.Style.make(
          ~backgroundColor=
            (state.isSelected, state.isFocused)
            |> (
              fun
              | (true, _) => "#ffdbb3"
              | (false, true) => "rgba(255, 219, 179, 0.5)"
              | _ => "transparent"
            ),
          ~padding="5px 10px",
          (),
        ),
      ),
    placeholder: (style, _) =>
      ReactDOM.Style.combine(
        style,
        ReactDOM.Style.make(~color="#ababab", ~marginLeft="10px", ()),
      ),
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

  // [ ] move isOpen & target inside Dropdown?
  <Components.CountrySelect.Dropdown
    className isOpen onClose={_ => setIsOpen(_ => false)} target>
    // [ ] move autoFocus, backspaceRemovesValue, components, controlShouldRenderValue, hideSelectedOptions, isClearable, formatOptionLabel, menuIsOpen, placeholder, styles, & unstyled inside Select?

      <Bindings.ReactSelect
        autoFocus=true
        components
        controlShouldRenderValue=false
        formatOptionLabel={({amount, label, value}: Types.Country.t) =>
          <Components.CountrySelect.Country amount label value />
        }
        menuIsOpen=true
        onChange={selected => {
          setSelected(_ => selected |> Option.some);
          setIsOpen(_ => false);
          selected |> onChange;
        }}
        onKeyDown={e =>
          e
          |> React.Event.Keyboard.keyCode
          |> (
            fun
            | 27 => setIsOpen(_ => false)
            | _ => ()
          )
        }
        options={countries |> Array.of_list}
        placeholder="Search..."
        styles
        unstyled=true
        value=selected
      />
    </Components.CountrySelect.Dropdown>;
};
