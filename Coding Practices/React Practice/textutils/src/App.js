// import logo from './logo.svg';
import './App.css';
import 'bootstrap/dist/css/bootstrap.min.css'
import Navbar from './components/Navbar';
import Textform from './components/Textform';
import About from './components/About';
import Alert from './components/Alert';
import React , {useState} from 'react';

import {
  BrowserRouter,
  Route,
  Routes,
} from "react-router-dom";


function App(props) {

  const [mode, setmode] = useState('light');
  
  const removeBodyclasses = () =>  {
    document.body.classList.remove('bg-dark');
    document.body.classList.remove('bg-success');
    document.body.classList.remove('bg-warning');
    document.body.classList.remove('bg-primary');
  }

  
  const toggleMode = (cls) => {
    if(cls === 'dark'){
      removeBodyclasses();
      if(mode === 'light'){
        setmode('dark');
        document.body.style.backgroundColor='#19191d';
        showAlert("Dark mode is enabled", "success");
        document.title = 'Textutils Dark Mode';
      }
      else{
        setmode('light');
        document.body.style.backgroundColor='white';
        showAlert("Dark mode is disabled", "success");
        document.title = 'Textutils white Mode';
        
      }
    }
    else if(cls === 'success'){
      removeBodyclasses();
      if(mode === 'light'){
        setmode('dark');
        document.body.style.backgroundColor='#287b3f';
        showAlert("Green mode is enabled", "success");
        document.title = 'Textutils Green Mode';
      }
      else{
        setmode('light');
        document.body.style.backgroundColor='white';
        showAlert("Green mode is disabled", "success");
        document.title = 'Textutils white Mode';
      }
    }
    else{console.log("Wrong");}
    // console.log(cls);
    
  } 
  
      const colorMode = () =>{
        if(toggleMode() === 'success'){
              return 'success';
        }
        else if(toggleMode() === 'dark'){
              return 'dark';
        }
  }


  const [alert, setalert] = useState(null);
  const showAlert = (message, type) => {
    setalert({
      msg: message,
         type: type
        })
        setTimeout(()=>{
          setalert(null);
        },3000);
      }

  return(
  <>
    <BrowserRouter> 
    <Navbar title="TextUitils" about="About Us" mode={mode} colorMode={colorMode} toggleMode={toggleMode}/>
    <Alert alert={alert}/>
        <Routes> 
            <Route path='/about' element={<About mode={mode} colorMode={colorMode}/>}/>
            <Route path='/' element={<Textform heading="Enter Your Text Below...." placeholder="Enter here" colorMode={colorMode} mode= {mode} showAlert={showAlert}/>}/>
        </Routes>
    </BrowserRouter>
  </>
  );
}
  
export default App;