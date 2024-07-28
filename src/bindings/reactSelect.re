type state = {
  isFocused: bool,
  isSelected: bool,
};

type styleFn = option((ReactDOM.Style.t, state) => ReactDOM.Style.t);

type styles = {
  control: styleFn,
  input: styleFn,
  menu: styleFn,
  noOptionsMessage: styleFn,
  option: styleFn,
  placeholder: styleFn,
};

let makeStyles =
    (
      ~control=?,
      ~input=?,
      ~menu=?,
      ~noOptionsMessage=?,
      ~option=?,
      ~placeholder=?,
      (),
    ) => {
  control,
  input,
  menu,
  noOptionsMessage,
  option,
  placeholder,
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
    ~tabSelectsValue: bool=?,
    ~unstyled: bool=?,
    ~value: option('value)
  ) =>
  React.element =
  "default";
