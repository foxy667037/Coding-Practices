// for sorting we use selection algorithm
#include <iostream>
using namespace std;

// Corrected Selection Sort Function
void selectionSort(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        int maxIdx = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[maxIdx] > arr[j])
            {
                swap(arr[maxIdx], arr[j]);
            };
        };
    };
}

// Function to search for an element in an array
int linearSearch(int arr[], int size, int target)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == target)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int arr[5] = {1, 4, 7, 2, 9};
    int target = 2;
    int sizeOfArr = sizeof(arr) / sizeof(arr[0]);

    cout << endl
         << "Unsorted Array: ";
    for (int i = 0; i < sizeOfArr; i++)
    {
        cout << arr[i] << " ";
    }

    selectionSort(arr, sizeOfArr);

    cout << endl
         << "Sorted Array: ";
    for (int i = 0; i < sizeOfArr; i++)
    {
        cout << arr[i] << " ";
    }

    // Perform linear search
    int index = linearSearch(arr, sizeOfArr, target);
    if (index != -1)
        cout << endl
             << "Element " << target << " found at index " << index;
    else
        cout << endl
             << "Element " << target << " not found in the array.";

    return 0;
}
