// import { useState } from "react";
// import { useDispatch, useSelector } from "react-redux";
// import { increment, decrement, incrementByValue, StateType } from "./state/store";

// const App = () => {
//   const [val, setVal] = useState<number>(0);
//   const dispatch = useDispatch();
//   const count = useSelector((state: { counter: StateType }) => state.counter.count);

//   const incrementByValueHandler = () => {
//     dispatch(incrementByValue(val));
//   };

//   return (
//     <div>
//       <h1>Redux Toolkit Counter</h1>
//       <h2>{count}</h2>
//       <button onClick={() => dispatch(increment())}>+</button>
//       <button onClick={() => dispatch(decrement())}>-</button>
//       <input
//         type="number"
//         value={val}
//         onChange={(e) => setVal(Number(e.target.value))}
//       />
//       <button disabled={val < 0} onClick={incrementByValueHandler}>
//         Add
//       </button>
//     </div>
//   );
// };

// export default App;