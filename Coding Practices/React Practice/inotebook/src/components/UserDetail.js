import React, { useContext, useEffect} from 'react';
import userContext from '../context/users/userContext';

    const UserDetail = () => {
        // Consume the user context
        const context = useContext(userContext);
        const { user , fetchUserDetails } = context;
        // console.log("user :" , user);
        useEffect(()=>{
            fetchUserDetails();
        },[])

    
  return (
    <>  
        <div className="container">
         <h3>Account User Details</h3>   
        <form>
        <div className="mb-3">
            <label htmlFor="name" className="form-label">User id</label>
            <input type="text" className="form-control" value= {user._id} readOnly name='_id' id="_id" aria-describedby="emailHelp"/>
        </div>    
        <div className="mb-3">
            <label htmlFor="name" className="form-label">Name</label>
            <input type="text" className="form-control" value= {user.name} readOnly name='name' id="name" aria-describedby="emailHelp"/>
        </div>
        <div className="mb-3">
            <label htmlFor="email" className="form-label">Email</label>
            <input type="text" className="form-control" value={user.email} readOnly name='email' id="email"/>
            <div id="emailHelp" className="form-text">We'll never share your email with anyone else.</div>
        </div>
        </form>
        </div>
    </>
  )
}

export default UserDetail;