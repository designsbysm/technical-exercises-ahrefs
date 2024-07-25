module K = {
  let style = ReactDOM.Style.make(~color="rgba(0, 0, 0, 0.52)", ());

  [@react.component]
  let make = (~amount: float) =>
    <span style> {amount |> Types.Amount.formatInKs |> React.string} </span>;
};

let style = ReactDOM.Style.make(~marginRight="4px", ());

[@react.component]
let make = (~amount: option(float)=?, ~label: string, ~value: string) => {
  let className = "fi fi-" ++ value;

  <>
    <span className key="flag" style />
    {label |> React.string}
    <span key="k">
      {amount
       |> (
         fun
         | Some(amount) => <K amount />
         | None => React.null
       )}
    </span>
  </>;
};
