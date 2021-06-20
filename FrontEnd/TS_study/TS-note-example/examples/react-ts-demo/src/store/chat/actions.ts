import { Message,SEND_MESSAGE,DELETE_MESSAGE,ChatActionTypes } from "./types";

export function sendMessage(params:Message):ChatActionTypes {
    return {
        type:SEND_MESSAGE,
        payload:params
    }
}

export function deleteMessage(params:number):ChatActionTypes {
    return {
        type:DELETE_MESSAGE,
        meta:{
            timestamp:params
        }
    }
}