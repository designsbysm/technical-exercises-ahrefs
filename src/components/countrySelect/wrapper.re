let style =
  ReactDOM.Style.make(
    ~backgroundColor="#fff",
    ~borderRadius="3px",
    ~boxShadow=
      "0 3px 18px 0 rgba(0, 0, 0, 0.15), 0 0 0 1px rgba(0, 0, 0, 0.08)",
    ~marginTop="3px",
    ~position="relative",
    ~zIndex="2",
    (),
  );

[@react.component]
let make = (~children) => <div style> children </div>;
