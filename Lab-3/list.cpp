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

    ~LinkedList()
    {
        cout << "[OPERATION] destroying list to free up memory" << endl;
        this->destroyList();
    }

    void insertAtBeggining(int value) 
    {
        // Dynamically allocate memory for a new node
        Node* newNode = new Node();
        newNode->data = value;      // Use the passed value
        newNode->next = this->head; // Make its next value point to the old head
        this->head = newNode;       // Update the head to the new node we just added
    }

    void insertAtEnd(int value) 
    {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = NULL;       // There is no node after this, adding to end

        if (this->head == NULL)     // If the List is empty
        {
            this->head = newNode;   // Just make the head this Node
        } 
        else 
        {
            Node* temp = this->head;
            while (temp->next != NULL)  // Traverse to the last node
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void insertAtPosition(int value, int position)
    {
        Node* newNode = new Node();
        newNode->data = value;
        
        if (position == 1)      // Add Node at head
        {
            newNode->next = this->head;
            this->head = newNode;
            return;
        }

        Node* temp = this->head;
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

    void deleteFromBeggining()
    {
        if (this->head == NULL)
        {
            cout << "[ERROR] cannot delete from beginning, list is empty" << endl;
            return;
        }
        Node* temp = this->head;      // Save the current head
        this->head = this->head->next;      // Point head to the next node
        delete temp;            // Free memory
    }

    void deleteFromEnd()
    {
        if (this->head == NULL)
        {
            cout << "[ERROR] cannot delete from end, list is empty" << endl;
            return;
        }
        if (this->head->next == NULL)     // If only one node is left
        {
            delete this->head;
            this->head = NULL;
            return;
        }
        Node* temp = this->head;
        while (temp->next->next != NULL)
        {       // Traverse to the second last node
            temp = temp->next;
        }
        delete temp->next;      // Free up last node memory
        temp->next = NULL;      // Update it to point to NULL
    }

    void deleteFromPosition(int position)
    {
        if (this->head == NULL)
        {
            cout << "[ERROR] cannot delete from Position " << position << ", list is empty" << endl;
            return;
        }
        if (position == 1)      // Delete from first position
        {
            Node* temp = this->head;
            this->head = this->head->next;
            delete temp;
            return;
        }
        Node* temp = this->head;
        for (int i = 1; i < position - 1 && temp != NULL; i++)
        {
            temp = temp->next;  // Traverse to the node before the one to be deleted
        }
        if (temp == NULL || temp->next == NULL)
        {
            cout << "[ERROR] cannot delete from position " << position << ", out of bounds" << endl;
            return;
        }
        Node* nodeToDelete = temp->next;    // Store the node to free memory later
        temp->next = temp->next->next;      // Update the link to remove the node
        delete nodeToDelete;                // Free up memory
    }

    void displayList()
    {
        if (this->head == NULL)
        {
            cout << "[ERROR] cannot display, list is empty" << endl;
            return;
        }

        Node* temp = this->head;
        while (temp != NULL) 
        {
            cout << temp->data << " -> ";
            temp = temp->next;      // Move to the next node
        }
        cout << "NULL" << endl;     // Show the end of the list
    }

    void destroyList() 
    {
        Node* temp;
        while (this->head != NULL)
        {
            temp = this->head;            // Store the head to delete later
            this->head = this->head->next;      // Move forward
            delete temp;            // Delete the stored head
        }
        cout << "[SUCCESS] list destroyed" << endl;
    }
};

int main()      // Test driver for list class
{
    // Create a linked list
    LinkedList* list = new LinkedList();

    // Insert Nodes at head
    list->insertAtBeggining(7);
    list->insertAtBeggining(4);
    list->insertAtBeggining(12);
    list->insertAtBeggining(8);

    // Verify that the values were added
    list->displayList();
}
