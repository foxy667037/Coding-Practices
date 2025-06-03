import Box4 from "./Box4";
import { ThemeProvider } from "../context/themeProvider";

const App = () => {
  return (
    <ThemeProvider>
      <Box4 />
    </ThemeProvider>
  );
};

export default App;