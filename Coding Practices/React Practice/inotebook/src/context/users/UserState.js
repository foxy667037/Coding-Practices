import React, { useState } from 'react';
import userContext from "./userContext";

const UserState = (props) => {

    const host = "http://localhost:5000";
    const [user, setUser] = useState({_id:"" , name:"" , email:""});  

    // Get User Detail:
    // useEffect(() => {
        const fetchUserDetails = async () => {
            try {
                const url = "/api/auth/getuser";
                const response = await fetch(`${host}${url}`, {
                    method: "POST",
                    headers: {
                        "auth-token": localStorage.getItem('token'),
                    },
                });
                if (response.ok) {
                    const userData = await response.json();
                    setUser(userData);
                } else {
                    console.error("Error fetching user details:", response.statusText);
                    // Optionally handle error state
                }
            } catch (error) {
                console.error("Error fetching user details:", error);
                // Optionally handle error state
            }
        };
        // fetchUserDetails(); // Call fetchUserDetails immediately upon component mount
    // }, []);

  return (
    <userContext.Provider
      value={{ user , fetchUserDetails }}
    >
      {props.children}
    </userContext.Provider>
  )
}

export default UserState
