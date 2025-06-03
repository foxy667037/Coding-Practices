import React from 'react';
import './App.css';
import 'bootstrap/dist/css/bootstrap.min.css';
import { useState } from 'react';
import Navbar from './components/Navbar'
import News from './components/News';
import LoadingBar from 'react-top-loading-bar';

import {
  BrowserRouter,
  Route,
  Routes,
} from "react-router-dom";

const App = () => {

  const pageSize = 20;
  const apikey = process.env.REACT_APP_NEWS_API
  
  const [progress, setProgress] = useState(0);
  return (
  
        <BrowserRouter>
          <Navbar/>
          <LoadingBar
            color='#0c6efd'
            progress={progress}
            height={3}
          />
          <Routes>
            <Route exact path='/' element={<News setProgress={setProgress} apikey={apikey} pageSize={pageSize} country="us" category="general"/>}/>
            <Route exact path='/sport' element={<News setProgress={setProgress} apikey={apikey} key={'sport'} pageSize={pageSize} country="us" category="sport"/>} />
            <Route exact path='/weather' element={<News setProgress={setProgress} apikey={apikey} key={'weather'} pageSize={pageSize} country="us" category="weather"/>}/>
            <Route exact path='/lifestyle' element={<News setProgress={setProgress} apikey={apikey} key={'lifestyle'} pageSize={pageSize} country="us" category="lifestyle"/>}/>
            <Route exact path='/health' element={<News setProgress={setProgress} apikey={apikey} key={'health'} pageSize={pageSize} country="us" category="health"/>}/>
            <Route exact path='/society' element={<News setProgress={setProgress} apikey={apikey} key={'society'} pageSize={pageSize} country="us" category="society"/>}/>
            <Route exact path='/business' element={<News setProgress={setProgress} apikey={apikey} key={'business'} pageSize={pageSize} country="us" category="business"/>}/>
            <Route exact path='/technology' element={<News setProgress={setProgress} apikey={apikey} key={'technology'} pageSize={pageSize} country="us" category="technology"/>}/>
          </Routes>
        </BrowserRouter>
    )
}

export default App;