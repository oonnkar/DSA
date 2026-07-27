#include <iostream>
using namespace std;

// Node of the Circular Linked List
class Node
{
public:
    int data;   // Stores the data
    Node *next; // Pointer to the next node
};

// Circular Linked List
class CLL
{
public:
    Node *first; // Points to the first node of the list

    // Constructor: Creates a circular linked list from an array
    CLL(int *arr, int n)
    {
        // Create the first node
        first = new Node;
        first->data = arr[0];
        first->next = nullptr;

        Node *last = first;

        // Create the remaining nodes
        for (int i = 1; i < n; i++)
        {
            Node *temp = new Node;
            temp->data = arr[i];
            temp->next = nullptr;

            last->next = temp;
            last = temp;
        }

        // Make the list circular by connecting the last node to the first node
        last->next = first;
    }

    // Displays the circular linked list using iteration
    void display()
    {
        Node *p = first;

        // Traverse until we reach the first node again
        do
        {
            cout << p->data << " ";
            p = p->next;
        } while (p != first);
    }

    // Displays the circular linked list using recursion
    void recDisplay(Node *p)
    {
        // Static variable ensures recursion stops after one complete cycle
        static int counter = 0;

        // Execute for the first call or until we return to the first node
        if (p != first || counter == 0)
        {
            counter++;
            cout << p->data << " ";
            recDisplay(p->next);
        }

        // Reset counter after recursion completes
        counter = 0;
    }

    // Inserts a new node at the given index
    void insert(int index, int key)
    {
        // Create the new node
        Node *temp = new Node;
        temp->data = key;

        Node *p = first;

        // Insert at the beginning
        if (index == 0)
        {
            // Move to the last node
            while (p->next != first)
                p = p->next;

            // Connect last node to the new node
            p->next = temp;

            // New node points to the current first node
            temp->next = first;

            // Update first pointer
            first = temp;
        }
        else
        {
            // Move to the node before the insertion position
            for (int i = 1; i < index; i++)
            {
                p = p->next;
            }

            // Insert the new node
            temp->next = p->next;
            p->next = temp;
        }
    }
};

int main()
{
    // Array used to create the circular linked list
    int arr[] = {1, 2, 3, 4, 5};

    // Create the circular linked list
    CLL cl(arr, 5);

    // Insert 0 at index 3
    cl.insert(3, 0);

    // Display the updated list
    cl.display();

    return 0;
}