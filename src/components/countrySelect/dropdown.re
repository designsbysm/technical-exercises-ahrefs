let style = ReactDOM.Style.make();
// ~position="relative", ()

[@react.component]
let make =
    (
      ~children: React.element,
      ~className: string,
      ~isOpen: bool,
      ~onClose: React.Event.Mouse.t => unit,
      ~target: React.element,
    ) =>
  <div className style>
    target
    {isOpen
     |> (
       fun
       | true =>
         <>
           <Menu key="menu"> children </Menu>
           // [ ] blanket
           <div key="blanket" onClick=onClose />
         </>
       | false => React.null
     )}
  </div>;
