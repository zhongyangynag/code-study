import React from "react";
import SendMessage from '../../components/SendMessage'
interface IProps{
    onSendMessage(idx:number):void;
}
export default class ChatPage extends React.Component<IProps> {
    render(){
        return (
            <div>
                <SendMessage onSendMessage={this.props.onSendMessage.bind(this,0)}></SendMessage>
            </div>
        )
    }
}