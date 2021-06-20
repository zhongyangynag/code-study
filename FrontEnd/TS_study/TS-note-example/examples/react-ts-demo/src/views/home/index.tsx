import React from 'react';
import BottomBar from '../../components/BottomBar'
import MessageList from '../../components/MessageList';
import SendMessage from '../../components/SendMessage'
import TopBar from '../../components/TopBar'

interface IProps{}
interface IState{
    activeIndex:number
}
export default class Home extends React.Component<IProps,IState>{
    constructor(props:IProps){
        super(props)
        this.state={
            activeIndex:0
        }
    }
    setIndex=(idx:number):void=>{
        this.setState({
            activeIndex:idx
        })
    }
    render(){
        const {activeIndex} = this.state;
        return (
            <div>
                {
                    activeIndex===0 && (
                        <div>
                            <TopBar title='消息列表'></TopBar>
                            <MessageList></MessageList>
                        </div>
                        
                    )
                }
                {
                    activeIndex===1 && (
                        <div>
                            <TopBar title='发送消息'></TopBar>
                            <SendMessage onSendMessage={this.setIndex}></SendMessage>
                        </div>
                        
                    )
                }
                <BottomBar onChangeTab={this.setIndex} activeTab={activeIndex}></BottomBar>
            </div>
        )
    }
}