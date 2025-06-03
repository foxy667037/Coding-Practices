// Push: Adds an element to the top of the stack.
// isEmpty(): Return true only, if the list is empty.
// Size(): Return the number of elements in the list.
// Pop: Removes and returns the element from the top of the stack.
// Peek/Top: Return the element at the top of the stack without removing it.

#include <iostream>
using namespace std;

class Stack
{
private:
    int arr[10];
    int top; // use to track the element in the stack
public:
    Stack()
    {
        top = -1;
    }

    void push(int value)
    {
        if (isFull())
        {
            cout << "Stack is Full" << endl;
            return;
        }
        arr[++top] = value;
    }

    int size()
    {
        return top + 1;
    };

    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack is Empty." << endl;
            return -1;
        }
        cout << "Popped Value = " << arr[top] << endl;
        return arr[top--];
    }

    void peek_top()
    {
        if (isEmpty())
        {
            cout << "Stack is Empty." << endl;
            return;
        }
        cout << "Top Value: " << arr[top] << endl;
    };

    bool isFull()
    {
        return top == 9;
    };

    bool isEmpty()
    {
        return top == -1;
    };

    void display()
    {
        for (int i = 0; i <= top; i++)
        {
            cout << "Stack Data: " << arr[i] << " ";
            cout << endl;
        };
        cout << endl;
    };
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

    Obj.peek_top();
    cout << endl;

    Obj.pop();
    Obj.display();

    cout << "Stack Size: " << Obj.size() << endl;
    cout << "Is Empty? " << (Obj.isEmpty() ? "Yes" : "No") << endl;
    cout << "Is Full? " << (Obj.isFull() ? "Yes" : "No") << endl;

    return 0;
}