// Push → Adds an element to the top of the stack.
// Pop → Removes and returns the top element.
// Peek → Returns the top element without removing it.
// isEmpty → Checks if the stack is empty.
// isFull → Checks if the stack is full.
// Size → Returns the number of elements in the stack.
// Display → Prints all stack elements.

#include <iostream>
using namespace std;

class Stack
{
private:
    int arr[10];
    int top;

public:
    Stack()
    {
        top = -1;
    }

    void push(int value)
    {
        if (isFull())
        {
            cout << "Stack is Full." << endl;
            return;
        }
        arr[++top] = value;
    }

    void pop()
    {
        if (isEmpty())
        {
            cout << "Stack is Empty." << endl;
            return;
        }
        cout << "Popped Value: " << arr[top] << endl;
        top--;
    }

    int peek()
    {
        if (isEmpty())
        {
            cout << "Stack is Empty." << endl;
            return -1;
        }
        return arr[top];
    }

    bool isFull()
    {
        return top == 9;
    }

    bool isEmpty()
    {
        return top == -1;
    }

    int size()
    {
        return top + 1;
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Stack is Empty!" << endl;
            return;
        }
        cout << "Stack (top to bottom): ";
        for (int i = top; i >= 0; i--)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Stack Obj;

    Obj.push(10);
    Obj.push(20);
    Obj.push(30);
    Obj.push(40);
    Obj.push(50);

    Obj.display();

    cout << "Top Element: " << Obj.peek() << endl;

    Obj.pop();
    Obj.display();

    cout << "Stack Size: " << Obj.size() << endl;
    cout << "Is Empty? " << (Obj.isEmpty() ? "Yes" : "No") << endl;
    cout << "Is Full? " << (Obj.isFull() ? "Yes" : "No") << endl;

    return 0;
}