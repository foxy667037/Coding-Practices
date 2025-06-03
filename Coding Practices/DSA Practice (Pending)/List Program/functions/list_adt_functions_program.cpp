#include <iostream>
using namespace std;

class List
{
private:
    int arr[100];
    int size; // Tracks the number of elements

public:
    // Constructor
    List()
    {
        size = 0;
    }

    // Get element at a specific position
    int get(int index)
    {
        if (index >= 0 && index < size)
        {
            return arr[index];
        }
        cout << "Index out of bounds!" << endl;
        return -1;
    }

    // Insert element at a specific position
    void insert(int index, int value)
    {
        if (index < 0 || index > size || size >= 100)
        {
            cout << "Insertion not possible!" << endl;
            return;
        }
        for (int i = size; i > index; i--)
        {
            arr[i] = arr[i - 1]; // Shift elements
        }
        arr[index] = value;
        size++;
    }

    // Remove first occurrence of an element
    void remove(int value)
    {
        int index = -1;
        for (int i = 0; i < size; i++)
        {
            if (arr[i] == value)
            {
                index = i;
                break;
            }
        }
        if (index == -1)
        {
            cout << "Element not found!" << endl;
            return;
        }
        removeAt(index);
    }

    // Remove element at a specified index
    void removeAt(int index)
    {
        if (index < 0 || index >= size)
        {
            cout << "Index out of bounds!" << endl;
            return;
        }
        for (int i = index; i < size - 1; i++)
        {
            arr[i] = arr[i + 1]; // Shift elements
        }
        size--;
    }

    // Replace an element at a specific index
    void replace(int index, int newValue)
    {
        if (index >= 0 && index < size)
        {
            arr[index] = newValue;
        }
        else
            cout << "Index out of bounds!" << endl;
    }

    // Get the size of the list
    int getSize()
    {
        return size;
    }

    // Check if the list is empty
    bool isEmpty()
    {
        return size == 0;
    }

    // Check if the list is full
    bool isFull()
    {
        return size == 100;
    }

    // Display the list
    void display()
    {
        cout << "List: ";
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

// Main function to test the List ADT
int main()
{
    List myList;

    myList.insert(0, 10);
    myList.insert(1, 20);
    myList.insert(2, 30);
    myList.insert(1, 50);
    myList.display();

    cout << "Element at index 1: " << myList.get(1) << endl;

    myList.replace(1, 25);
    myList.display();

    myList.remove(10);
    myList.display();

    myList.removeAt(1);
    myList.display();

    cout << "Size of list: " << myList.getSize() << endl;
    cout << "Is empty? " << (myList.isEmpty() ? "Yes" : "No") << endl;
    cout << "Is full? " << (myList.isFull() ? "Yes" : "No") << endl;

    return 0;
}
