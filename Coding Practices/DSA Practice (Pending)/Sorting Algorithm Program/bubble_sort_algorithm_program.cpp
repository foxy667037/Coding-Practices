#include <iostream>
#include <vector>
using namespace std;

class BubbleSort
{
public:
    void bubble_sort(vector<int> &arr, int size)
    {
        for (int i = 0; i < size - 1; i++)
        {
            for (int j = 0; j < size - 1 - i; j++)
            {
                if (arr[j] > arr[j + 1])
                {
                    swap(arr[j], arr[j + 1]);
                }
            };
        };
    };
};

int main()
{
    vector<int> arr = {42, 34, 65, 67, 32};
    int size = arr.size();

    cout << "Unsorted Array: ";
    for (int num : arr)
    {
        cout << num << " ";
    }

    BubbleSort Obj;
    Obj.bubble_sort(arr, size);

    cout << endl
         << "Sorted Array: ";
    for (int num : arr)
    {
        cout << num << " ";
    }

    return 0;
}