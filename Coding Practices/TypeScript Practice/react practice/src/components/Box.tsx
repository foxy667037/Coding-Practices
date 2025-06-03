import { ReactNode } from "react";

type PropTypes = {
  Heading: string;
  children:ReactNode
  func1: (a: string) => void;
};
// const Box = ({Heading}: {Heading: string})  => {
const Box = ({ Heading, func1, children }: PropTypes) => {
  func1("abc");
  return (
    <div>
      <h1>{Heading}</h1>
      {children}
    </div>
  );
};

export default Box;