#include <iostream>
#include <vector>
using namespace std;

// Function to get the maximum element in the array
int getMax(vector<int> &arr)
{
    int maxVal = arr[0];
    for (int num : arr)
    {
        if (num > maxVal)
            maxVal = num;
    }
    return maxVal;
}

// Counting Sort used in Radix Sort (for a specific digit place)
void countingSort(vector<int> &arr, int exp)
{
    int size = arr.size();
    vector<int> output(size);
    int count[10] = {0}; // To store count of occurrences (digits 0-9)

    // Count occurrences of digits at the given place (exp)
    for (int i = 0; i < size; i++)
    {
        int digit = (arr[i] / exp) % 10;
        count[digit]++;
    }

    // Update count[i] to store the position of this digit in output[]
    for (int i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    }

    // Build the sorted output array
    for (int i = size - 1; i >= 0; i--)
    {
        int digit = (arr[i] / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    // Copy sorted output back to the original array
    for (int i = 0; i < size; i++)
    {
        arr[i] = output[i];
    }
}

// Main function for Radix Sort
void radix_sort(vector<int> &arr)
{
    int maxVal = getMax(arr); // Get the maximum number

    // Apply counting sort for each digit (units, tens, hundreds, etc.)
    for (int exp = 1; maxVal / exp > 0; exp *= 10)
    {
        countingSort(arr, exp);
    }
}

int main()
{
    vector<int> arr = {170, 45, 75, 90, 802, 24, 2, 66};

    cout << "Unsorted Array: ";
    for (int num : arr)
    {
        cout << num << " ";
    }

    radix_sort(arr);

    cout << endl
         << "Sorted Array: ";
    for (int num : arr)
    {
        cout << num << " ";
    }

    return 0;
}
