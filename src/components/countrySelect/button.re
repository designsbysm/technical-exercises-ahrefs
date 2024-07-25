let style = ReactDOM.Style.make(~padding="4px", ~width="100%", ());

// [ ] don't pass in selected?
[@react.component]
let make =
    (
      ~onClick: React.Event.Mouse.t => unit,
      ~selected: option(Types.Country.t),
    ) =>
  <button onClick style>
    {selected
     |> (
       fun
       | Some({label, value, _}) => <Country label value />
       | None => "Select a Country" |> React.string
     )}
    <ChevronDown />
  </button>;
