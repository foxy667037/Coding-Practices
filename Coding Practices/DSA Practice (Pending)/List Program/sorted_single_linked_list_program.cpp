#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

class SortedSingleLinkedList
{
private:
    Node *head;
    int count;

public:
    SortedSingleLinkedList()
    {
        head = nullptr;
        count = 0;
    };

    void insertSort(int value)
    {
        Node *newNode = new Node();
        if (!newNode)
        {
            cout << "Memory is Full.";
        };
        newNode->data = value;
        newNode->next = nullptr;
        if (head == nullptr || value < head->data)
        {
            newNode->next = head;
            head = newNode;
        }
        else
        {

            Node *current = head;
            while (current->next != nullptr && current->next->data < value)
            {
                current = current->next;
            };
            newNode->next = current->next;
            current->next = newNode;
        }
        count++;
    };

    void remove(int value)
    {
        if (isEmpty())
        {
            cout << "List is Empty.";
            return;
        };
        Node *current = head;
        Node *prev = nullptr;

        if (head->data == value)
        {
            Node *temp = head;
            head=head->next;
            delete temp;
            count--;
            cout << "Deleted Value: " << temp->data << endl;
            return;
        }

        while(current != nullptr && current->data !=value){
            prev=current;
            current=current->next;
        };

         // If the value was not found
         if (current == nullptr)
         {
             cout << "Value not found in the list." << endl;
             return;
         }

         prev->next=current->next;
         cout << "Deleted Value: " << current->data << endl;
         delete current;
         count--;
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
    SortedSingleLinkedList Obj;
    Obj.insertSort(1);
    Obj.insertSort(2);
    Obj.insertSort(4);
    Obj.insertSort(3);
    Obj.insertSort(5);

    Obj.display();
    
    Obj.remove(4);
    Obj.display();
    return 0;
}