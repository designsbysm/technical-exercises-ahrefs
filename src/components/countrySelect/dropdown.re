[@react.component]
let make =
    (
      ~children: React.element,
      ~className: string,
      ~isOpen: bool,
      ~onClose: React.Event.Mouse.t => unit,
      ~target: React.element,
    ) =>
  <div className>
    target
    {isOpen
     |> (
       fun
       | true =>
         <>
           <Wrapper key="menu"> children </Wrapper>
           <Blanket key="blanket" onClick=onClose />
         </>
       | false => React.null
     )}
  </div>;
