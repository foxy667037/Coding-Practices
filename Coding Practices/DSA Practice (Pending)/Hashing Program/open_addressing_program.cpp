
#include <iostream>
#include <vector>

using namespace std;

enum ProbingType { LINEAR, QUADRATIC, DOUBLE_HASH };

class HashTable {
private:
    vector<pair<int, string>> table;
    vector<bool> occupied; 
    int size;
    ProbingType probingType;

    // Hash functions
    int HashFunction(int key) {
        return key % size;
    }

    // Secondary hash function for double hashing
    int SecondHashFunction(int key) {
        return (7 - (key % 7)); // A prime number smaller than table size
    }

public:
    // Constructor
    HashTable(int size, ProbingType type) {
        this->size = size;
        this->probingType = type;
        table.resize(size, {-1, ""});
        occupied.resize(size, false);
    }

    // Insert function
    void insert(int key, string value) {
        int index = HashFunction(key);
        int iterative = 0;

        while (occupied[index]) { // Find next available slot
            if (table[index].first == key) {
                table[index].second = value; // Update if key already exists
                return;
            }

            // Apply different probing techniques
            if (probingType == LINEAR) {
                index = (index + 1) % size;
            } else if (probingType == QUADRATIC) {
                index = (index + iterative * iterative) % size;
            } else if (probingType == DOUBLE_HASH) {
                index = (index + iterative * SecondHashFunction(key)) % size;
            }
            iterative++;

            if (iterative >= size) {
                cout << "Table is full, cannot insert key: " << key << endl;
                return;
            }
        }

        table[index] = {key, value};
        occupied[index] = true;
    }

    // Search function
    string findKey(int key) {
        int index = HashFunction(key);
        int iterative = 0;

        while (occupied[index]) {
            if (table[index].first == key) {
                return table[index].second;
            }

            // Apply probing techniques
            if (probingType == LINEAR) {
                index = (index + 1) % size;
            } else if (probingType == QUADRATIC) {
                index = (index + iterative * iterative) % size;
            } else if (probingType == DOUBLE_HASH) {
                index = (index + iterative * SecondHashFunction(key)) % size;
            }
            iterative++;

            if (iterative >= size) {
                break;
            }
        }
        return "Not Found";
    }

    // Delete function
    string deleteValue(int key) {
        int index = HashFunction(key);
        int iterative = 0;

        while (occupied[index]) {
            if (table[index].first == key) {
                table[index] = {-1, ""};
                occupied[index] = false;
                return "Data Deleted.";
            }

            // Apply probing techniques
            if (probingType == LINEAR) {
                index = (index + 1) % size;
            } else if (probingType == QUADRATIC) {
                index = (index + iterative * iterative) % size;
            } else if (probingType == DOUBLE_HASH) {
                index = (index + iterative * SecondHashFunction(key)) % size;
            }
            iterative++;

            if (iterative >= size) {
                break;
            }
        }
        return "Not Found.";
    }

    // Display the hash table
    void display() {
        for (int i = 0; i < size; i++) {
            cout << "Bucket " << i << ": ";
            if (occupied[i]) {
                cout << "(" << table[i].first << ", " << table[i].second << ")";
            } else {
                cout << "NULL";
            }
            cout << endl;
        }
    }
};

int main() {
    cout << "\nUsing Linear Probing:\n";
    HashTable linearTable(7, LINEAR);
    linearTable.insert(10, "A");
    linearTable.insert(20, "B");
    linearTable.insert(24, "C");
    linearTable.insert(14, "D");
    linearTable.insert(9, "E");
    linearTable.display();

    cout << "\nUsing Quadratic Probing:\n";
    HashTable quadraticTable(7, QUADRATIC);
    quadraticTable.insert(10, "A");
    quadraticTable.insert(20, "B");
    quadraticTable.insert(24, "C");
    quadraticTable.insert(14, "D");
    quadraticTable.insert(9, "E");
    quadraticTable.display();

    cout << "\nUsing Double Hashing:\n";
    HashTable doubleHashTable(7, DOUBLE_HASH);
    doubleHashTable.insert(10, "A");
    doubleHashTable.insert(20, "B");
    doubleHashTable.insert(24, "C");
    doubleHashTable.insert(14, "D");
    doubleHashTable.insert(9, "E");
    doubleHashTable.display();

    return 0;
}
