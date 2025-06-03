first=input("enter the first :")
op = input("choice operator(+ _ * % /):")
second=input("enter the second :")
first=int(first)
second=int(second)
if   op== "+":
    print(first+second)
elif op== "-":
     print(first-second)
elif op== "*":
     print(first*second)
elif op=="%":
     print(first%second)
elif op== "/":
     print(first/second)
else:
    print("invalid operator")