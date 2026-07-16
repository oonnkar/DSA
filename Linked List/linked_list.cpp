#include <iostream>
using namespace std;

// Structure representing a node of the linked list
struct Node
{
    int data;   // Value stored in the node
    Node *next; // Pointer to the next node
};
// Creates a linked list from an array and returns the head pointer
Node *createLinkedList(int *array, int size)
{
    // Create the first node
    Node *head = new Node;
    head->data = array[0];
    head->next = nullptr;
    // current is used to create new nodes
    // tail always points to the last node in the list
    Node *current = nullptr;
    Node *tail = head;
    // Create the remaining nodes
    for (int index = 1; index < size; index++)
    {
        current = new Node;
        current->data = array[index];
        current->next = nullptr;
        // Attach the new node to the end of the list
        tail->next = current;
        tail = current;
    }
    return head;
}
// Displays the linked list iteratively
void display(Node *head)
{
    while (head != nullptr)
    {
        cout << head->data << " " << head->next << endl;
        head = head->next;
    }
}
// Helper function that recursively traverses and displays the list
void recursiveDisplayHelper(Node *current)
{
    if (current)
    {
        cout << current->data << " " << current->next << endl;
        recursiveDisplayHelper(current->next);
    }
}
// Calls the recursive helper function
void recursiveDisplay(Node *head)
{
    recursiveDisplayHelper(head);
}
// 
int main()
{
    // Array used to create the linked list
    int numbers[] = {1, 2, 3, 4, 5};
    int arraySize = 5;
    // Create the linked list
    Node *head = createLinkedList(numbers, arraySize);
    // Display using iteration
    display(head);
    cout << "Recursive display" << endl;
    // Display using recursion
    recursiveDisplay(head);
    return 0;
}