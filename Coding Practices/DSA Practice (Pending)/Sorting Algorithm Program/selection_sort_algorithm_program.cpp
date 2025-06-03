#include <iostream>
using namespace std;

class SelectionSort
{
public:
    void selection_sort(int arr[], int size)
    {
        for (int i = 0; i < size; i++)
        {
            int smallestIndex = i;
            for (int j = i + 1; j < size; j++)
            {
                if (arr[j] < arr[smallestIndex])
                {
                    smallestIndex = j;
                };
            };
            swap(arr[i], arr[smallestIndex]);
        };
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

    SelectionSort Obj;
    Obj.selection_sort(arr, size);

    cout << endl
         << "Sorted Array: ";

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    };
    return 0;
}