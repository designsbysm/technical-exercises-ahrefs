module App = {
  [@react.component]
  let make = () =>
    <CountrySelect
      className="custom-class"
      country={Some("gs")}
      onChange={country => country |> Js.log}
    />;
};

ReactDOM.querySelector("#root")
->(
    fun
    | Some(rootElement) =>
      ReactDOM.Client.createRoot(rootElement)
      ->ReactDOM.Client.render(<App />)
    | None =>
      Js.Console.error(
        "Failed to start React: couldn't find the #root element",
      )
  );
