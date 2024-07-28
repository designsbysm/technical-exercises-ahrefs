[@react.component]
let make = (~children, ~className, ~isOpen, ~onClose, ~onKeyDown, ~target) =>
  <div className>
    target
    {isOpen
     |> (
       fun
       | true =>
         <>
           <Wrapper key="menu" onKeyDown> children </Wrapper>
           <Blanket key="blanket" onClick=onClose />
         </>
       | false => React.null
     )}
  </div>;
