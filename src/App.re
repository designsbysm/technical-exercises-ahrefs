module App = {
  [@react.component]
  let make = () => <> {"TODO" |> React.string} </>;
};

ReactDOM.querySelector("#root")
|> (
  fun
  | Some(rootElement) => {
      let root = ReactDOM.Client.createRoot(rootElement);
      ReactDOM.Client.render(root, <App />);
    }
  | None =>
    Js.Console.error("Failed to start React: couldn't find the #root element")
);
