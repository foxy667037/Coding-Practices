#include <iostream>
#include <vector>
using namespace std;

class HeapSort
{
public:
    // Function to heapify a subtree rooted at index i
    void heapify(vector<int> &arr, int n, int i)
    {
        int largest = i;    // Root as largest
        int left = 2 * i + 1;  // Left child
        int right = 2 * i + 2; // Right child

        // Check if left child is larger than root
        if (left < n && arr[left] > arr[largest])
        {
            largest = left;
        }

        // Check if right child is larger than current largest
        if (right < n && arr[right] > arr[largest])
        {
            largest = right;
        }

        // If largest is not root, swap and heapify again
        if (largest != i)
        {
            swap(arr[i], arr[largest]);
            heapify(arr, n, largest);
        }
    }

    // Function to perform heap sort
    void heap_sort(vector<int> &arr)
    {
        int size = arr.size();

        // Step 1: Build max heap (rearrange array)
        for (int i = size / 2 - 1; i >= 0; i--)
        {
            heapify(arr, size, i);
        }

        // Step 2: Extract elements from heap one by one
        for (int i = size - 1; i > 0; i--)
        {
            swap(arr[0], arr[i]); // Move current root to end
            heapify(arr, i, 0);   // Heapify the reduced heap
        }
    }
};

int main()
{
    vector<int> arr = {14, 5, 78, 3, 66};
    
    cout << "Unsorted Array: ";
    for (int num : arr)
    {
        cout << num << " ";
    }

    HeapSort Obj;
    Obj.heap_sort(arr);

    cout << endl
         << "Sorted Array: ";
    for (int num : arr)
    {
        cout << num << " ";
    }

    return 0;
}
