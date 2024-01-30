#include <iostream>

// Node class for linked list
class Node {
public:
    std::string key;
    std::string value;
    Node* next;

    Node(const std::string& k, const std::string& v) : key(k), value(v), next(NULL) {}
};

// HashTable class
class HashTable {
private:
    static const int num_buckets = 10; // Adjust the number of buckets as needed
    Node* buckets[num_buckets];

    // Hash function based on the sum of ASCII values
    int hash(const std::string& key) {
        int sum = 0;
        for (char c : key) {
            sum += static_cast<int>(c);
        }
        return sum % num_buckets;
    }

public:
    // Constructor initializes buckets
    HashTable() {
        for (int i = 0; i < num_buckets; ++i) {
            buckets[i] = nullptr;
        }
    }

    // Function to insert a key-value pair into the hash table
    void insert(const std::string& key, const std::string& value) {
        int index = hash(key);

        // Check if the key already exists in the bucket
        Node* current = buckets[index];
        while (current != nullptr) {
            if (current->key == key) {
                // Key found, update the value and return
                current->value = value;
                return;
            }
            current = current->next;
        }

        // Key not found, insert a new node at the beginning of the bucket's linked list
        Node* newNode = new Node(key, value);
        newNode->next = buckets[index];
        buckets[index] = newNode;
    }

    // Function to print the contents of the hash table
    void print() {
        for (int i = 0; i < num_buckets; ++i) {
            std::cout << "Bucket " << i << ": ";
            Node* current = buckets[i];
            while (current != nullptr) {
                std::cout << "(" << current->key << ", " << current->value << ") ";
                current = current->next;
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    HashTable myhash;

    myhash.insert("A", "aaaaa");
    myhash.insert("B", "bbbbb");
    myhash.insert("C", "ccccc");
    myhash.insert("A", "zzzzz");

    // Print the contents of the hash table
    myhash.print();

    return 0;
}

