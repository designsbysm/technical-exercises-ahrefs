module K = {
  let style =
    ReactDOM.Style.make(
      ~color="rgba(0, 0, 0, 0.52)",
      ~fontSize="12px",
      ~marginLeft="auto",
      (),
    );

  [@react.component]
  let make = (~amount) =>
    <span style> {amount |> Types.Amount.formatInKs |> React.string} </span>;
};

module Styles = {
  let flag =
    ReactDOM.Style.make(
      ~height="10px",
      ~marginRight="4px",
      ~minWidth="18px",
      (),
    );

  let text =
    ReactDOM.Style.make(
      ~overflow="hidden",
      ~textOverflow="ellipsis",
      ~whiteSpace="nowrap",
      (),
    );

  let wrapper =
    ReactDOM.Style.make(
      ~alignItems="center",
      ~color="#333333",
      ~display="flex",
      ~fontSize="14px",
      (),
    );
};

[@react.component]
let make = (~amount=?, ~label, ~value) => {
  let className = "fi fi-" ++ value;

  <div style=Styles.wrapper>
    <span className style=Styles.flag />
    <span style=Styles.text> {label |> React.string} </span>
    {amount
     |> (
       fun
       | Some(amount) => <K amount />
       | None => React.null
     )}
  </div>;
};
