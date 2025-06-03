#include <iostream>
using namespace std;

struct Node
{
    int value;
    int priority;
    Node *next;
};

class PriorityQueue
{
private:
    Node *front;
    Node *rear;
    int count = 0;

public:
    PriorityQueue()
    {
        front = rear = nullptr; // nullptr == NULL
    };

    void enqueue(int value, int priority)
    {
        Node *newNode = new Node();
        if (newNode == NULL)
        {
            cout << "Queue is Full.";
        };
        newNode->value = value;
        newNode->priority = priority;
        newNode->next = NULL;
        if (front == NULL)
        {
            rear = front = newNode;
            count++;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
            count++;
        }
    };

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty!" << endl;
            return;
        }

        Node *temp = front, *prev = nullptr;
        Node *maxPriorityNode = front, *prevMax = nullptr;

        // Find the node with the highest priority
        while (temp != nullptr)
        {
            if (temp->priority > maxPriorityNode->priority)
            {
                maxPriorityNode = temp;
                prevMax = prev;
            }
            prev = temp;
            temp = temp->next;
        }

        // Remove the node from the linked list
        if (maxPriorityNode == front)
        {
            front = front->next; // Update front
        }
        else
        {
            prevMax->next = maxPriorityNode->next;
        }

        if (maxPriorityNode == rear)
        {
            rear = prevMax; // Update rear if needed
        }

        cout << "Dequeued: " << maxPriorityNode->value << " with priority " << maxPriorityNode->priority << endl;
        delete maxPriorityNode; 
        count--;
    };

    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty!" << endl;
            return;
        };
        cout << "Queue: "<<endl;
        Node *temp;
        temp = front;
        while (temp != nullptr)
        {
            cout << "Value: " << temp->value << " " << " Priority: " << temp->priority << endl;
            temp = temp->next;
        };
        cout << endl;
    };

    bool isEmpty()
    {
        return front == NULL;
    };

    int size()
    {
        return count;
    };
};

int main()
{
    PriorityQueue Obj;
    Obj.enqueue(12, 43);
    Obj.enqueue(14, 432);
    Obj.enqueue(125, 4334);
    Obj.enqueue(123, 4365);
    Obj.enqueue(121, 4399);

    Obj.display();
    
    Obj.dequeue();
    Obj.display();

    Obj.dequeue();
    Obj.display();
    
    Obj.dequeue();
    Obj.display();

    cout << "Size of Queue: " << Obj.size();
    return 0;
}