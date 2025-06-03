#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

class Queue
{
private:
    Node *front;
    Node *rear;

public:
    Queue()
    {
        front = rear = nullptr; // nullptr == NULL
    };
    void enqueue(int value)
    {
        Node *newNode = new Node();
        if (newNode == NULL)
        {
            cout << "Queue is Full.";
        };
        newNode->data = value;
        newNode->next = NULL;
        if (front == NULL)
        {
            front = rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }
    };

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty!" << endl;
            return;
        };

        int dequeuedValue = front->data;
        Node *temp = front;
        front = front->next;
        delete temp;
        cout << "Dequeued Element: " << dequeuedValue << endl;
        return;
    };

    void peek()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty!" << endl;
            return;
        };

        int peekValue = front->data;
        int bottomValue = rear->data;

        cout << "Top Element: " << peekValue << endl;
        cout << "Bottom Element: " << bottomValue << endl;
        return;
    };

    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty!" << endl;
            return;
        };
        cout << "Queue: ";
        Node *temp = front;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    };

    bool isEmpty()
    {
        return front == NULL;
    }
};

int main()
{
    Queue Obj;
    Obj.enqueue(22);
    Obj.enqueue(222);
    Obj.enqueue(223);
    Obj.enqueue(225);
    Obj.enqueue(226);
    Obj.enqueue(227);

    Obj.display();

    Obj.dequeue();
    Obj.display();

    Obj.dequeue();
    Obj.display();

    Obj.dequeue();
    Obj.display();

    Obj.peek();

    return 0;
}