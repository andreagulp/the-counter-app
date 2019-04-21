let str = React.string;

[@react.component]
let make = (~operation, ~label) =>
  <button onClick={_e => operation()}> {label |> str} </button>;