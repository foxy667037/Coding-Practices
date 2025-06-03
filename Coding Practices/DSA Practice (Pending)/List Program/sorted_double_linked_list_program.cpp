#include <iostream>
using namespace std;

struct Node
{
    Node *prev;
    int data;
    Node *next;
};

class SortedDoubleLinkedList
{
private:
    Node *head;
    Node *tail;
    int count;

public:
    SortedDoubleLinkedList()
    {
        head = tail = nullptr;
        count = 0;
    }
    void insertSorted(int value)
    {
        Node *newNode = new Node();
        if (!newNode)
        {
            cout << "Memory is Full.";
        };
        newNode->prev = nullptr;
        newNode->data = value;
        newNode->next = nullptr;
        if (head == nullptr)
        {
            head = tail = newNode;
        }
        else if (value < head->data)
        {
            newNode->next = head;
            head->prev = newNode;
            head=newNode;
        }
        else if (value < tail->data)
        {
            newNode->next = tail;
            tail->prev->next = newNode;
            newNode->prev = tail->prev;
            tail->prev = newNode;
        }
        else
        {
            Node *current = head;
            while (current->next != nullptr && current->next->data < value)
            {
                current = current->next;
            }
            newNode->next = current->next;
            newNode->prev = current;

            if (current->next != nullptr)
            {
                current->next->prev = newNode;
            }
            
            current->next = newNode;
        }
        count++;
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
        Node *temp = head;

        while (temp != nullptr)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    };
};
int main()
{
    SortedDoubleLinkedList Obj;
    Obj.insertSorted(1);
    Obj.insertSorted(2);
    Obj.insertSorted(3);
    Obj.insertSorted(4);
    Obj.insertSorted(7);
    Obj.insertSorted(6);
    Obj.insertSorted(0);

    Obj.display();
    return 0;
}