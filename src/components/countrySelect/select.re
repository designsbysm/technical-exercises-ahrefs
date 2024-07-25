[@mel.module "react-select"] [@react.component]
external make:
  (
    ~autoFocus: bool=?,
    // ~backspaceRemovesValue: bool=?,
    ~components: Js.t({..})=?,
    ~controlShouldRenderValue: bool=?,
    // ~hideSelectedOptions: bool=?,
    // ~isClearable: bool=?,
    ~formatOptionLabel: 'option => React.element=?,
    ~menuIsOpen: bool=?,
    ~onChange: 'option => unit=?,
    ~options: array('option),
    ~placeholder: string=?,
    ~unstyled: bool=?,
    ~value: option('option)
  ) =>
  React.element =
  "default";
