import { bindActionCreators } from "@reduxjs/toolkit";
import { useSelector, useDispatch } from "react-redux";
import actionCreators from "./reduxtoolkit/actionCreators";

const App = () => {
  type RootState = {
    counter: {
      count: number;
    };
  };

  const count = useSelector((state: RootState) => state.counter.count);
  const dispatch = useDispatch();

  const { increment, decrement } = bindActionCreators(actionCreators, dispatch);

  return (
    <div>
      <h2>Count: {count}</h2>
      <button onClick={() => increment(1)}>+</button>
      <button onClick={() => decrement(1)}>-</button>
    </div>
  );
};

export default App;