import React , {useState} from 'react'

export default function Textform(props){
    
    const handleUpClick = () => {
        let texts = text.toUpperCase();
        newtext(texts); 
        props.showAlert("Coverted to Upper case" , "success");
        // console.log("True");
        
    }

    const handleLowClick = () => {
        let texts = text.toLowerCase();
        newtext(texts); 
        props.showAlert("Coverted to Lower case" , "success");
        // console.log("True");
        
    }

    const handleClearClick = () => {
        let texts = "";
        newtext(texts); 
        props.showAlert("Text clear" , "success");
        // console.log("True");
        
    }

    const handleAnciiClick = () => {
        let texts = text;
        let strr , ans = "";
        for(let i = 0; i<texts.length;i++){
            strr = texts.charCodeAt(i).toString();
            ans += strr + " ";
        }
        newtext(ans);
        props.showAlert("Coverted to Ascii" , "success");
    }
    const handleCopyClick = () => {
        navigator.clipboard.writeText(text);
        props.showAlert("Text copied" , "success");
    }
    
    const changeText = (event) => {
        // console.log("true");
        newtext(event.target.value);
    }

    const [text , newtext] = useState('Enter Your Text Here');
    
    return(
  <>    
    <div className="container" style={{color : props.mode === 'light' ? 'black' : 'white'}}>
        <h1 className='my-2' >{props.heading}</h1>
        <div className='mb-3'>
            <textarea className="form-control" onChange={changeText} id='myBox' value={text} rows='6' style={{backgroundColor : props.mode === 'light' ? 'white' : '#41414345' , color : props.mode === 'light' ? 'black' : 'white'}} placeholder={props.placeholder}/>
        </div>
        <button disabled={text.length === 0} className='btn btn-primary mx-2 my-2' onClick={handleUpClick} >Convert to UpperCase</button>
        <button disabled={text.length === 0} className='btn btn-danger mx-2 my-2' onClick={handleLowClick} >Convert to UpperCase</button>
        <button disabled={text.length === 0} className='btn btn-info mx-2 my-2' onClick={handleClearClick} >Clear Text</button>
        <button disabled={text.length === 0} className='btn btn-success mx-2 my-2' onClick={handleAnciiClick} >ANCII Code</button>
        <button disabled={text.length === 0} className='btn btn-warning mx-2 my-2' onClick={handleCopyClick} >Copy text</button>
    </div>

    <div className="container my-3" style={{color : props.mode === 'light' ? 'black' : 'white'}}>
        <h3>Your Summary</h3>
        <p style={{fontSize:'15px'}}>Number of words <strong>{text.split(/\s+/).filter((element)=>{return element.length !==0 }).length}</strong>.</p> 
        <p style={{fontSize:'15px'}}>Number of characters <strong>{text.length}</strong>.</p>
        <p style={{fontSize:'15px'}}><strong>{0.008 * text.split(/\s+/).filter((element)=>{return element.length !==0 }).length}</strong> Minutes to read this.</p>
        <h3>Preview</h3>
        <p style={{fontSize:'15px'}}>{text.length>0 ? text : "No preview untill you type.."}</p>
    </div>
  </>
  );
}
