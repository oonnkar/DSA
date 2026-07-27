#include <iostream>
using namespace std;

// Node of a Doubly Linked List
class Node
{
public:
    Node *prev; // Points to the previous node
    int data;   // Stores the data
    Node *next; // Points to the next node
};

// Doubly Linked List
class DLL
{
public:
    Node *first; // Points to the first node of the list

    // Constructor: Creates a doubly linked list from an array
    DLL(int *arr, int n)
    {
        // Create the first node
        first = new Node;
        first->data = arr[0];
        first->next = first->prev = nullptr;

        // 'last' always points to the last node of the list
        Node *last = first;

        // Create the remaining nodes
        for (int i = 1; i < n; i++)
        {
            Node *temp = new Node;
            temp->data = arr[i];

            // Previous pointer points to the last node
            temp->prev = last;

            // New node is currently the last node
            temp->next = nullptr;

            // Link the previous last node to the new node
            last->next = temp;

            // Update the last pointer
            last = temp;
        }
    }

    // Displays the doubly linked list
    void display()
    {
        Node *p = first;

        // Traverse until the end of the list
        while (p)
        {
            // Print previous node address, current node data, and next node address
            cout << p->prev << " " << p->data << " " << p->next << endl;

            // Move to the next node
            p = p->next;
        }

        cout << endl;
    }
};

int main()
{
    // Array used to create the doubly linked list
    int arr[] = {1, 2, 3, 4, 5};
    int length = 5;

    // Create the doubly linked list
    DLL DL(arr, length);

    // Display the list
    DL.display();

    return 0;
}