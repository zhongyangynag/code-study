import React from "react";
import { connect } from "react-redux";
import { AppState } from "../../store/index";
import {ChatState} from '../../store/chat/types'
import MessageItem from "../MessageItem";
const mapStateToProps=(state:AppState)=>({
    chat:state.chat
})

interface IProps{
    chat:ChatState
}
interface IState{
    
}
class MessageList extends React.Component<IProps,IState>{
    
    render(){
        const {chat} = this.props;
        return (
            <div>
                {
                    chat.messages.map((item,idx)=>{
                        return (
                            <MessageItem info={item} key={item.timestamp}></MessageItem>
                        )
                    })
                }
            </div>
        )
    }
    componentDidMount(){
    }
}

export default connect(mapStateToProps)(MessageList as any)