#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Queue {
    Node* head;   // Points to the front of the queue
    Node* tail;   // Points to the rear of the queue

public:
    Queue() {
        head = NULL;
        tail = NULL;
    }

    ~Queue() {
        // Keep removing until queue becomes empty
        while (!isEmpty()) {
            dequeue();
        }
        cout << "[SUCCESS] Queue destroyed" << endl;
    }

    // Add a new value at the end of the queue
    void enqueue(int value) {
        Node* newNode = new Node();     // Create a new Node
        newNode->data = value;          // Store the value
        newNode->next = NULL;           // Nothing comes after this new Node yet

        if (tail == NULL) {             // If the queue is empty
            head = tail = newNode;      // Head and Tail both point to the same Node
        } else {
            tail->next = newNode;       // Link the old last Node to the new one
            tail = newNode;             // Update the tail to the new Node
        }
        cout << value << " enqueued" << endl;
    }

    // Remove a value from the front of the queue
    void dequeue() {
        if (isEmpty()) {
            cout << "[ERROR] cannot dequeue, queue is empty" << endl;
            return;
        }

        Node* temp = head;          // Store the front Node
        head = head->next;          // Move head to the next Node

        if (head == NULL) {         // If the queue is now empty
            tail = NULL;            // Update tail also to NULL
        }

        cout << temp->data << " dequeued" << endl;
        delete temp;                // Free the memory of the removed Node
    }

    // Look at the front value without removing it
    int peek() {
        if (isEmpty()) {
            cout << "[ERROR] queue is empty, cannot peek" << endl;
            return -1;
        }
        return head->data;          // Just return the front value
    }

    // Check if the queue has no elements
    bool isEmpty() {
        return head == NULL;
    }

    // Print all elements from front to rear
    void display() {
        if (isEmpty()) {
            cout << "[ERROR] queue is empty" << endl;
            return;
        }

        Node* temp = head;
        cout << "Queue: ";
        while (temp != NULL) {
            cout << temp->data << " <- ";   // Print data and move to next
            temp = temp->next;
        }
        cout << "NULL" << endl;             // Show end of queue
    }
};

// Test driver
int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    cout << "Displaying queue: " << endl;
    q.display();

    cout << "Front element called using peek: " << q.peek() << endl;
    cout << "Removing using dequeue" << endl;
    q.dequeue();
    cout << "Displaying queue (again): " << endl;
    q.display();

    return 0;
}
