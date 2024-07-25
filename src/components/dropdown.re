let style = ReactDOM.Style.make(~position="relative", ());

[@react.component]
let make =
    (
      ~children: React.element,
      ~isOpen: bool,
      ~onClose: React.Event.Mouse.t => unit,
      ~target: React.element,
    ) =>
  <div style>
    target
    {isOpen
     |> (
       fun
       | true =>
         <>
           // [ ] menu
           <div key="menu"> children </div>
           // [ ] blanket
           <div key="blanket" onClick=onClose />
         </>
       | false => React.null
     )}
  </div>;
