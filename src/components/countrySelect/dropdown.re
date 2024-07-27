[@react.component]
let make = (~children, ~className, ~isOpen, ~onClose, ~target) =>
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
