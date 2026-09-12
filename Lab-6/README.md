# Lab 6: Sorting, Searching & Recursion

This lab covers fundamental algorithms for sorting, searching, and recursive problem-solving.

## Files Included

### 1. `sorting_algorithms.cpp`

- **Sorting algorithms:** Bubble, Selection, Insertion, Merge, Quick Sort
- **Time Complexity:** Ranges from O(n²) to O(n log n)
- **Space Complexity:** O(1) to O(n)

### 2. `searching_algorithms.cpp`

- **Searching algorithms:** Linear Search, Binary Search (Iterative & Recursive)
- **Time Complexity:** O(n) for Linear, O(log n) for Binary Search
- **Requirements:** Binary Search requires sorted array

### 3. `recursion_examples.cpp`

- **Recursive algorithms:** Factorial, Fibonacci, Tower of Hanoi, GCD, etc.
- **Demonstrates:** Recursive thinking and problem decomposition
- **Time Complexity:** Varies by algorithm

## How to Compile and Run

```bash
# Compile individual files
g++ -std=c++11 sorting_algorithms.cpp -o sorting
g++ -std=c++11 searching_algorithms.cpp -o searching
g++ -std=c++11 recursion_examples.cpp -o recursion

# Run executables
./sorting
./searching
./recursion
