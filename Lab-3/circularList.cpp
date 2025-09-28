#include <iostream>
using namespace std;

// Node class, represents each element of the circular list
class Node {
public:
    int value;
    Node* next;   // Points to the next Node
};

// Class for the Circular Linked List
class CircularLinkedList {
    Node* head;   // First node
    Node* tail;   // Last node (helps for easy insert at end)

public:
    CircularLinkedList() {
        head = NULL;
        tail = NULL;
    }

    ~CircularLinkedList() {
        // Keep deleting from front until list is empty
        while (head != NULL) {
            deleteFromFront();
        }
        cout << "[SUCCESS] circular list destroyed" << endl;
    }

    // Insert at the head (front of list)
    void insertAtHead(int new_value) {
        Node* newNode = new Node();
        newNode->value = new_value;

        if (head == NULL) {
            // First node → points to itself
            head = tail = newNode;
            newNode->next = head;
        } else {
            newNode->next = head;    // New node points to old head
            head = newNode;          // Update head
            tail->next = head;       // Last node still points to head
        }
        cout << new_value << " inserted at head" << endl;
    }

    // Insert at the end of the list
    void insertAtEnd(int new_value) {
        Node* newNode = new Node();
        newNode->value = new_value;

        if (head == NULL) {
            // First node → points to itself
            head = tail = newNode;
            newNode->next = head;
        } else {
            tail->next = newNode;    // Old tail points to new node
            tail = newNode;          // Update tail
            tail->next = head;       // New tail points back to head
        }
        cout << new_value << " inserted at end" << endl;
    }

    // Insert at any position (1-based indexing)
    void insertAtLocation(int location, int new_value) {
        if (location <= 0) {
            cout << "[ERROR] invalid location" << endl;
            return;
        }

        if (location == 1) {
            insertAtHead(new_value);
            return;
        }

        Node* newNode = new Node();
        newNode->value = new_value;

        Node* temp = head;
        for (int i = 1; i < location - 1 && temp->next != head; i++) {
            temp = temp->next;
        }

        newNode->next = temp->next;
        temp->next = newNode;

        if (temp == tail) {
            tail = newNode; // If inserted at the end, update tail
        }

        cout << new_value << " inserted at location " << location << endl;
    }

    // Delete node from front
    void deleteFromFront() {
        if (head == NULL) {
            cout << "[ERROR] cannot delete, list is empty" << endl;
            return;
        }

        Node* temp = head;

        if (head == tail) {
            // Only one node left
            head = tail = NULL;
        } else {
            head = head->next;       // Move head forward
            tail->next = head;       // Tail should still point to head
        }

        cout << temp->value << " deleted from front" << endl;
        delete temp;
    }

    // Delete by value
    void deleteNode(int del_value) {
        if (head == NULL) {
            cout << "[ERROR] cannot delete, list is empty" << endl;
            return;
        }

        Node* curr = head;
        Node* prev = tail;

        do {
            if (curr->value == del_value) {
                if (curr == head) {
                    deleteFromFront();
                } else {
                    prev->next = curr->next;
                    if (curr == tail) {
                        tail = prev;   // If deleting last node, update tail
                    }
                    cout << del_value << " deleted from list" << endl;
                    delete curr;
                }
                return;
            }
            prev = curr;
            curr = curr->next;
        } while (curr != head);

        cout << "[ERROR] value " << del_value << " not found in list" << endl;
    }

    // Count how many nodes are in the list
    void countList() {
        if (head == NULL) {
            cout << "List contains 0 nodes" << endl;
            return;
        }

        int count = 0;
        Node* temp = head;
        do {
            count++;
            temp = temp->next;
        } while (temp != head);

        cout << "List contains " << count << " nodes" << endl;
    }

    // Display all nodes
    void displayList() {
        if (head == NULL) {
            cout << "[ERROR] list is empty" << endl;
            return;
        }

        Node* temp = head;
        cout << "Circular List: ";
        do {
            cout << temp->value << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << "(back to head)" << endl;
    }

    // Detect if the list is circular
    bool isCircular() {
        if (head == NULL) return false;

        Node* temp = head->next;
        while (temp != NULL && temp != head) {
            temp = temp->next;
        }
        return (temp == head);
    }
};

// Test driver for CircularLinkedList class
int main() {
    CircularLinkedList cl;

    cout << "Inserting 10, 20, 30 at the end of the circular list..." << endl;
    cl.insertAtEnd(10);
    cl.insertAtEnd(20);
    cl.insertAtEnd(30);

    cout << "\nDisplaying list: " << endl;
    cl.displayList();
    cout << "\nNow inserting 5 at the head of the list..." << endl;
    cl.insertAtHead(5);

    cout << "Displaying list: " << endl;
    cl.displayList();
    cout << "\nNow inserting 15 at position 3..." << endl;
    cl.insertAtLocation(3, 15);

    cout << "Displaying list: " << endl;
    cl.displayList();
    cout << "\nNow deleting one element from the front..." << endl;
    cl.deleteFromFront();

    cout << "Displaying list: " << endl;
    cl.displayList();
    cout << "\nDeleting node with value 20..." << endl;
    cl.deleteNode(20);

    cout << "Displaying list: " << endl;
    cl.displayList();
    cout << "\nCounting total nodes in the list..." << endl;
    cl.countList();

    cout << "\nChecking if the list is circular: " 
         << (cl.isCircular() ? "Yes, it is circular." : "No, it is not circular.") 
         << endl;

    return 0;
}
