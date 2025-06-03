#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

class Deque
{
private:
    Node *front;
    Node *rear;
    int count;

public:
    Deque()
    {
        front = rear = nullptr;
    };

    void rearEnque(int value)
    {
        Node *newNode = new Node();
        if (newNode == NULL)
        {
            cout << "Queue is Full.";
        };
        newNode->data = value;
        newNode->next = nullptr;
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

    void frontEnque(int value)
    {
        Node *newNode = new Node();
        if (!newNode)
        {
            cout << "Queue is Full." << endl;
            return;
        }
        newNode->data = value;
        newNode->next = front;
        front = newNode;
        if (rear == nullptr)
        {
            front = rear = newNode;
        }
    };

    void frontDeque()
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
        cout << "Front Deque Element: " << dequeuedValue << endl;
        return;
    };

    void rearDeque()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty." << endl;
            return;
        }

        int rearDequeValue = rear->data;
        if (front == rear)
        {
            delete rear;
            front = rear = nullptr;
        }
        else
        {
            Node *temp = front;
            while (temp->next != rear)
            {
                temp = temp->next;
            }
            delete rear;
            rear = temp;
            rear->next = nullptr;
        }
        cout << "Rear Deque Value: " << rearDequeValue << endl;
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty.";
            return;
        };
        cout << "Deque: ";
        Node *temp = front;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    bool isEmpty()
    {
        return front == nullptr;
    }
};

int main()
{
    Deque Obj;
    Obj.rearEnque(1);
    Obj.rearEnque(2);
    Obj.rearEnque(3);

    Obj.display();

    Obj.frontDeque();
    Obj.display();

    Obj.frontEnque(0);
    Obj.display();

    Obj.rearDeque();
    Obj.display();

    return 0;
}