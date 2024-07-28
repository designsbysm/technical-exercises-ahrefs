type children = {
  index: int,
  style: ReactDOM.Style.t,
};

[@mel.module "react-window"] [@react.component]
external make:
  (
    ~children: children => React.element,
    ~height: int,
    ~itemCount: int,
    ~width: string,
    ~itemSize: int,
    ~initialScrollOffset: int,
    ~ref: ReactDOM.domRef=?
  ) =>
  React.element =
  "FixedSizeList";
