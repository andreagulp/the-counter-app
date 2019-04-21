let str = React.string;

type state = {count: int};

type action =
  | INCREMENT
  | DECREMENT;

[@react.component]
let make = () => {
  let ({count}, dispatch) =
    React.useReducer(
      (state, action) =>
        switch (action) {
        | INCREMENT => {count: state.count + 1}
        | DECREMENT => {count: state.count - 1}
        },
      {count: 0},
    );

  let incrementCounter = () => dispatch(INCREMENT);
  let decrementCounter = () => dispatch(DECREMENT);

  Js.log2("counter", count);

  <div>
    <h2> {"The Counter App" |> str} </h2>
    <hr />
    <Button operation=incrementCounter label="INCREMENT" />
    <div className="counter">
      <h4>
        {"counter: " |> str}
        <span> {string_of_int(count) |> str} </span>
      </h4>
    </div>
    <Button operation=decrementCounter label="DECREMENT" />
  </div>;
};