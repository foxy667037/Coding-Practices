#include <iostream>
#include <vector>

using namespace std;

class BucketArray {
private:
    int size;
    vector<vector<pair<int, string>>> buckets; // Each bucket stores a list of (key, value) pairs

public:
    // Constructor to initialize bucket array with empty lists
    BucketArray(int size) {
        this->size = size;
        buckets.resize(size);
    }

    // Hash function: Modulo operation to get the index
    int hashFunction(int key) {
        return key % size;
    }

    // Insert key-value pair
    void insert(int key, string value) {
        int index = hashFunction(key);
        buckets[index].push_back({key, value}); // Store key-value pair in the correct bucket
    }

    // Get value by key
    string get(int key) {
        int index = hashFunction(key);
        for (auto &pair : buckets[index]) {
            if (pair.first == key)
                return pair.second; // Return value if key matches
        }
        return "Not Found"; // Return if key is not present
    }
};

int main() {
    BucketArray obj(5);

    obj.insert(10, "Apple");
    obj.insert(15, "Banana");
    obj.insert(20, "Cherry");

    cout << obj.get(10) << endl; // Output: Apple
    cout << obj.get(15) << endl; // Output: Banana
    cout << obj.get(30) << endl; // Output: Not Found

    return 0;
}
