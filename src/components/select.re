[@mel.module "react-select"] [@react.component]
external make:
  (
    ~autoFocus: bool=?,
    // ~backspaceRemovesValue: bool=?,
    ~components: Js.t({..})=?,
    ~controlShouldRenderValue: bool=?,
    // ~hideSelectedOptions: bool=?,
    // ~isClearable: bool=?,
    ~menuIsOpen: bool=?,
    ~onChange: 'country => unit=?,
    ~options: array('country),
    ~placeholder: string=?,
    ~unstyled: bool=?,
    ~value: option('country)
  ) =>
  React.element =
  "default";
