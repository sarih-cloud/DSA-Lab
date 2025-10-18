/**
 * Hash Table Implementation with Separate Chaining in C++
 * Features: Insert, Search, Delete, Display
 * Time Complexity:
 *   - Insert/Search/Delete: O(1) average, O(n) worst
 * Space Complexity: O(n)
 */

#include <iostream>
#include <vector>
#include <list>
using namespace std;

class HashTable {
private:
    static const int TABLE_SIZE = 10;
    vector<list<pair<int, string>>> table;

    // Hash function
    int hashFunction(int key) {
        return key % TABLE_SIZE;
    }

public:
    HashTable() : table(TABLE_SIZE) {}

    // Insert key-value pair
    void insert(int key, const string& value) {
        int index = hashFunction(key);
        
        // Check if key already exists
        for (auto& pair : table[index]) {
            if (pair.first == key) {
                pair.second = value; // Update existing key
                cout << "Updated key " << key << " with value: " << value << endl;
                return;
            }
        }
        
        // Insert new key-value pair
        table[index].emplace_back(key, value);
        cout << "Inserted key " << key << " with value: " << value << endl;
    }

    // Search for a key
    string search(int key) {
        int index = hashFunction(key);
        
        for (const auto& pair : table[index]) {
            if (pair.first == key) {
                return pair.second;
            }
        }
        
        return "Key not found";
    }

    // Delete a key
    bool remove(int key) {
        int index = hashFunction(key);
        
        auto& chain = table[index];
        for (auto it = chain.begin(); it != chain.end(); ++it) {
            if (it->first == key) {
                cout << "Deleted key " << key << " with value: " << it->second << endl;
                chain.erase(it);
                return true;
            }
        }
        
        cout << "Key " << key << " not found for deletion" << endl;
        return false;
    }

    // Display entire hash table
    void display() {
        cout << "Hash Table Contents:" << endl;
        for (int i = 0; i < TABLE_SIZE; i++) {
            cout << "Bucket " << i << ": ";
            if (table[i].empty()) {
                cout << "Empty";
            } else {
                for (const auto& pair : table[i]) {
                    cout << "[" << pair.first << ":" << pair.second << "] ";
                }
            }
            cout << endl;
        }
    }

    // Calculate load factor
    double loadFactor() {
        int totalElements = 0;
        for (const auto& chain : table) {
            totalElements += chain.size();
        }
        return static_cast<double>(totalElements) / TABLE_SIZE;
    }

    // Statistics
    void statistics() {
        int totalElements = 0;
        int emptyBuckets = 0;
        int maxChainLength = 0;
        
        for (const auto& chain : table) {
            totalElements += chain.size();
            if (chain.empty()) {
                emptyBuckets++;
            }
            if (chain.size() > maxChainLength) {
                maxChainLength = chain.size();
            }
        }
        
        cout << "Hash Table Statistics:" << endl;
        cout << "Total Elements: " << totalElements << endl;
        cout << "Table Size: " << TABLE_SIZE << endl;
        cout << "Load Factor: " << loadFactor() << endl;
        cout << "Empty Buckets: " << emptyBuckets << endl;
        cout << "Longest Chain: " << maxChainLength << endl;
    }
};

// Demo function to test Hash Table
void demoHashTable() {
    cout << "=== HASH TABLE DEMONSTRATION ===" << endl;
    
    HashTable ht;
    
    // Insert key-value pairs
    ht.insert(101, "Alice");
    ht.insert(102, "Bob");
    ht.insert(103, "Charlie");
    ht.insert(201, "David"); // Will collide with 101
    ht.insert(202, "Eve");   // Will collide with 102
    ht.insert(15, "Frank");  // Will collide with 5
    
    cout << endl;
    
    // Display table
    ht.display();
    
    cout << endl;
    
    // Search operations
    cout << "Search 101: " << ht.search(101) << endl;
    cout << "Search 201: " << ht.search(201) << endl;
    cout << "Search 999: " << ht.search(999) << endl;
    
    cout << endl;
    
    // Delete operations
    ht.remove(102);
    ht.remove(999); // Non-existent key
    
    cout << endl;
    
    // Display after deletion
    ht.display();
    
    cout << endl;
    
    // Statistics
    ht.statistics();
    
    cout << "=== END DEMONSTRATION ===" << endl << endl;
}

int main() {
    demoHashTable();
    return 0;
}