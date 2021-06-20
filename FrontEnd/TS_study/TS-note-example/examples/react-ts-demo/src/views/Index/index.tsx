import React from 'react';
import { Link } from "react-router-dom";
import { IMenuItem } from '../../entities/menu/menuItem'
interface IProps{}
interface IState{
    menu:IMenuItem[]
}
export default class Index extends React.Component<IProps,IState>{
    constructor(props:IProps){
        super(props);
        this.state={
            menu:[{
                to:'/Home',
                text:'Home'
            },{
                to:'/DataStructure',
                text:'DataStructure'
            },{
                to:'/Algorithm',
                text:'Algorithm'
            },{
                to:'/PageTest',
                text:'PageTest'
            }]
        }
    }
    render(){
        const {menu} = this.state;
        return (
            <div>
                {
                    menu.map((item,idx)=>{
                        return (
                            <div key={idx}>
                                <Link to={item.to}>{item.text}</Link>
                            </div>
                        )
                    })
                }
                
            </div>
        )
    }
}