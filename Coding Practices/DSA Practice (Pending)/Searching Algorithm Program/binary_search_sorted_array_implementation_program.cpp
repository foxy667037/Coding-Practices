#include <iostream>
#include <vector>
using namespace std;

// Bubble Sort Function
void BubbleSort(vector<int> &arr, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Binary Search Function (Recursive)
int BinarySearchRecursive(vector<int> &arr, int strt, int end, int target)
{
    if (strt > end)
    {
        cout << endl
             << "Target Value Does Not Exist.";
        return -1;
    }

    int midOfArr = strt + (end - strt) / 2;

    if (arr[midOfArr] == target)
    {
        cout << endl
             << "The Element " << target << " is found at index: " << midOfArr;
        return midOfArr;
    }
    else if (target < arr[midOfArr])
    {
        return BinarySearchRecursive(arr, strt, midOfArr - 1, target);
    }
    else
    {
        return BinarySearchRecursive(arr, midOfArr + 1, end, target);
    }
}

// Binary Search Function (Without Recursive)
int BinarySearchSimple(vector<int> &arr, int strt, int end, int target)
{
    while (strt <= end)
    {
        int mid = strt + (end - strt) / 2;

        if (target == arr[mid])
        {
            return mid;
        }
        else if (target < arr[mid])
        {
            end = mid - 1;
        }
        else
        {
            strt = mid + 1;
        }
    }

    return -1;
}

int main()
{
    vector<int> arr = {3, 5, 7, 2, 4};
    int sizeOfArr = arr.size();
    int target = 2;

    cout << endl
         << "Unsorted Array: ";
    for (int i = 0; i < sizeOfArr; i++)
    {
        cout << arr[i] << " ";
    }

    // Sorting array using Bubble Sort
    BubbleSort(arr, sizeOfArr);

    cout << endl
         << "Sorted Array: ";
    for (int i = 0; i < sizeOfArr; i++)
    {
        cout << arr[i] << " ";
    }

    // Binary Search (Recursive)
    BinarySearchRecursive(arr, 0, sizeOfArr - 1, target);

    // Binary Search (Simple)
    int result = BinarySearchSimple(arr, 0, sizeOfArr - 1, target);
    if (result == -1)
    {
        cout << endl
             << "Target Not Found";
    }
    else
    {
        cout << endl
             << "Target Found at index: " << result;
    }

    return 0;
}
