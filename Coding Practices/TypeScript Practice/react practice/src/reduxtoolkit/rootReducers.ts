import { configureStore } from "@reduxjs/toolkit";
import counterReducer from "./counterSlice.ts";

const store = configureStore({
  reducer: {
    counter: counterReducer,
  },
});

export default store;