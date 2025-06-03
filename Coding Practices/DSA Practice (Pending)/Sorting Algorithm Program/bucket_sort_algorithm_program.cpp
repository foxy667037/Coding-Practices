#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class BucketSort
{
public:
    void bucket_sort(vector<float> &arr)
    {
        int n = arr.size();
        vector<vector<float>> buckets(n); // Create n empty buckets

        // Put array elements into buckets
        for (int i = 0; i < n; i++)
        {
            int index = n * arr[i]; // Bucket index
            buckets[index].push_back(arr[i]);
        }

        // Sort individual buckets
        for (int i = 0; i < n; i++)
        {
            sort(buckets[i].begin(), buckets[i].end());
        }

        // Concatenate all buckets into original array
        int idx = 0;
        for (int i = 0; i < n; i++)
        {
            for (float num : buckets[i])
            {
                arr[idx++] = num;
            }
        }
    }
};

int main()
{
    vector<float> arr = {0.78, 0.17, 0.39, 0.26, 0.72, 0.94, 0.21, 0.12, 0.23, 0.68};

    cout << "Unsorted Array: ";
    for (float num : arr) cout << num << " ";

    BucketSort Obj;
    Obj.bucket_sort(arr);

    cout << "\nSorted Array: ";
    for (float num : arr) cout << num << " ";

    return 0;
}
