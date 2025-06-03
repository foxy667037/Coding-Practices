import { combineReducers } from "redux";
import amountReducer from "../child-reducers/amountReducer";

const rootReducers = combineReducers({
    count: amountReducer,
})

export default rootReducers;