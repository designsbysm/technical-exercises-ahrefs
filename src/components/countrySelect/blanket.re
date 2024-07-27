let style =
  ReactDOM.Style.make(
    ~bottom="0",
    ~left="0",
    ~position="fixed",
    ~right="0",
    ~top="0",
    ~zIndex="1",
    (),
  );

[@react.component]
let make = (~onClick) => <div onClick style />;
