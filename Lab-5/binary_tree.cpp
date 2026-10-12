/**
 * Binary Tree Implementation in C++
 * Features: Insertion, Traversals (Inorder, Preorder, Postorder), Search
 * Time Complexity: 
 *   - Insertion: O(log n) average, O(n) worst
 *   - Traversal: O(n)
 *   - Search: O(log n) average, O(n) worst
 * Space Complexity: O(n)
 */

#include <iostream>
#include <queue>
using namespace std;

// Binary Tree Node Structure
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BinaryTree {
private:
    TreeNode* root;

    // Helper function for recursive insertion
    TreeNode* insertRecursive(TreeNode* node, int value) {
        if (node == nullptr) {
            return new TreeNode(value);
        }
        
        if (value < node->data) {
            node->left = insertRecursive(node->left, value);
        } else {
            node->right = insertRecursive(node->right, value);
        }
        
        return node;
    }

    // Helper function for recursive traversals
    void inorderRecursive(TreeNode* node) {
        if (node == nullptr) return;
        
        inorderRecursive(node->left);
        cout << node->data << " ";
        inorderRecursive(node->right);
    }

    void preorderRecursive(TreeNode* node) {
        if (node == nullptr) return;
        
        cout << node->data << " ";
        preorderRecursive(node->left);
        preorderRecursive(node->right);
    }

    void postorderRecursive(TreeNode* node) {
        if (node == nullptr) return;
        
        postorderRecursive(node->left);
        postorderRecursive(node->right);
        cout << node->data << " ";
    }

    // Level order traversal helper
    void levelOrderTraversal(TreeNode* node) {
        if (node == nullptr) return;
        
        queue<TreeNode*> q;
        q.push(node);
        
        while (!q.empty()) {
            TreeNode* current = q.front();
            q.pop();
            
            cout << current->data << " ";
            
            if (current->left != nullptr) {
                q.push(current->left);
            }
            if (current->right != nullptr) {
                q.push(current->right);
            }
        }
    }

public:
    BinaryTree() : root(nullptr) {}

    // Public insertion method
    void insert(int value) {
        root = insertRecursive(root, value);
        cout << "Inserted: " << value << endl;
    }

    // Public traversal methods
    void inorder() {
        cout << "Inorder Traversal: ";
        inorderRecursive(root);
        cout << endl;
    }

    void preorder() {
        cout << "Preorder Traversal: ";
        preorderRecursive(root);
        cout << endl;
    }

    void postorder() {
        cout << "Postorder Traversal: ";
        postorderRecursive(root);
        cout << endl;
    }

    void levelOrder() {
        cout << "Level Order Traversal: ";
        levelOrderTraversal(root);
        cout << endl;
    }

    // Search method
    bool search(int value) {
        TreeNode* current = root;
        
        while (current != nullptr) {
            if (value == current->data) {
                return true;
            } else if (value < current->data) {
                current = current->left;
            } else {
                current = current->right;
            }
        }
        
        return false;
    }

    // Find minimum value
    int findMin() {
        if (root == nullptr) {
            throw runtime_error("Tree is empty");
        }
        
        TreeNode* current = root;
        while (current->left != nullptr) {
            current = current->left;
        }
        
        return current->data;
    }

    // Find maximum value
    int findMax() {
        if (root == nullptr) {
            throw runtime_error("Tree is empty");
        }
        
        TreeNode* current = root;
        while (current->right != nullptr) {
            current = current->right;
        }
        
        return current->data;
    }
};

// Demo function to test Binary Tree
void demoBinaryTree() {
    cout << "=== BINARY TREE DEMONSTRATION ===" << endl;
    
    BinaryTree tree;
    
    // Insert elements
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);
    
    cout << endl;
    
    // Perform traversals
    tree.inorder();
    tree.preorder();
    tree.postorder();
    tree.levelOrder();
    
    cout << endl;
    
    // Search operations
    cout << "Search 40: " << (tree.search(40) ? "Found" : "Not Found") << endl;
    cout << "Search 90: " << (tree.search(90) ? "Found" : "Not Found") << endl;
    
    // Find min and max
    cout << "Minimum value: " << tree.findMin() << endl;
    cout << "Maximum value: " << tree.findMax() << endl;
    
    cout << "=== END DEMONSTRATION ===" << endl << endl;
}

int main() {
    demoBinaryTree();
    return 0;
}