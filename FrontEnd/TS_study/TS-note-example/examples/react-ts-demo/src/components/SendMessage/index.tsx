import React from "react";
import { connect } from "react-redux";
import { AppState } from "../../store/index";
import {ChatState,SEND_MESSAGE,Message} from '../../store/chat/types'
const mapStateToProps=(state:AppState)=>({
    chat:state.chat
})

const mapDispatchToProps=(dispatch:any)=>{
    return {
        sendMessage:(params:Message)=>{
            dispatch({
                type:SEND_MESSAGE,
                payload:params
            })
        }
    }
}

interface IProps{
    sendMessage(params:Message):ChatState;
    onSendMessage(idx:number):void;
    chat:ChatState;
}
interface IState{
    val:string
}
class SendMessage extends React.Component<IProps,IState>{
    constructor(props:any){
        super(props);
        this.state={
            val:''
        }
    }
    
    handleClick=():void=>{
        const message:Message={
            message:this.state.val,
            user:'123',
            timestamp:new Date().getTime()
        }
        this.props.sendMessage(message)
        this.props.onSendMessage(0)
    }
    handleInput=(e:any)=>{
        e.persist()
        this.setState({
            val:e.target.value
        })
    }

    test=()=>{
        console.log('000')
        return function () {
            console.log('111')
        }
    }
    render(){
        // const {chat} = this.props;
        return (
            <div className='all-center' style={{marginTop:20}}>
                {/* {
                    chat.messages.map((item,idx)=>{
                        return (
                            <div key={idx}>{item.message}</div>
                        )
                    })
                } */}
                <input placeholder='input message' value={this.state.val} onInput={this.handleInput} onChange={this.handleInput}/>
                <button onClick={this.handleClick}>submit</button>
            </div>
        )
    }
    componentDidMount(){
        // console.log(this.test())
    }
}

export default connect(mapStateToProps,mapDispatchToProps)(SendMessage)