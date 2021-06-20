import React from 'react';
import './index.scss'
interface IProps{
    onChangeTab(idx:number):void;
    activeTab:number
}
interface IState{
}
export default class BottomBar  extends React.Component<IProps,IState>{
    changeTab=(idx:number):void=>{
        this.props.onChangeTab(idx)
    }
    render(){
        const {activeTab} = this.props;
        return (
            <div className='wrapper all-center'>
                <div className={`fl item ${activeTab===0?'active':''}`} onClick={this.changeTab.bind(this,0)}>消息列表</div>
                <div className={`fl item ${activeTab===1?'active':''}`} onClick={this.changeTab.bind(this,1)}>发送消息</div>
            </div>
        )
    }
}