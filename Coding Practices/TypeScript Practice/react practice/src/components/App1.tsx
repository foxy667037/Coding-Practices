// import Box from "./components/Box";
// import Box2 from "./components/Box2";
import { FormEvent, useState } from "react";

interface person {
  name: string;
  age: number;
}

const App = () => {
  // const [Value, setValue] = useState<string>();
  // const [Value, setValue] = useState("");
  const [User, setUser] = useState<person>();

  const submitHandler = (e: FormEvent<HTMLFormElement>) => {
    e.preventDefault();
    console.log(User);
  }
  return (
    // <Box
    //   Heading="Helow"
    //   func1={(a: string) => {
    //     alert(a);
    //   }}
    // >
    //   {"lol"}
    // </Box>
    // <Box2 label="Search" value={Value} Setter={setValue} />
    <form onSubmit={submitHandler}>
      <input
        type="number"
        name=""
        id=""
        value={User?.age || ""}
        onChange={(event) => {
          setUser((pre) => ({ ...pre!, age: Number(event.target.value) }));
        }}
      />
      <input
        type="text"
        name=""
        id=""
        value={User?.name || ""}
        onChange={(event) => {
          setUser((pre) => ({ ...pre!, name: event.target.value }));
        }}
      />
      <button type="submit">Submit</button>
    </form>
  );
};

export default App;