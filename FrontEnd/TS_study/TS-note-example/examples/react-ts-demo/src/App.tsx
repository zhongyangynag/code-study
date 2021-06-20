import React from 'react';
import './App.css';
import { BrowserRouter as Router, Route } from "react-router-dom";
import Home from './views/home'
import ChatPage from './views/chatPage'
import PageDataStructure from './views/dataStructure'
import Algorithm from './views/algorithm'
import Index from './views/Index'
import PageTest from './views/pageTest'

interface IProps { }
interface IState { }

class App extends React.Component<IProps, IState>{
  render() {
    return (
      <Router>
        <div>
          <Route exact path='/' component={Index}></Route>
          <Route path='/Home' component={Home}></Route>
          <Route path='/ChatPage' component={ChatPage}></Route>
          <Route path='/DataStructure' component={PageDataStructure}></Route>
          <Route path='/Algorithm' component={Algorithm}></Route>
          <Route path='/PageTest' component={PageTest}></Route>
        </div>
      </Router>

    )
  }
}

export default App;
