// enqueue(): Insert an element at the end of the queue.
// dequeue(): Remove and Return the first element of the queue, if the queue is not empty.
// peek(): Return the element of the queue without removing it, if the queue is not empty.

#include <iostream>
using namespace std;

class Queue
{
private:
    int arr[10];
    int front;
    int rear;

public:
    Queue()
    {
        front = -1;
        rear = -1;
    };

    void enqueue(int value)
    {
        if (isFull())
        {
            cout << "Stack is Full." << endl;
            return;
        }
        if (front == -1)
        {
            front = 0;
        }
        arr[++rear] = value;
    };

    int dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty.";
        };
        int removedValue = arr[front];

        for (int i = front; i < rear; i++)
        {
            arr[i] = arr[i + 1];
        };
        rear--;
        if (front > rear)
        {
            front = -1;
            rear = -1;
        };
        return removedValue;
    };

    int peek()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty!" << endl;
            return -1;
        };
        return arr[front];
    }

    bool isFull()
    {
        return rear == 9;
    };

    bool isEmpty()
    {
        return front == -1 || front > rear;
    };

    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty!" << endl;
            return;
        };
        cout << "Queue: ";
        for (int i = front; i <= rear; i++)
        {
            cout << arr[i] << " ";
        };
        cout << endl;
    };
};

int main()
{
    Queue Obj;
    Obj.enqueue(10);
    Obj.enqueue(20);
    Obj.enqueue(30);
    Obj.display();

    cout << "Peek Front Element: " << Obj.peek() << endl;

    cout << "Dequeued Element: " << Obj.dequeue() << endl;
    Obj.display();

    cout << "Is Empty? " << (Obj.isEmpty() ? "Yes" : "No") << endl;
    cout << "Is Full? " << (Obj.isFull() ? "Yes" : "No") << endl;
    return 0;
}