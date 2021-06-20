import React from 'react';
import { Message,DELETE_MESSAGE } from "../../store/chat/types";
import { AppState } from "../../store/index";
import { connect } from "react-redux";
import './index.scss'
interface IProps{
    info:Message;
    deleteMessage(params:number):void;
}
const mapStateToProps=(state:AppState)=>({
    chat:state.chat
})
const mapDispatchToProps=(dispatch:any)=>{
    return {
        deleteMessage:(params:number)=>{
            dispatch({
                type:DELETE_MESSAGE,
                meta:{
                    timestamp:params
                }
            })
        }
    }
}
class MessageItem extends React.Component<IProps> {
    handleDel=()=>{
        const {timestamp} = this.props.info;
        this.props.deleteMessage(timestamp)
    }
    render(){
        const {info} = this.props;
        return (
            <div className='all-center msg-wrapper'>
                <div className='fl'>
                    <div>{info.message}</div>
                    <div className='grey'>{info.timestamp}</div>
                </div>
                <div className='del' onClick={this.handleDel}>删除</div>
            </div>
        )
    }
}

export default connect(mapStateToProps,mapDispatchToProps)(MessageItem)