/**
 * Graph Implementation using Adjacency List in C++
 * Features: Add vertex/edge, BFS, DFS, Display
 * Time Complexity:
 *   - Add Vertex/Edge: O(1)
 *   - BFS/DFS: O(V + E)
 * Space Complexity: O(V + E)
 */

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Graph {
private:
    unordered_map<int, vector<int>> adjList;

    // DFS recursive helper
    void DFSRecursive(int vertex, unordered_set<int>& visited) {
        visited.insert(vertex);
        cout << vertex << " ";
        
        for (int neighbor : adjList[vertex]) {
            if (visited.find(neighbor) == visited.end()) {
                DFSRecursive(neighbor, visited);
            }
        }
    }

public:
    // Add vertex to graph
    void addVertex(int vertex) {
        if (adjList.find(vertex) == adjList.end()) {
            adjList[vertex] = vector<int>();
            cout << "Added vertex: " << vertex << endl;
        }
    }

    // Add undirected edge
    void addEdge(int src, int dest) {
        adjList[src].push_back(dest);
        adjList[dest].push_back(src);
        cout << "Added edge: " << src << " - " << dest << endl;
    }

    // Add directed edge
    void addDirectedEdge(int src, int dest) {
        adjList[src].push_back(dest);
        cout << "Added directed edge: " << src << " -> " << dest << endl;
    }

    // Display graph
    void display() {
        cout << "Graph Adjacency List:" << endl;
        for (auto& [vertex, neighbors] : adjList) {
            cout << vertex << " -> ";
            for (int neighbor : neighbors) {
                cout << neighbor << " ";
            }
            cout << endl;
        }
    }

    // Breadth First Search
    void BFS(int startVertex) {
        cout << "BFS Traversal: ";
        
        unordered_set<int> visited;
        queue<int> q;
        
        visited.insert(startVertex);
        q.push(startVertex);
        
        while (!q.empty()) {
            int current = q.front();
            q.pop();
            cout << current << " ";
            
            for (int neighbor : adjList[current]) {
                if (visited.find(neighbor) == visited.end()) {
                    visited.insert(neighbor);
                    q.push(neighbor);
                }
            }
        }
        cout << endl;
    }

    // Depth First Search (Iterative)
    void DFS(int startVertex) {
        cout << "DFS Traversal: ";
        
        unordered_set<int> visited;
        stack<int> st;
        
        st.push(startVertex);
        
        while (!st.empty()) {
            int current = st.top();
            st.pop();
            
            if (visited.find(current) == visited.end()) {
                visited.insert(current);
                cout << current << " ";
                
                // Push neighbors in reverse order for correct DFS
                for (auto it = adjList[current].rbegin(); it != adjList[current].rend(); ++it) {
                    if (visited.find(*it) == visited.end()) {
                        st.push(*it);
                    }
                }
            }
        }
        cout << endl;
    }

    // DFS Recursive
    void DFSRecursive(int startVertex) {
        cout << "DFS Recursive Traversal: ";
        unordered_set<int> visited;
        DFSRecursive(startVertex, visited);
        cout << endl;
    }

    // Check if graph is connected
    bool isConnected() {
        if (adjList.empty()) return true;
        
        unordered_set<int> visited;
        queue<int> q;
        
        int startVertex = adjList.begin()->first;
        visited.insert(startVertex);
        q.push(startVertex);
        
        while (!q.empty()) {
            int current = q.front();
            q.pop();
            
            for (int neighbor : adjList[current]) {
                if (visited.find(neighbor) == visited.end()) {
                    visited.insert(neighbor);
                    q.push(neighbor);
                }
            }
        }
        
        return visited.size() == adjList.size();
    }
};

// Demo function to test Graph
void demoGraph() {
    cout << "=== GRAPH ADJACENCY LIST DEMONSTRATION ===" << endl;
    
    Graph g;
    
    // Add vertices
    for (int i = 1; i <= 6; i++) {
        g.addVertex(i);
    }
    
    cout << endl;
    
    // Add edges (undirected)
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(2, 5);
    g.addEdge(3, 5);
    g.addEdge(4, 5);
    g.addEdge(4, 6);
    g.addEdge(5, 6);
    
    cout << endl;
    
    // Display graph
    g.display();
    
    cout << endl;
    
    // Traversal demonstrations
    g.BFS(1);
    g.DFS(1);
    g.DFSRecursive(1);
    
    cout << endl;
    
    // Check connectivity
    cout << "Graph is connected: " << (g.isConnected() ? "Yes" : "No") << endl;
    
    cout << "=== END DEMONSTRATION ===" << endl << endl;
}

int main() {
    demoGraph();
    return 0;
}