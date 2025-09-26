#include <iostream>

using namespace std;

struct Node 
{
    int data;
    Node* next;
};

class LinkedList 
{
    Node* head;
    Node* tail;

    public:
    LinkedList() 
    {
        this->head = NULL;
        this->tail = NULL;
    }

    void insertAtBeggining(Node* &head, int value) 
    {
        // Dynamically allocate memory for a new node
        Node* newNode = new Node();
        newNode->data = value;      // Use the passed value
        newNode->next = head;       // Make its next value point to the old head
        head = newNode;             // Update the head to the new node we just added
    }

    void insertAtEnd(Node* &head, int value) 
    {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = NULL;       // There is no node after this, adding to end

        if (head == NULL)       // If the List is empty
        {
            head = newNode;     // Just make the head this Node
        } 
        else 
        {
            Node* temp = head;
            while (temp->next != NULL)  // Traverse to the last node
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void insertAtPosition(Node* &head, int value, int position)
    {
        Node* newNode = new Node();
        newNode->data = value;
        
        if (position == 1)      // Add Node at head
        {
            newNode->next = head;
            head = newNode;
            return;
        }

        Node* temp = head;
        for (int i = 1; i < position - 1 && temp != NULL; i++)
        {           // Traverse to next Node till at location just behind position
            temp = temp->next;
        }

        if (temp == NULL)       // Invalid position handling
        {
            cout << "[ERROR] position out of bounds for insertion" << endl;
        }
        else 
        {
            newNode->next = temp->next;     // Link the new node to the next node
            temp->next = newNode;           // Link previous node to the new one
        }
    }

    void deleteFromBeggining(Node* &head)
    {
        if (head == NULL)
        {
            cout << "[ERROR] cannot delete from beginning, list is empty" << endl;
            return;
        }
        Node* temp = head;      // Save the current head
        head = head->next;      // Point head to the next node
        delete temp;            // Free memory
    }

    void deleteFromEnd(Node* &head)
    {
        if (head == NULL)
        {
            cout << "[ERROR] cannot delete from end, list is empty" << endl;
        }
        if (head->next == NULL)     // If only one node is left
        {
            delete head;
            head = NULL;
            return;
        }
        Node* temp = head;
        while (temp->next->next != NULL)
        {       // Traverse to the second last node
            temp = temp->next;
        }
        delete temp->next;      // Free up last node memory
        temp->next = NULL;      // Update it to point to NULL
    }

    void deleteFromPosition(Node* &head, int position)
    {
        if (head == NULL)
        {
            cout << "[ERROR] cannot delete from Position " << position << ", list is empty" << endl;
            return;
        }
        if (position == 1)      // Delete from first position
        {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node* temp = head;
        for (int i = 1; i < position - 1 && temp != NULL; i++)
        {
            temp = temp->next;  // Traverse to the node before the one to be deleted
        }
        if (temp == NULL || temp->next = NULL)
        {
            cout << "[ERROR] cannot delete from position " << position << ", out of bounds" << endl;
            return;
        }
        Node* nodeToDelete = temp->next;    // Store the node to free memory later
        temp->next = temp->next->next;      // Update the lionk to remove the node
        delete nodeToDelete;                // Free up memory
    }

    void displayList(Node* head)
    {
        if (head == NULL)
        {
            cout << "[ERROR] cannot display, list is empty" << endl;
            return;
        }

        Node* temp = head;
        while (temp != NULL) 
        {
            cout << temp->data << " -> ";
            temp = temp->next;      // Move to the next node
        }
        cout << "NULL" << endl;     // Show the end of the list
    }

    void destroyList(Node* &head) 
    {
        Node* temp;
        while (head != NULL)
        {
            temp = head;            // Store the head to delete later
            head = head->next;      // Move forward
            delete temp;            // Delete the stored head
        }
        cout << "[SUCCESS] list destroyed" << endl;
    }
};

int main()
{
    
}