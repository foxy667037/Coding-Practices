import './App.css';
import 'bootstrap/dist/css/bootstrap.min.css';
import React, { Component } from 'react';
import Navbar from './components/Navbar';
import News from './components/News';
import LoadingBar from 'react-top-loading-bar';

import {
  BrowserRouter,
  Route,
  Routes,
} from "react-router-dom";

export default class App extends Component {
  pageSize= 20;
  apikey=process.env.REACT_APP_NEWS_API

  state= {
    progress:0,
  }
  setProgress = (progress) => {
    this.setState({progress: progress})
  }

  render() {
    return (
        <BrowserRouter>
          <Navbar/>
          <LoadingBar
            color='#0c6efd'
            progress={this.state.progress}
            height={3}
          />
          <Routes>
            <Route exact path='/' element={<News setProgress={this.setProgress} apikey={this.apikey} pageSize={this.pageSize} country="us" category="general"/>}/>
            <Route exact path='/sport' element={<News setProgress={this.setProgress} apikey={this.apikey} key={'sport'} pageSize={this.pageSize} country="us" category="sport"/>} />
            <Route exact path='/weather' element={<News setProgress={this.setProgress} apikey={this.apikey} key={'weather'} pageSize={this.pageSize} country="us" category="weather"/>}/>
            <Route exact path='/lifestyle' element={<News setProgress={this.setProgress} apikey={this.apikey} key={'lifestyle'} pageSize={this.pageSize} country="us" category="lifestyle"/>}/>
            <Route exact path='/health' element={<News setProgress={this.setProgress} apikey={this.apikey} key={'health'} pageSize={this.pageSize} country="us" category="health"/>}/>
            <Route exact path='/society' element={<News setProgress={this.setProgress} apikey={this.apikey} key={'society'} pageSize={this.pageSize} country="us" category="society"/>}/>
            <Route exact path='/business' element={<News setProgress={this.setProgress} apikey={this.apikey} key={'business'} pageSize={this.pageSize} country="us" category="business"/>}/>
            <Route exact path='/technology' element={<News setProgress={this.setProgress} apikey={this.apikey} key={'technology'} pageSize={this.pageSize} country="us" category="technology"/>}/>
          </Routes>
        </BrowserRouter>
    )
  }
}
