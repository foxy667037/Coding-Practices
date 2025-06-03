import { State } from "../../action-creators/actionCreators";

const amountReducer = (state: number = 0, action: State): number => {
  switch (action.type) {
    case "increment":
      return state + Number(action.payload);
    case "decrement":
      return state - Number(action.payload);
    default:
      return state;
  }
};

export default amountReducer;