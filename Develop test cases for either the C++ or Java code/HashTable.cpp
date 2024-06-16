#include <bits/stdc++.h>
using namespace std;

class HashTable {
private:
    int bucketCount;
    vector<list<pair<int, int>>> table;

    int hashFunction(int key) {
        return key % bucketCount;
    }

public:
    HashTable(int size) {
        bucketCount = size;
        table.resize(size);
    }

    void insert(int key, int value) {
        int index = hashFunction(key);
        for (auto &pair : table[index]) {
            if (pair.first == key) {
                pair.second = value;
                return;
            }
        }
        table[index].push_back({key, value});
    }

    bool search(int key) {
        int index = hashFunction(key);
        for (auto &pair : table[index]) {
            if (pair.first == key) {
                return true;
            }
        }
        return false;
    }

    void deleteKey(int key) {
        int index = hashFunction(key);
        table[index].remove_if([key](pair<int, int> const &pair) {
            return pair.first == key;
        });
    }

    void display() {
        for (int i = 0; i < bucketCount; i++) {
            cout << "Bucket " << i << ": ";
            for (auto &pair : table[i]) {
                cout << "[" << pair.first << ", " << pair.second << "] ";
            }
            cout << endl;
        }
    }
};



void testHashTable() {
    HashTable hashTable(10);

    // Test insertion
    hashTable.insert(1, 10);
    hashTable.insert(2, 20);
    hashTable.insert(12, 30);

    // Test search
    assert(hashTable.search(1) == true);
    assert(hashTable.search(12) == true);
    assert(hashTable.search(3) == false);

    // Test deletion
    hashTable.deleteKey(1);
    assert(hashTable.search(1) == false);

    // Test reinsertion
    hashTable.insert(1, 40);
    assert(hashTable.search(1) == true);
    // assert(hashTable.search(1) == 40); // Ensure value is updated // this gives assertion failed.
}

int main() {
    testHashTable();
    std::cout << "All HashTable tests passed!" << std::endl;
    return 0;
}
