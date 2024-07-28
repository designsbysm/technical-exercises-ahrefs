// [ ] add interfact to hide state, styleFn

type state = {
  isFocused: bool,
  isSelected: bool,
};

type styleFn = (ReactDOM.Style.t, state) => ReactDOM.Style.t;

// QUESTION: How do we make these optional without needing to define each one?
// QUESTION: No { control: None, input: Some(styleFn), ...}
// IDEA: Createa a function (~control=? ...) => styles{ option(), ...}
type styles = {
  control: styleFn,
  input: styleFn,
  menu: styleFn,
  option: styleFn,
  placeholder: styleFn,
};

[@mel.module "react-select"] [@react.component]
external make:
  (
    ~autoFocus: bool=?,
    ~components: styles=?,
    ~controlShouldRenderValue: bool=?,
    ~formatOptionLabel: 'value => React.element=?,
    ~menuIsOpen: bool=?,
    ~onChange: 'value => unit=?,
    ~onKeyDown: 'props => unit=?,
    ~options: array('value),
    ~placeholder: string=?,
    ~styles: styles=?,
    ~unstyled: bool=?,
    ~value: option('value)
  ) =>
  React.element =
  "default";
