#include <iostream>
using namespace std;

struct Node
{
    Node *prev;
    int data;
    Node *next;
};

class DoubleLinkedList
{
private:
    Node *head;
    Node *tail;
    int count;

public:
    DoubleLinkedList()
    {
        head = tail = NULL;
    };

    void insert(int value)
    {
        Node *newNode = new Node();
        if (!newNode)
        {
            cout << "Memory Full" << endl;
        };

        newNode->prev = NULL;
        newNode->data = value;
        newNode->next = NULL;
        if (head == nullptr)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        count++;
    };

    void remove(int value)
    {
        if (isEmpty())
        {
            cout << "List is Empty." << endl;
            return;
        }

        int deletedValue = value;

        // Case 1: Deleting head node
        if (head->data == deletedValue)
        {
            Node *temp = head;
            head = head->next;

            if (head)
            {
                head->prev = nullptr;
            }
            if (head == nullptr)
            {
                tail = nullptr;
            }

            cout << "Deleted Value: " << temp->data << endl;
            delete temp;
            count--;
            return;
        }

        // Case 2: Deleting tail node
        if (tail->data == deletedValue)
        {
            Node *temp = tail;
            tail = tail->prev;

            if (tail)
            {
                tail->next = nullptr;
            }
            if (tail == nullptr)
            {
                head = nullptr;
            }

            cout << "Deleted Value: " << temp->data << endl;
            delete temp;
            count--;
            return;
        }

        // Case 3: Deleting a middle node
        Node *start = head;
        Node *nodeStartData = nullptr;

        while (start != nullptr && start->data != deletedValue)
        {
            nodeStartData = start;
            start = start->next;
        }

        // If value not found
        if (start == nullptr)
        {
            cout << "Value not found in the list." << endl;
            return;
        }

        // Update links
        nodeStartData->next = start->next;
        if (start->next)
        {
            start->next->prev = nodeStartData;
        }

        cout << "Deleted Value: " << start->data << endl;
        delete start;
        count--;
    };

    void replace(int firstValue, int changeValue)
    {
        if (isEmpty())
        {
            cout << "List is Empty." << endl;
            return;
        }

        bool found = false;
        Node *start = head;

        while (start != nullptr)
        {
            if (start->data == firstValue)
            {
                cout << "Old Value: " << firstValue << " New Value: " << changeValue << endl;
                start->data = changeValue;
                found = true;
            }
            start = start->next;
        };

        if (!found)
        {
            cout << "Value not found in the list." << endl;
        };
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
        while (temp != nullptr)
        {
            cout << "Previous Address: " << temp->prev << " Data: " << temp->data << " Next Address: " << temp->next << endl;
            temp = temp->next;
        }
    };
};

int main()
{
    DoubleLinkedList Obj;
    Obj.insert(1);
    Obj.insert(2);
    Obj.insert(3);
    Obj.insert(4);
    Obj.insert(5);

    Obj.display();

    Obj.remove(3);
    Obj.display();

    Obj.replace(4, 3);
    Obj.display();

    return 0;
}