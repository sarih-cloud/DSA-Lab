# Lab 5: Advanced Data Structures

This lab covers three fundamental data structures: Binary Trees, Graphs, and Hash Tables.

## Files Included

### 1. `binary_tree.cpp`

- **Binary Search Tree implementation**
- **Operations:** Insert, Search, Traversals (Inorder, Preorder, Postorder, Level Order)
- **Time Complexity:** O(log n) average for search/insert, O(n) worst
- **Space Complexity:** O(n)

### 2. `graph_adjacency_list.cpp`

- **Graph implementation using adjacency list**
- **Operations:** Add vertex/edge, BFS, DFS (iterative & recursive)
- **Time Complexity:** O(V + E) for traversals
- **Space Complexity:** O(V + E)

### 3. `hash_table.cpp`

- **Hash Table with separate chaining collision resolution**
- **Operations:** Insert, Search, Delete, Load factor calculation
- **Time Complexity:** O(1) average, O(n) worst case
- **Space Complexity:** O(n)

## How to Compile and Run

```bash
# Compile individual files
g++ -std=c++11 binary_tree.cpp -o binary_tree
g++ -std=c++11 graph_adjacency_list.cpp -o graph
g++ -std=c++11 hash_table.cpp -o hash_table

# Run executables
./binary_tree
./graph  
./hash_table
