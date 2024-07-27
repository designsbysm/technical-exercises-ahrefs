module Styles = {
  let arrow =
    ReactDOM.Style.make(
      ~height="100%",
      ~marginLeft="auto",
      ~width="14px",
      (),
    );

  let country = ReactDOM.Style.make(~width="calc(100% - 24px)", ());

  let button =
    ReactDOM.Style.make(
      ~alignItems="center",
      ~backgroundColor="#fff",
      ~borderColor="rgba(0, 0, 0, 0.2)",
      ~borderRadius="3px",
      ~borderStyle="solid",
      ~borderWidth="1px",
      ~cursor="pointer",
      ~display="flex",
      ~fontSize="14px",
      ~maxWidth="100%",
      ~padding="4px",
      ~position="relative",
      ~textAlign="left",
      ~width="100%",
      ~zIndex="2",
      (),
    );
};

[@react.component]
let make = (~children, ~onClick) =>
  <button onClick style=Styles.button tabIndex=0>
    <div style=Styles.country> children </div>
    <div style=Styles.arrow> <Icons.DownArrow /> </div>
  </button>;
