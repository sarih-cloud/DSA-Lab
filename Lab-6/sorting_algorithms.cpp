/**
 * Sorting Algorithms Implementation in C++
 * Includes: Bubble Sort, Selection Sort, Insertion Sort, Merge Sort, Quick Sort
 * Time Complexity Analysis for each algorithm
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class SortingAlgorithms {
private:
    // Helper function for merge sort
    void merge(vector<int>& arr, int left, int mid, int right) {
        int n1 = mid - left + 1;
        int n2 = right - mid;
        
        vector<int> L(n1), R(n2);
        
        for (int i = 0; i < n1; i++)
            L[i] = arr[left + i];
        for (int j = 0; j < n2; j++)
            R[j] = arr[mid + 1 + j];
            
        int i = 0, j = 0, k = left;
        
        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                arr[k] = L[i];
                i++;
            } else {
                arr[k] = R[j];
                j++;
            }
            k++;
        }
        
        while (i < n1) {
            arr[k] = L[i];
            i++;
            k++;
        }
        
        while (j < n2) {
            arr[k] = R[j];
            j++;
            k++;
        }
    }
    
    // Helper function for quick sort
    int partition(vector<int>& arr, int low, int high) {
        int pivot = arr[high];
        int i = low - 1;
        
        for (int j = low; j < high; j++) {
            if (arr[j] <= pivot) {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]);
        return i + 1;
    }

public:
    // Bubble Sort - O(n²)
    void bubbleSort(vector<int>& arr) {
        int n = arr.size();
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    swap(arr[j], arr[j + 1]);
                }
            }
        }
    }
    
    // Selection Sort - O(n²)
    void selectionSort(vector<int>& arr) {
        int n = arr.size();
        for (int i = 0; i < n - 1; i++) {
            int minIdx = i;
            for (int j = i + 1; j < n; j++) {
                if (arr[j] < arr[minIdx]) {
                    minIdx = j;
                }
            }
            swap(arr[i], arr[minIdx]);
        }
    }
    
    // Insertion Sort - O(n²)
    void insertionSort(vector<int>& arr) {
        int n = arr.size();
        for (int i = 1; i < n; i++) {
            int key = arr[i];
            int j = i - 1;
            
            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;
        }
    }
    
    // Merge Sort - O(n log n)
    void mergeSort(vector<int>& arr, int left, int right) {
        if (left >= right) return;
        
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
    
    // Quick Sort - O(n log n) average, O(n²) worst
    void quickSort(vector<int>& arr, int low, int high) {
        if (low < high) {
            int pi = partition(arr, low, high);
            quickSort(arr, low, pi - 1);
            quickSort(arr, pi + 1, high);
        }
    }
    
    // Display array
    void display(const vector<int>& arr, const string& algorithm) {
        cout << algorithm << ": ";
        for (int num : arr) {
            cout << num << " ";
        }
        cout << endl;
    }
};

void demoSortingAlgorithms() {
    cout << "=== SORTING ALGORITHMS DEMONSTRATION ===" << endl;
    
    SortingAlgorithms sorter;
    vector<int> arr = {64, 34, 25, 12, 22, 11, 90};
    
    // Test each sorting algorithm
    vector<int> temp;
    
    // Bubble Sort
    temp = arr;
    sorter.bubbleSort(temp);
    sorter.display(temp, "Bubble Sort");
    
    // Selection Sort
    temp = arr;
    sorter.selectionSort(temp);
    sorter.display(temp, "Selection Sort");
    
    // Insertion Sort
    temp = arr;
    sorter.insertionSort(temp);
    sorter.display(temp, "Insertion Sort");
    
    // Merge Sort
    temp = arr;
    sorter.mergeSort(temp, 0, temp.size() - 1);
    sorter.display(temp, "Merge Sort");
    
    // Quick Sort
    temp = arr;
    sorter.quickSort(temp, 0, temp.size() - 1);
    sorter.display(temp, "Quick Sort");
    
    cout << "=== END DEMONSTRATION ===" << endl << endl;
}

int main() {
    demoSortingAlgorithms();
    return 0;
}