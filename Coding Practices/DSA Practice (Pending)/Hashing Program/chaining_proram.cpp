#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class HashTable {
private:
    int size;
    vector<unordered_map<int, string>> table;

public:
    // Constructor
    HashTable(int size) {
        this->size = size;
        table.resize(size);
    }

    // Hash function
    int HashFunction(int key) {
        return key % size;
    }

    // Insert data 
    void insert(int key, string value) {
        int index = HashFunction(key);
        table[index][key] = value; // Insert into the unordered_map at that index
    }

    // Retrieve data
    string findKey(int key) {
        int index = HashFunction(key);
        if (table[index].find(key) != table[index].end()) {
            return table[index][key];
        }
        return "Not Found";
    }

    // Delete a key
    string deleteValue(int key) {
        int index = HashFunction(key);
        if (table[index].find(key) != table[index].end()) {
            table[index].erase(key);
            return "Data Deleted.";
        }
        return "Not Found.";
    }

    // Display the hash table
    void display() {
        for (int i = 0; i < size; i++) {
            cout << "Bucket " << i << ": ";
            for (auto &pair : table[i]) {
                cout << "(" << pair.first << ", " << pair.second << ") -> ";
            }
            cout << "NULL\n";
        }
    }
};

int main() {
    HashTable Obj(5);
    Obj.insert(10, "foxy");
    Obj.insert(20, "foxy2");
    Obj.insert(24, "foxy3");
    Obj.insert(14, "foxy4");
    Obj.insert(9, "foxy5");

    cout << "\n--- Hash Table ---\n";
    Obj.display();

    cout << "\nDeleting key 14...\n";
    Obj.deleteValue(14);

    cout << "\n--- Updated Hash Table ---\n";
    Obj.display();

    cout << "\nFinding key 24: " << Obj.findKey(24) << endl;

    return 0;
}