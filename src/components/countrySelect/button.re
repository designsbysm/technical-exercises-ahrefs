module Styles = {
  let arrow =
    ReactDOM.Style.make(~height="100%", ~marginLeft="5px", ~width="14px", ());

  let country = ReactDOM.Style.make(~minWidth="100px", ());

  let button =
    ReactDOM.Style.make(
      ~alignItems="center",
      ~backgroundColor="#fff",
      ~borderColor="rgba(0, 0, 0, 0.2)",
      ~borderRadius="3px",
      ~borderWidth="1px",
      ~display="flex",
      ~fontSize="14px",
      // ~justifyContent="space-between",
      ~padding="4px",
      ~position="relative",
      ~textAlign="left",
      ~zIndex="2",
      // ~width="100%",
      (),
    );
};

[@react.component]
let make = (~children, ~onClick) =>
  <button onClick style=Styles.button>
    <div style=Styles.country> children </div>
    <div style=Styles.arrow> <Icons.DownArrow /> </div>
  </button>;
