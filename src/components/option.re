// type t;
// let style = ReactDOM.Style.make(~marginRight="4px", ());

//  const Option = (props: OptionProps<Country>) => {
//    const { label, value } = props;

//    return (
//      <components.Option
//        {...props}
//        // style={{
//        //   padding: 20,
//        // }}
//      >
//        <CountryItem label={label} value={value} />
//      </components.Option>
//    );
//  };

[@mel.module "react-select"] [@react.component]
external make: 'props => React.element = "components";

// let make = (~amount: float, ~label: string, ~value: string) =>
// let make = () => <CountryItem amount=0. label="Test" value="test" />;

// [@mel.module "react-select"];
// [@react.component];
// {
// let className = "fi fi-" ++ value;

// <>
// <span className key="flag" style />
// {label |> React.string}
// <K amount key="k" />
// </>;
// };
