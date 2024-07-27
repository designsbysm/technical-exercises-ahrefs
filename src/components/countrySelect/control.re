module Styles = {
  let icon =
    ReactDOM.Style.make(
      ~height="15px",
      ~marginLeft="12px",
      ~width="13px",
      (),
    );

  let wrapper =
    ReactDOM.Style.make(
      ~alignItems="center",
      ~display="flex",
      ~flexWrap="wrap",
      ~fontSize="14px",
      (),
    );
};

// [@mel.module "react-select"] [@mel.scope "components"] [@react.component]
// external control: unit => React.element = "Control";
// FIXME: missing getStyles
// module Control1 = {
//   [@mel.module "react-select"] [@mel.scope "components"]
//   external make: unit => React.element = "Control";
// };

// FIXME: looks correct but clicking placeholder remove input focus
[@react.component]
let make = (~children) =>
  <div style=Styles.wrapper>
    <div key="icon" style=Styles.icon> <Icons.Search /> </div>
    children
  </div>;
