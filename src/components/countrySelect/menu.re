let style =
  ReactDOM.Style.make(
    // ~display="grid",
    // ~gridTemplateColumns="repeat(20px, 1fr, 20px)",
    // (),
    ~backgroundColor="#f0f",
    ~borderRadius="2px",
    ~boxShadow=
      "0 3px 18px 0 rgba(0, 0, 0, 0.15), 0 0 0 1px rgba(0, 0, 0, 0.08)",
    ~marginTop="3px",
    ~zIndex="2",
    (),
  );

[@react.component]
let make = (~children: React.element) => <div style> children </div>;
