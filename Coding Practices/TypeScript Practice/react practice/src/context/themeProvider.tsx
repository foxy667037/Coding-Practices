import { useState } from "react";
import { ReactNode } from "react";
import { ThemeType } from "./themeType";
import { ThemeContext } from "./themeContext";

export const ThemeProvider = ({ children }: { children: ReactNode }) => {
  const [theme, settheme] = useState<ThemeType>("light");

  const toggleTheme = () => {
    settheme((pre) => (pre === "light" ? "dark" : "light"));
  };

  return (
    <ThemeContext.Provider
      value={{
        theme: theme,
        toggleTheme: toggleTheme,
      }}
    >
      {children}
    </ThemeContext.Provider>
  );
};