#include <iostream>
using namespace std;

struct Node
{
    int value;
    Node *next;
};

class SingleLinkedList
{
private:
    Node *head;
    int count;

public:
    SingleLinkedList()
    {
        head = nullptr;
        count = 0;
    }

    void insert(int value)
    {
        Node *newNode = new Node();
        if (!newNode)
        {
            cout << "Limit is Full, Cannot insert." << endl;
            return;
        }
        newNode->value = value;
        newNode->next = nullptr;

        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            Node *temp = head;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        count++;
    }

    void remove(int value)
    {
        if (isEmpty())
        {
            cout << "List is Empty.";
            return;
        };
        Node *current = head;
        Node *prev = nullptr;

        // If the head node contains the value to be deleted
        if (head->value == value)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
            count--;
            cout << "Deleted Value: " << temp->value << endl;
            return;
        }

        while (current != nullptr && current->value != value)
        {
            prev = current;
            current = current->next;
        }

        // If the value was not found
        if (current == nullptr)
        {
            cout << "Value not found in the list." << endl;
            return;
        }

        prev->next = current->next;
        cout << "Deleted Value: " << current->value << endl;
        delete current;
        count--;
    };

    void replace(int originalValue, int replaceValue)
    {
        if (isEmpty())
        {
            cout << "List is Empty.";
            return;
        };

        // If the head node contains the value to be deleted
        if (head->value == originalValue)
        {
            Node *temp = head;
            head->value = replaceValue;
            cout << "Value Updated: " << temp->value << " to " << head->value << endl;
            delete temp;
            return;
        };

        // If the value was not found
        if (head == nullptr)
        {
            cout << "Value not found in the list." << endl;
            return;
        }

        Node *current = head;
        while (current != nullptr)
        {
            if (current->value == originalValue)
            {
                cout << "Value Updated: " << current->value << " to " << replaceValue << endl;
                current->value = replaceValue;
                delete current;
            }
            current = current->next;
        }
    }

    void display()
    {
        if (head == nullptr)
        {
            cout << "List is Empty!" << endl;
            return;
        }

        Node *temp = head;
        cout << "Linked List: ";
        while (temp != nullptr)
        {
            cout << temp->value << " ";
            temp = temp->next;
        }
        cout << endl;
    };

    int size()
    {
        return count;
    }

    bool isEmpty()
    {
        return head == nullptr;
    };
};

int main()
{
    SingleLinkedList Obj;
    Obj.insert(1);
    Obj.insert(2);
    Obj.insert(3);
    Obj.insert(4);
    Obj.insert(5);
    Obj.insert(6);

    Obj.display();
    cout << "Size of Linked List: " << Obj.size() << endl;

    Obj.remove(5);

    Obj.display();
    cout << "Size of Linked List: " << Obj.size() << endl;

    Obj.replace(6, 5);
    Obj.display();
    cout << "Size of Linked List: " << Obj.size() << endl;

    return 0;
}