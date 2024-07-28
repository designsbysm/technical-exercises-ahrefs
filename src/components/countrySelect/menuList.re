// QUESTION: is there a better way to get the value of the child element?
let getValue: React.element => string = [%mel.raw
  "element => element.props.value"
];

[@react.component]
let make =
    (
      ~children: array(React.element),
      ~listRef,
      ~maxHeight: int,
      ~selected: option(Types.Country.t),
    ) => {
  let itemSize = 31;
  let initialScrollOffset =
    selected
    |> (
      fun
      | Some(selected) =>
        children
        |> Array.find_index(child => child |> getValue == selected.value)
        |> (
          fun
          | Some(index) => index * itemSize
          | None => 0
        )
      | None => 0
    );

  <Bindings.ReactWindow
    height={maxHeight + 10}
    initialScrollOffset
    itemCount={children |> Array.length}
    itemSize
    ref={ReactDOM.Ref.domRef(listRef)}
    width="100%">
    {({index, style}) => <div style> {children->Array.get(index)} </div>}
  </Bindings.ReactWindow>;
};
