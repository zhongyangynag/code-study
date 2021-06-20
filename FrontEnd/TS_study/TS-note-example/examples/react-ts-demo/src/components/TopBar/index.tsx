import React from 'react';
import './index.scss'
interface IProps{
    title:string
}
export default class TopBar extends React.Component<IProps>{
    render(){
        const {title} = this.props
        return (
            <div className='wrapper-header'>
                <div className='header'>{title}</div>
            </div>
            
        )
    }
}