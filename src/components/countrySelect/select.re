// [ ] move to bindings

type state = {
  isFocused: bool,
  isSelected: bool,
};

type style = (ReactDOM.Style.t, state) => ReactDOM.Style.t;

let a: style = (style, _state) => style;

type styles = {
  control: style,
  input: style,
  menu: style,
  menuList: style,
  option: style,
  placeholder: style,
};

[@mel.module "react-select"] [@react.component]
external make:
  (
    ~autoFocus: bool=?,
    ~components: Js.t({..})=?,
    ~controlShouldRenderValue: bool=?,
    ~formatOptionLabel: 'option => React.element=?,
    ~menuIsOpen: bool=?,
    ~onChange: 'option => unit=?,
    ~onKeyDown: 'props => unit=?,
    ~options: array('option),
    ~placeholder: string=?,
    ~styles: styles=?,
    ~unstyled: bool=?,
    ~value: option('option)
  ) =>
  React.element =
  "default";
