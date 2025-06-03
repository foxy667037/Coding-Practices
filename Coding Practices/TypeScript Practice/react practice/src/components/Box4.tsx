import { useContext } from "react";
import { ThemeContext } from "../context/themeContext";

const Box4 = () => {
  const {theme, toggleTheme} = useContext(ThemeContext);  
  return (
    <div className="boxContainer" style={{
        backgroundColor: theme === "light" ? "white" : "black",
        color: theme === "light" ? "black" : "white",
        cursor: "pointer"
      }}>
      <h1>Box4</h1>
      <button onClick={toggleTheme}>Chnage Theme</button>
    </div>
  )
}

export default Box4;