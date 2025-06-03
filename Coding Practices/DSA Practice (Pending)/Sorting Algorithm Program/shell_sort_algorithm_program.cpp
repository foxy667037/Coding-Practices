#include <iostream>
#include <vector>
using namespace std;

class ShellSort
{
public:
    void shell_sort(vector<int> &arr, int size)
    {
        // Start with a large gap and reduce it
        for (int gap = size / 2; gap > 0; gap /= 2)
        {
            // Perform insertion sort for the current gap size
            for (int i = gap; i < size; i++)
            {
                int temp = arr[i];
                int j = i;

                // Shift elements of the sorted subarray to find the correct position for arr[i]
                while (j >= gap && arr[j - gap] > temp)
                {
                    arr[j] = arr[j - gap];
                    j -= gap;
                }

                // Place the element at its correct position
                arr[j] = temp;
            }
        }
    }
};

int main()
{
    vector<int> arr = {42, 34, 65, 67, 32, 21, 78, 56};
    int size = arr.size();

    cout << "Unsorted Array: ";
    for (int num : arr)
    {
        cout << num << " ";
    }

    ShellSort Obj;
    Obj.shell_sort(arr, size);

    cout << endl
         << "Sorted Array: ";
    for (int num : arr)
    {
        cout << num << " ";
    }

    return 0;
}
