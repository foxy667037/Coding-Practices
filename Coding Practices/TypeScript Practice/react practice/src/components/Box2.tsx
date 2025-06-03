// import React from 'react';
import { Dispatch, SetStateAction } from "react";

type InputValue = string | number;
const Box2 = <T extends InputValue>({
  label,
  value,
  Setter,
}: {
  label: string;
  value: T;
  // OnChange: React.Dispatch<React.SetStateAction<string>>
  Setter: Dispatch<SetStateAction<T>>;
}) => {
  return (
    <form>
      <label htmlFor="">{label}</label>
      <input
        type="text"
        name=""
        value={value}
        id=""
        onChange={(e) => Setter(e.target.value as T)}
      />
      <button type="submit">Submit</button>
    </form>
  );
};

export default Box2;