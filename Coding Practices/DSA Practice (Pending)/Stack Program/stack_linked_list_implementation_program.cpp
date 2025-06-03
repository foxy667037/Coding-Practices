// Push → Adds an element to the top of the stack.
// Pop → Removes and returns the top element.
// Peek → Returns the top element without removing it.
// isEmpty → Checks if the stack is empty.
// isFull → Checks if the stack is full.
// Size → Returns the number of elements in the stack.
// Display → Prints all stack elements.

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

class Stack
{
private:
    Node *top;
    int count;

public:
    Stack()
    {
        top = NULL;
        count = 0;
    }

    void push(int value)
    {
        Node *newNode = new Node();
        if (!newNode)
        {
            cout << "Stack Overflow.";
        };
        newNode->data = value;
        newNode->next = top;
        top = newNode;
        count++;
    };

    int pop()
    {
        if (isEmpty())
        {
            cout << "stack underflow.";
        };
        int poppedValue = top->data;
        Node *temp = top;
        top = top->next;
        delete temp;
        count--;
        return poppedValue;
    };

    void peek()
    {
        if (isEmpty())
        {
            cout << "stack underflow.";
        };
        cout << "Top Element: " << top->data << endl;
    }

    int size()
    {
        cout << "Size of Stack: " << count <<endl;
        return count;
    };

    bool isEmpty()
    {
        return top == NULL;
    };

    void display()
    {
        if (isEmpty())
        {
            cout << "Stack is Empty!" << endl;
            return;
        };
        cout << "Stack: ";
        Node *temp = top;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    };
};
int main()
{
    Stack Obj;
    Obj.push(1);
    Obj.push(2);
    Obj.push(3);
    Obj.push(4);
    Obj.push(5);
    Obj.push(6);

    Obj.display();

    Obj.pop();
    Obj.display();

    Obj.peek();
    Obj.size();

    return 0;
}