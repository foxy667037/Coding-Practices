#include <iostream>
using namespace std;

class InsertionSort
{
public:
    void insertion_sort(int arr[], int size) // time complexity = O(n^2)
    {
        for (int i = 1; i < size; i++)
        {
            int currentElement = arr[i];
            int previousElement = i - 1;

            while (previousElement >= 0 && arr[previousElement] > currentElement)
            {
                arr[previousElement + 1] = arr[previousElement];
                previousElement--;
            }

            arr[previousElement + 1] = currentElement;
        }
    };
};

int main()
{
    int arr[5] = {10, 2, 4, 6, 23};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Unsorted Array: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    };

    InsertionSort Obj;
    Obj.insertion_sort(arr, size);
    cout << endl
         << "Sorted Array: ";

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    };

    return 0;
}