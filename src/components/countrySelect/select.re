type component = {
  children: array(React.element),
  maxHeight: int,
};

let components = (~listRef, ~selected) => {
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
    |> MenuList.make
  );

  Obj.magic(obj);
};

let styles =
  Bindings.ReactSelect.makeStyles(
    ~control=
      (style, _) =>
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
    ~input=
      (style, _) =>
        ReactDOM.Style.combine(
          style,
          ReactDOM.Style.make(~marginLeft="10px", ()),
        ),
    ~menu=
      (style, _) =>
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
    ~noOptionsMessage=
      (style, _) =>
        ReactDOM.Style.combine(
          style,
          ReactDOM.Style.make(~fontSize="14px", ~paddingBottom="4px", ()),
        ),
    ~option=
      (style, state) =>
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
    ~placeholder=
      (style, _) =>
        ReactDOM.Style.combine(
          style,
          ReactDOM.Style.make(~color="#ababab", ~marginLeft="10px", ()),
        ),
    (),
  );

[@react.component]
let make =
    (~formatOptionLabel, ~listRef, ~onChange, ~onKeyDown, ~options, ~value) =>
  <Bindings.ReactSelect
    autoFocus=true
    components={components(~listRef, ~selected=value)}
    controlShouldRenderValue=false
    formatOptionLabel
    menuIsOpen=true
    onChange
    onKeyDown
    options
    placeholder="Search..."
    styles
    tabSelectsValue=false
    unstyled=true
    value
  />;
