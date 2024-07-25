// [@mel.module "react-select"] [@react.component]
// external make:
//   (
//     ~autoFocus: bool=?,
//     // ~backspaceRemovesValue: bool=?,
//     ~components: Js.t({..})=?,
//     ~controlShouldRenderValue: bool=?,
//     // ~hideSelectedOptions: bool=?,
//     // ~isClearable: bool=?,
//     ~menuIsOpen: bool=?,
//     ~onChange: 'option => unit=?,
//     ~options: array('option),
//     ~placeholder: string=?,
//     ~unstyled: bool=?,
//     ~value: option('option)
//   ) =>
//   React.element =
//   "default";

let style = ReactDOM.Style.make(~padding="4px", ~width="100%", ());

// [@react.component]
// let make =
//     // ~onClick: React.Event.Mouse.t => unit,
//     (~selected: option(Types.Country.t)) =>
//   <Bindings.Select
//     autoFocus=true
//     components
//     // backspaceRemovesValue=false
//     controlShouldRenderValue=false
//     // hideSelectedOptions=false
//     // isClearable=false
//     menuIsOpen=true
//     onChange={selected => {
//       setSelected(_ => selected |> Option.some);
//       setIsOpen(_ => false);
//       selected |> onChange;
//     }}
//     options={countries |> Array.of_list}
//     placeholder="Search..."
//     // unstyled=true
//     value=selected
//   />;
