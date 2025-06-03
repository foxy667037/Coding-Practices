const a = "Fahad";
const b = "Fahadsss";
const c = "Fahadsssss";
const d = "Fahadssssss";

export default a;

export {b};
export {c};
export {d};


<div className={`form-check form-switch text-${props.mode === 'light' ? 'primary' : 'light'} mx-3`}>
        <input className="form-check-input" onClick={()=>props.toggleMode('primary')} type="checkbox" role="switch" id="flexSwitchCheckDefault"/>
        <label className="form-check-label" htmlFor="flexSwitchCheckDefault">Blue</label>
        </div>
        <div className={`form-check form-switch text-${props.mode === 'light' ? 'danger' : 'light'} mx-3`}>
        <input className="form-check-input" onClick={()=>props.toggleMode('danger')} type="checkbox" role="switch" id="flexSwitchCheckDefault"/>
        <label className="form-check-label" htmlFor="flexSwitchCheckDefault">Red</label>
else if(cls === 'danger'){
    removeBodyclasses();
    if(mode === 'dark'){
      setmode('light');
      document.body.style.backgroundColor='white';
      showAlert("Red mode is disabled", "success");
      
    }
    else{
      setmode('dark');
      document.body.style.backgroundColor='#df3f3f';
      showAlert("Red mode is enabled", "success");
      document.title = 'Textutils Red Mode';
    }
  }
  else if(cls === 'primary'){
    removeBodyclasses();
    if(mode === 'dark'){
      setmode('light');
      document.body.style.backgroundColor='white';
      showAlert("Blue mode is disabled", "success");
      
    }
    else{
      setmode('dark');
      document.body.style.backgroundColor='#4a4acd';
      showAlert("Blue mode is enabled", "success");
      document.title = 'Textutils Blue Mode';
    }
  }