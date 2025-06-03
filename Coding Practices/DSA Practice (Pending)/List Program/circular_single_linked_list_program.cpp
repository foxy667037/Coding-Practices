#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

class CircularSingleLinkedList
{
private:
    Node *head;
    int count;

public:
    CircularSingleLinkedList()
    {
        head = nullptr;
        count = 0;
    }

    void insert(int value)
    {
        Node *newNode = new Node();
        if (!newNode)
        {
            cout << "Memory is Full." << endl;
            return;
        }
        newNode->data = value;
        newNode->next = nullptr;

        if (head == nullptr)
        {
            head = newNode;
            newNode->next = head;
        }
        else
        {
            Node *temp = head;
            while (temp->next != head)
            {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
        count++;
    }

    void remove(int value)
    {
        if (isEmpty())
        {
            cout << "List is empty" << endl;
            return;
        }

        Node *current = head;
        Node *prev = nullptr;

        // Case 1: If the head needs to be deleted
        if (head->data == value)
        {
            Node *tail = head;
            while (tail->next != head)
            {
                tail = tail->next;
            }
            tail->next = head->next;
            Node *temp = head;
            head = head->next;
            cout << "Deleted Value: " << temp->data << endl;
            delete temp;

            if (head == temp)
            {
                head = nullptr;
            }
            return;
        }

        // Case 2: Deleting a middle or last node
        do
        {
            prev = current;
            current = current->next;
        } while (current != head && current->data != value);

        if (current == head) // Value not found
        {
            cout << "Value not found in the list." << endl;
            return;
        }

        prev->next = current->next;
        cout << "Deleted Value: " << current->data << endl;
        delete current;
    }

    bool isEmpty()
    {
        return head == nullptr;
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "List is Empty." << endl;
            return;
        };

        Node *temp = head;
        do
        {
            cout << "Data: " << temp->data << " Next Address: " << temp->next << endl;
            temp = temp->next;
        } while (temp != head);
    };
};

int main()
{
    CircularSingleLinkedList Obj;
    Obj.insert(1);
    Obj.insert(2);
    Obj.insert(3);
    Obj.insert(4);

    Obj.display();

    Obj.remove(3);
    Obj.display();
    return 0;
}
