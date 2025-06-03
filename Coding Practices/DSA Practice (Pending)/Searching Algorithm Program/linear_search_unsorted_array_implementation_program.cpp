#include <iostream>
using namespace std;

// Function to search for an element in an unsorted array
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
};

int main()
{
    int arr[] = {7, 2, 15, 10, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target;
    cout << "Enter the number to search: ";
    cin >> target;

    int result = linearSearch(arr, size, target);

    if (result != -1)
    {
        cout << "Element found at index: " << result << endl;
    }
    else
    {
        cout << "Element not found in the array." << endl;
    }

    return 0;
}
