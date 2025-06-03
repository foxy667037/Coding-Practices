"use strict";
// typeScript Datatypes
// let a:string = "34";
// let a = <number>34;
// let a: number | string = 34;
// --------------------------------------------------------------------------------
// type alaisis: it help to make custom data types:
// type UserName = (n: number, m: number) => number;
// let a:UserName;
// const fun:UserName = (n, m) => {
//   return n * m;
// };
// --------------------------------------------------------------------------------
// Array:
// const arr: number[] = [23, 45, 6, 7, 4];
// const arr2: Array<string> = ["a", "b", "c", "d", "e"];
// const arr3: [number, string, boolean] = [34, "34", true];
// arr2.forEach(i => {
//     console.log(i.replace("a", "b"));
// })
// --------------------------------------------------------------------------------
// Object:
// interface Obj {
//   height: number;
//   weight: number;
//   gender?: number; // the quesion mark indicate that the gender optionally
// };
// interface Obj2 extends Obj { // extents indicate that it copy all the properties and attributes of the Obj
//     scolar: boolean,
// }
// const obj: Obj2 = {
//   height: 34,
//   weight: 34,
//   gender:34,
//   scolar: true,
// };
// --------------------------------------------------------------------------------
// function:
// type FuncType = (n: number, m: number, l?:number) => number;
// const fun:FuncType = (n , m, l = 20) => {
//     return n * m;
// }
// fun(20,20);
// function lol(n:number):number{
// return n;
// }
// lol(3);
// --------------------------------------------------------------------------------
// rest operator:
// type FuncType = (...m: number[]) => number[];
// const func:FuncType = (...m) => {
//     return m;
// }
// func(3, 3, 65, 76);
// --------------------------------------------------------------------------------
// function with object:
// interface Product {
//   name: string;
//   stock: number;
//   price: number;
//   photo: number;
//   readonly id: number;
// }
// type getDatatype = (product: Product) => void;
// const getdata: getDatatype = (product) => {
//   console.log(product);
// };
// const productOne: Product = {
//   name: "macbook",
//   stock: 45,
//   price: 34,
//   photo: 99999,
//   id: 23,
// };
// getdata(productOne);
// --------------------------------------------------------------------------------
// Never Type:
// const errorHandler = (): never => {
//   throw new Error();
// };
// --------------------------------------------------------------------------------
// classes in typescript:
// class Player {
//   public readonly id: string;
//   constructor(
//     private height: number,
//     public weight: number,
//     protected power: number
//   ) {
//     this.id = String(Math.round(Math.random() * 100));
//   }
//   // getmyHeight = () => this.height;
//   // get and set in classess:
//   get getmyHeight():number{
//     return this.height;
//   }
//   set changeHeight(val:number){
//     this.height = val;
//   }
// }
// class newPlayer extends Player {
//   special?:boolean;
//   constructor(height: number, weight: number, power: number, special = true) {
//     super(height, weight, power);
//     this.special = special;
//   }
//   getmyPower = () => this.power;
// }
// const player = new Player(100, 300, 140);
// player.changeHeight=500;
// console.log(player.getmyHeight);
// --------------------------------------------------------------------------------
// interface in class:
// interface ProductType {
//   name: string;
//   price: number;
//   stock: number;
//   offer?: boolean;
// }
// interface getId {
//   getId: () => string;
// }
// class Product implements ProductType, getId {
//   private id: string = String(Math.random() * 100);
//   constructor(
//     public name: string,
//     public price: number,
//     public stock: number
//   ) {}
//   getId = () => this.id;
// }
// const product1 = new Product("Macbook", 2000, 20);
// --------------------------------------------------------------------------------
// type Assertion
// const btn = document.getElementById("btn") as HTMLElement;
// const btn = <HTMLElement> document.getElementById("btn");
// btn.onclick;
// const form = document.getElementById("myform") as HTMLFormElement;
// const input = document.getElementById("myinput") as HTMLInputElement;
// const answer = document.getElementById("answer") as HTMLParagraphElement;
// form.onsubmit = (e: SubmitEvent): void => {
//   e.preventDefault();
//   const myanswer = Number(input.value) + 20;
//   const myanswer2: string = myanswer.toString();
//   answer.innerText = myanswer2;
// };
// --------------------------------------------------------------------------------
// interface Person {
//   // [key: string]:string
//   name: string;
//   email: string;
// }
// const obj: Person = {
//   name:"foxy",
//   email:"m@gmail.com",
// }
// let key = "name";
// obj[key as keyof typeof obj];
// const getname = ():string => {
//   return obj.name;
// }
// const getemail = ():string => {
//   return obj.email;
// }
// const getdata = (key: keyof Person):string => {
//   return obj[key];
// }
// --------------------------------------------------------------------------------
// type utility
// 1. Partial<Type>
// type User = {
//     name:string,
//     email:string,
// }
// type PartialUser = Partial<User>;
// 2. Required<Type> oppsoide of partial:
// type User = {
//     name?: string,
//     email?: string,
// }
// type requiredUser = Required<User>;
// 3. Readonly<Type> make every property readonly:
// type User = {
//         name: string,
//         email: string,
//     }
// const UserReadOnly: Readonly<User> = {
//     name:"123",
//     email:"m@gmail.com",
// };
// UserReadOnly.name = "123"; // cannot assign name because it is readonly
// 4. Record<Type>
// const User = {
//   name: "123",
//   email: "m@gmail.com",
// };
// type User2 = Record<"name"| "email"| "gender", string>;
// Example:
// interface UserInfo {
//     age: number;
// }
// type Username = "John"|"Ali"|"Ahmad";
// const Users:Record<Username, UserInfo> = {
//     John: { age: 30 },
//     Ali: { age: 28 },
//     Ahmad: { age: 25 },
// };
// 5. Peek<type>
// interface OrderReview {
//     readonly id:string,
//     user:string,
//     email:string,
//     country:string,
//     status:string,
// }
// type ShippingInfo = Pick<OrderReview, "user" | "email" | "country">;
// 6. Peek<type>
// interface OrderReview {
//     readonly id:string,
//     user:string,
//     email:string,
//     country:string,
//     status:string,
// }
// type ShippingInfo = Omit<OrderReview, "user" | "email" | "country">;
// 7. Exclude<type>
// type Random = string | boolean | number;
// type ExcludeRandom = Exclude<Random, string>; // it remove the string from the random type
// 8. Extract<type>
// type Random = string | boolean | number;
// type ExtractRandom = Extract<Random, string>; // it keep the string from the random type
// 9. NonNullable<type>
// type Random = string | null | undefined;
// type NonNullableRandom = NonNullable<Random>; // it remove the null and undefined from the
// 10. Parameters<type>
// const myfunc = (a:number, b:number) => {
//     console.log(a + b);
// }
// type Random = Parameters<typeof myfunc>;
// 11. Constructor<type>
// class Person {
//     public name:string = "abc";
//     public age:number = 12;
//     constructor(name:string, age:number){
//         return {name, age};
//     }
// }
// type Random = ConstructorParameters<typeof Person>;
// 12. ReturnType<type>
// const myfunc = (a:number, b:number): number => {
//     console.log(a + b);
//     return a + b;
// }
// type func = ReturnType<typeof myfunc>;
// 13. InstanceType<type>
// class Person {
//     constructor(name:string, age:number){
//         return {name, age};
//     }
// }
// type Random = InstanceType<typeof Person>;
// const user:Random = {
//     name: "John Doe",
//     age: 30
// }
// 14. Uppercase
// type Random = string; // Define a literal type
// type ExtractRandom = Uppercase<Random>; // Convert the literal type to uppercase
// const a: Random = "abc"; // Variable `a` must match the `Random` literal type
// console.log(a); // Output: abc
// const b: ExtractRandom = "ABC"; // `ExtractRandom` type will enforce the uppercase string
// console.log(b); // Output: ABC
// 15. Awaited<type>
// const example = async () => {
//   const response: Awaited<Promise<object>> = await Promise.resolve({
//     name: "abc",
//     email: "abc@gmail.com",
//   });
//   const response2: Awaited<Promise<Promise<number>>> = await Promise.resolve(
//     Promise.resolve(12)
//   );
//   const response3: Awaited<Promise<Promise<Promise<boolean | number>>>> =
//     await Promise.resolve(Promise.resolve(Promise.resolve(12)));
// };
// -----------------------------------------------------------------------------------------------
// Generic typescript:
// const func = <T>(n:T):T => {
//     return n;
// }
// type Elements = {
//     id: number,
//     name: string,
// };
// const obj:Elements = {
//     id: 1,
//     name: "John",
// }
// const func = <T>(n:T):T => {
//     return n;
// }
// const ans = func<Elements>(obj);
// Array use generic:
// const arr:number[] = [];
// const arr2:Array<number> = [];
// use 2 generic:
// const func = <T, U>(n:T, m:U):object => {
//     return {n, m};
// }
// const ans = func<number,string>(20,"abc");
// extends keyword:
// const func = <T, U extends T>(n: T, m: U): object => {
//   //extent keyword used to copy all properties and attributes of the previous class, function; U copy all properties like T is a number so that U also be a number. U cannot be a string, boolean and other
//   return { n, m };
// };
// const ans = func<number, number>(20, 30);
// example extent:
// type person = {
//     name: string;
//     id: number;
// }
// type person2 = {
//     name: string;
//     id: number;
// }
// const user:person={
//     name:"Foxy",
//     id:12,
// }
// const user2:person2={
//     name:"Foxy",
//     id:12,
// }
// const func = <T, U extends T>(n: T, o: U):object => {
//     return {n, o}
// }
// const ans = func<person, person2>(user, user2);
// type Person = {
//     name: string;
//     age: number;
// }
// const people: Person[] = [
//     { name: "John", age: 30 },
//     { name: "Alice", age: 28 },
//     { name: "Bob", age: 35 },
// ]
// const filterByPeoples = <T,K extends keyof T> (arr:T[], property:K, value:T[K]): T[] => {
//     return arr.filter(item => item[property] === value);
// }
// const filteredPeopleByName = filterByPeoples(people, "name", "John");
