import { createContext } from "react";
import { ThemeContextType } from "./themeType";

export const ThemeContext = createContext<ThemeContextType>({
  theme: "light",
  toggleTheme: () => {},
});