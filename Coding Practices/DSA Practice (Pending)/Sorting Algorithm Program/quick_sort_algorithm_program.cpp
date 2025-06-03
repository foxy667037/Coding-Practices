#include <iostream>
#include <vector>
using namespace std;

class QuickSort
{
public:
    void quick_sort(vector<int> &arr, int strt, int end)
    {
        if (strt < end)
        {
            int pivotIdx = partition(arr, strt, end);
            quick_sort(arr, strt, pivotIdx - 1); // Sort left part
            quick_sort(arr, pivotIdx + 1, end);  // Sort right part
        }
    }

    int partition(vector<int> &arr, int strt, int end)
    {
        int initialPivot = arr[end]; 
        int low = strt - 1;

        for (int i = strt; i < end; i++)
        {
            if (arr[i] <= initialPivot)
            {
                low++;
                swap(arr[low], arr[i]);
            }
        }

        swap(arr[low + 1], arr[end]); // used to set the correct position of pivot
        return low + 1; // return pivot Index
    }
};

int main()
{
    vector<int> arr = {14, 5, 78, 3, 66};
    int sizeOfArr = arr.size();
    
    cout << "Unsorted Array: ";
    for (int num : arr)
    {
        cout << num << " ";
    }
    
    QuickSort Obj;
    Obj.quick_sort(arr, 0, sizeOfArr - 1);
    
    cout << endl
    << "Sorted Array: ";
    for (int num : arr)
    {
        cout << num << " ";
    }
    
    return 0;
}
