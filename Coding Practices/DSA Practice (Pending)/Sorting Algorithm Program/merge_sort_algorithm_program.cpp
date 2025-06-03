#include <iostream>
#include <vector>
using namespace std;

class MergeSort
{

public:
    void merge(vector<int> &arr, int strt, int mid, int end)
    {
        vector<int> tempArr;
        int leftStart = strt;
        int rightStart = mid + 1;
        while (leftStart <= mid && rightStart <= end)
        {
            if (arr[leftStart] <= arr[rightStart])
            {
                tempArr.push_back(arr[leftStart]);
                leftStart++;
            }
            else
            {
                tempArr.push_back(arr[rightStart]);
                rightStart++;
            }
        };

        while (leftStart <= mid)
        {
            tempArr.push_back(arr[leftStart]);
            leftStart++;
        }

        while (rightStart <= end)
        {
            tempArr.push_back(arr[rightStart]);
            rightStart++;
        }

        for (int idx = 0; idx < tempArr.size(); idx++)
        {
            arr[strt + idx] = tempArr[idx];
        };
    };

    void merge_sort(vector<int> &arr, int strt, int end)
    {
        if (strt < end)
        {
            int midOfArr = strt + (end - strt) / 2;

            merge_sort(arr, strt, midOfArr);       // left side of array
            merge_sort(arr, midOfArr + 1, end); // right sort of array

            merge(arr, strt, midOfArr, end);
        };
    }
};

int main()
{
    vector<int> arr = {54, 65, 23, 77, 34};
    int sizeOfArr = arr.size();

    cout << "Unsorted Array: ";
    for (int num : arr)
    {
        cout << num << " ";
    }

    MergeSort Obj;
    Obj.merge_sort(arr, 0, sizeOfArr - 1);

    cout << endl
         << "Sorted Array: ";
    for (int num : arr)
    {
        cout << num << " ";
    }

    return 0;
}