#include <iostream>
using namespace std;

struct Node
{
    Node *prev;
    int data;
    Node *next;
};

class CircularDoubledLinkedList
{
private:
    Node *head;
    Node *tail;
    int count;

public:
    CircularDoubledLinkedList()
    {
        head = tail = nullptr;
        count = 0;
    };

    void insert(int value)
    {
        Node *newNode = new Node();
        if (!newNode)
        {
            cout << "Memory is Full.";
            return;
        };
        newNode->prev = nullptr;
        newNode->data = value;
        newNode->next = nullptr;
        if (head == nullptr)
        {
            head = tail = newNode;
            newNode->next = newNode;
            newNode->prev = newNode;
        }
        else
        {
            newNode->next = head;
            newNode->prev = tail;
            tail->next = newNode;
            head->prev = newNode;
            tail = newNode;
            count++;
        }
    };

    void remove(int value)
    {
        if (isEmpty())
        {
            cout << "List is Empty." << endl;
            return;
        };

        // case 1: if value is equal to head value
        if (head->data == value)
        {
            Node *temp = head;
            head = head->next;
            if (head)
            {
                head->prev = tail;
                tail->next = head;
            }
            if (head == nullptr)
            {
                tail = nullptr;
            }
            cout << "Deleted Value: " << temp->data << endl;
            delete temp;
            count--;
            return;
        };

        // case 2: if value is equal to tail value
        if (tail->data == value)
        {
            Node *temp = tail;
            tail = tail->prev;
            if (tail)
            {
                tail->next = head;
                head->prev = tail;
            }
            if (tail == nullptr)
            {
                head = nullptr;
            }
            cout << "Deleted Value: " << temp->data << endl;
            delete temp;
            count--;
            return;
        };

        // case 3: if value is equal to median value
        Node *start = head;
        Node *nodeData;

        do
        {
            nodeData = start;
            start = start->next;
        } while (start != head && start->data != value);

        // If value not found
        if (start == nullptr)
        {
            cout << "Value not found in the list." << endl;
            return;
        };

        nodeData->next = start->next;
        if (start->next)
        {
            start->next->prev = nodeData;
        }
    };

    int size()
    {
        return count;
    };

    bool isEmpty()
    {
        return head == nullptr;
    };

    void display()
    {
        if (isEmpty())
        {
            cout << "List is Empty." << endl;
            return;
        }

        Node *temp = head;
        do
        {
            cout << "Prev: " << temp->prev->data << " Data: " << temp->data << " Next: " << temp->next->data << endl;
            temp = temp->next;
        } while (temp != head);
    };
};

int main()
{
    CircularDoubledLinkedList Obj;
    Obj.insert(1);
    Obj.insert(2);
    Obj.insert(3);
    Obj.insert(4);

    Obj.display();

    Obj.remove(2);
    Obj.display();

    Obj.remove(3);
    Obj.display();

    return 0;
}