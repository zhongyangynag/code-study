import { chatReducer } from './chat/reducers'
import { combineReducers } from "redux";

export const rootReducer = combineReducers({
    chat: chatReducer
})

export type AppState = ReturnType<typeof rootReducer>
