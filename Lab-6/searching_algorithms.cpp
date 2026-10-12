/**
 * Searching Algorithms Implementation in C++
 * Includes: Linear Search, Binary Search (Iterative & Recursive)
 * Time Complexity Analysis for each algorithm
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class SearchingAlgorithms {
public:
    // Linear Search - O(n)
    int linearSearch(const vector<int>& arr, int target) {
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == target) {
                return i;
            }
        }
        return -1;
    }
    
    // Binary Search (Iterative) - O(log n)
    int binarySearchIterative(const vector<int>& arr, int target) {
        int left = 0;
        int right = arr.size() - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (arr[mid] == target) {
                return mid;
            } else if (arr[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return -1;
    }
    
    // Binary Search (Recursive) - O(log n)
    int binarySearchRecursive(const vector<int>& arr, int target, int left, int right) {
        if (left > right) return -1;
        
        int mid = left + (right - left) / 2;
        
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            return binarySearchRecursive(arr, target, mid + 1, right);
        } else {
            return binarySearchRecursive(arr, target, left, mid - 1);
        }
    }
    
    // Display search result
    void displayResult(int index, int target, const string& algorithm) {
        if (index != -1) {
            cout << algorithm << ": Found " << target << " at index " << index << endl;
        } else {
            cout << algorithm << ": " << target << " not found" << endl;
        }
    }
};

void demoSearchingAlgorithms() {
    cout << "=== SEARCHING ALGORITHMS DEMONSTRATION ===" << endl;
    
    SearchingAlgorithms searcher;
    vector<int> arr = {2, 5, 8, 12, 16, 23, 38, 45, 67, 89};
    vector<int> targets = {23, 45, 10, 89};
    
    cout << "Array: ";
    for (int num : arr) cout << num << " ";
    cout << endl << endl;
    
    for (int target : targets) {
        cout << "Searching for " << target << ":" << endl;
        
        // Linear Search
        int linearResult = searcher.linearSearch(arr, target);
        searcher.displayResult(linearResult, target, "Linear Search");
        
        // Binary Search Iterative
        int binaryIterResult = searcher.binarySearchIterative(arr, target);
        searcher.displayResult(binaryIterResult, target, "Binary Search (Iterative)");
        
        // Binary Search Recursive
        int binaryRecResult = searcher.binarySearchRecursive(arr, target, 0, arr.size() - 1);
        searcher.displayResult(binaryRecResult, target, "Binary Search (Recursive)");
        
        cout << endl;
    }
    
    cout << "=== END DEMONSTRATION ===" << endl << endl;
}

int main() {
    demoSearchingAlgorithms();
    return 0;
}