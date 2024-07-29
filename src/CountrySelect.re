// QUESTION: is there a better way?
let scrollToItem: (Js.nullable(Dom.element), int) => unit = [%mel.raw
  "(element, index) => element?.scrollToItem(index)"
];

[@react.component]
let make = (~className, ~country as defaultCountry, ~onChange) => {
  let (selected, setSelected) = React.useState(_ => None);
  let (isOpen, setIsOpen) = React.useState(_ => false);
  let listRef = React.useRef(Js.Nullable.null);
  let scrollIndex = React.useRef(0);

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

  <Components.CountrySelect.Dropdown
    className
    isOpen
    onClose={_ => setIsOpen(_ => false)}
    onKeyDown={e => {
      let currentIndex = scrollIndex.current;
      let newIndex =
        e
        |> Utils.Keyboard.getKey
        |> (
          fun
          | Some(Utils.Keyboard.ArrowDown) => currentIndex + 1
          | Some(ArrowUp) => currentIndex - 1
          | Some(PageDown) => currentIndex + 5
          | Some(PageUp) => currentIndex - 5
          | _ => currentIndex
        )
        // if we go out of bounds, we should loop around
        |> (
          fun
          | index when index < 0 => (countries |> List.length) - 1
          | index when index >= (countries |> List.length) => 0
          | index => index
        );

      scrollToItem(listRef.current, newIndex);
      scrollIndex.current = newIndex;
    }}
    target={
      <Components.CountrySelect.Button
        onClick={_ => {
          setIsOpen(prev => !prev);
          scrollIndex.current =
            selected
            |> (
              fun
              | Some(selected) =>
                countries
                |> List.find_index((country: Types.Country.t) =>
                     country.value == selected.value
                   )
              | None => None
            )
            |> (
              fun
              | Some(index) => index
              | None => 0
            );
        }}>
        {selected
         |> (
           fun
           | Some({label, value, _}) =>
             <Components.CountrySelect.Country label value />
           | None => "Select a Country" |> React.string
         )}
      </Components.CountrySelect.Button>
    }>
    <Components.CountrySelect.Select
      formatOptionLabel={({amount, label, value}: Types.Country.t) =>
        <Components.CountrySelect.Country amount label value />
      }
      listRef
      onChange={selected => {
        setSelected(_ => selected |> Option.some);
        setIsOpen(_ => false);
        selected |> onChange;
      }}
      onKeyDown={e =>
        e
        |> Utils.Keyboard.getKey
        |> (
          fun
          | Some(Utils.Keyboard.Escape)
          | Some(Tab) => setIsOpen(_ => false)
          | _ => ()
        )
      }
      options={countries |> Array.of_list}
      value=selected
    />
  </Components.CountrySelect.Dropdown>;
};
