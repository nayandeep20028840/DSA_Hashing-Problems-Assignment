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

int main() {
    HashTable hashTable(10);
    hashTable.insert(1, 10);
    hashTable.insert(2, 20);
    hashTable.insert(12, 30);

    cout << "Search 1: " << hashTable.search(1) << endl;
    cout << "Search 12: " << hashTable.search(12) << endl;
    cout << "Search 3: " << hashTable.search(3) << endl;

    hashTable.deleteKey(1);
    cout << "Search 1 after deletion: " << hashTable.search(1) << endl;

    hashTable.display();

    return 0;
}
