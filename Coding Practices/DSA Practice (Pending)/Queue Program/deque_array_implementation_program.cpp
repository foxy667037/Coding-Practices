#include <iostream>
using namespace std;

class Dequeue
{
private:
    int arr[10];
    int front;
    int rear;

public:
    Dequeue()
    {
        front = rear = -1;
    };

    void rearEnque(int value)
    {
        if (isFull())
        {
            cout << "Dequeue is Full.";
            return;
        };
        front = 0;
        arr[++rear] = value;
    };

    void frontEnque(int value)
    {
        if (isFull())
        {
            cout << "Dequeue is Full.";
            return;
        };
        if (isEmpty())
        {
            front = rear = 0;
            arr[front] = value;
        }
        else
        {
            for (int i = rear; i >= front; i--)
            {
                arr[i + 1] = arr[i];
            }
            arr[front] = value;
            rear++;
        }
    };

    void frontDeque()
    {
        if (isEmpty())
        {
            cout << "Dequeue is Empty.";
            return;
        };
        int frontDequeuedValue = arr[front];
        for (int i = front; i <= rear; i++)
        {
            arr[i] = arr[i + 1];
        };
        rear--;
        cout << endl
             << "Dequeued Value: "
             << frontDequeuedValue;
    };

    void rearDeque()
    {
        if (isEmpty())
        {
            cout << "Deque is Empty." << endl;
            return;
        }
        cout << "Rear Deque Value: " << arr[rear] << endl;

        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            rear--;
        }
    };

    void display()
    {
        if (isEmpty())
        {
            cout << "Dequeue is Empty.";
            return;
        };

        for (int i = front; i <= rear; i++)
        {
            cout << arr[i] << " ";
        };
    };

    bool isFull()
    {
        return rear == 9;
    };

    bool isEmpty()
    {
        return front == -1;
    };
};

int main()
{
    Dequeue Obj;
    cout << "Queue: ";
    Obj.rearEnque(1);
    Obj.rearEnque(2);
    Obj.rearEnque(3);
    Obj.rearEnque(4);

    Obj.display();

    Obj.frontEnque(0);
    Obj.display();

    return 0;
}