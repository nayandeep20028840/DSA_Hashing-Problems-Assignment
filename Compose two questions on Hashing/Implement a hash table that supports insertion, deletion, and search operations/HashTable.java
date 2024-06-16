import java.util.LinkedList;

class HashTable {
    private int bucketCount;
    private LinkedList<Entry>[] table;

    static class Entry {
        int key;
        int value;

        Entry(int key, int value) {
            this.key = key;
            this.value = value;
        }
    }

    public HashTable(int size) {
        bucketCount = size;
        table = new LinkedList[size];
        for (int i = 0; i < size; i++) {
            table[i] = new LinkedList<>();
        }
    }

    private int hashFunction(int key) {
        return key % bucketCount;
    }

    public void insert(int key, int value) {
        int index = hashFunction(key);
        for (Entry entry : table[index]) {
            if (entry.key == key) {
                entry.value = value;
                return;
            }
        }
        table[index].add(new Entry(key, value));
    }

    public boolean search(int key) {
        int index = hashFunction(key);
        for (Entry entry : table[index]) {
            if (entry.key == key) {
                return true;
            }
        }
        return false;
    }

    public void deleteKey(int key) {
        int index = hashFunction(key);
        table[index].removeIf(entry -> entry.key == key);
    }

    public void display() {
        for (int i = 0; i < bucketCount; i++) {
            System.out.print("Bucket " + i + ": ");
            for (Entry entry : table[i]) {
                System.out.print("[" + entry.key + ", " + entry.value + "] ");
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        HashTable hashTable = new HashTable(10);
        hashTable.insert(1, 10);
        hashTable.insert(2, 20);
        hashTable.insert(12, 30);

        System.out.println("Search 1: " + hashTable.search(1));
        System.out.println("Search 12: " + hashTable.search(12));
        System.out.println("Search 3: " + hashTable.search(3));

        hashTable.deleteKey(1);
        System.out.println("Search 1 after deletion: " + hashTable.search(1));

        hashTable.display();
    }
}
