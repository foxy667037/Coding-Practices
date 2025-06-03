type StateType = number; 

export interface State {
  type: string;
  payload: StateType; 
}

export const increment = (count: StateType) => {
  return (dispatch: (action: State) => void) => {
    dispatch({
      type: "increment",
      payload: count,
    });
  };
};

export const decrement = (count: StateType) => {
  return (dispatch: (action: State) => void) => {
    dispatch({
      type: "decrement",
      payload: count,
    });
  };
};