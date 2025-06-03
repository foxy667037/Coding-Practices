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

    bool isFull()
    {
        return rear == 9;
    }

    bool isEmpty()
    {
        return front == -1 || front > rear;
    }

    void enqueue(int value)
    {
        if (isFull())
        {
            cout << "Queue is Full!" << endl;
            return;
        };
        if (front == -1)
        {
            front = 0;
        };
        arr[++rear] = value;
    }

    void peek()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty.";
            return;
        };
        cout << endl
             << "Peek Value: " << arr[front];
        return;
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty.";
            return;
        };
        int dequeuedValue = arr[front];
        for (int i = front; i <= rear; i++)
        {
            arr[i] = arr[i + 1];
        }
        rear--;

        cout << endl
             << "Dequeued Value: "
             << dequeuedValue;
        return;
    };

    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty.";
            return;
        };
        cout << endl
             << "Queue Values: ";
        for (int i = front; i <= rear; i++)
        {
            cout
                << arr[i]
                << " ";
        };
    };
};

int main()
{
    Queue Obj;

    Obj.enqueue(12);
    Obj.enqueue(122);
    Obj.enqueue(1223);
    Obj.enqueue(12233);
    Obj.display();

    Obj.peek();

    Obj.dequeue();
    Obj.display();

    Obj.dequeue();
    Obj.display();

    return 0;
}