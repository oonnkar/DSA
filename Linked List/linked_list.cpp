#include <iostream>
using namespace std;

// Structure representing a single node in the linked list
struct Node
{
    int data;   // Stores the value of the node
    Node *next; // Points to the next node in the list
};

// Creates a linked list from an array and returns the head pointer
Node *createLinkedList(int *array, int size)
{
    // Create the first node (head)
    Node *head = new Node;
    head->data = array[0];
    head->next = nullptr;

    // current is used to create new nodes
    // tail always points to the last node in the list
    Node *current = nullptr;
    Node *tail = head;

    // Create the remaining nodes and attach them at the end
    for (int index = 1; index < size; index++)
    {
        current = new Node;
        current->data = array[index];
        current->next = nullptr;

        // Link the new node to the list
        tail->next = current;

        // Move tail to the newly created node
        tail = current;
    }

    // Return the head of the linked list
    return head;
}

// Displays all nodes of the linked list using iteration
void display(Node *head)
{
    // Traverse until the end of the list
    while (head != nullptr)
    {
        // Print node data and the address of the next node
        cout << head->data << " " << head->next << endl;

        // Move to the next node
        head = head->next;
    }
}

// Recursive helper function to display the linked list
void recursiveDisplayHelper(Node *current)
{
    // Continue until the current node becomes nullptr
    if (current)
    {
        // Print current node data and next pointer
        cout << current->data << " " << current->next << endl;

        // Recursively visit the next node
        recursiveDisplayHelper(current->next);
    }
}

// Calls the recursive helper function
void recursiveDisplay(Node *head)
{
    recursiveDisplayHelper(head);
}

// Counts the number of nodes using iteration
int countNodes(Node *head)
{
    Node *p = head;
    int count = 0;

    // Traverse the entire list
    while (p)
    {
        count++;
        p = p->next;
    }

    // Return the total number of nodes
    return count;
}

// Recursive helper function to count nodes
int recCountNodesHelper(Node *p)
{
    // If node exists, count it and recurse for the next node
    if (p)
        return 1 + recCountNodesHelper(p->next);

    // Base case: end of list
    return 0;
}

// Calls the recursive node counting function
int recCountNodes(Node *head)
{
    return recCountNodesHelper(head);
}

// Calculates the sum of all node values using iteration
int sum(Node *head)
{
    Node *p = head;
    int sum = 0;

    // Traverse the list and add each node's value
    while (p)
    {
        sum += p->data;
        p = p->next;
    }

    // Return the total sum
    return sum;
}

// Recursive helper function to calculate the sum
int recSumHelper(Node *p)
{
    // Add current node value and recurse for the next node
    if (p)
        return p->data + recSumHelper(p->next);

    // Base case: end of list
    return 0;
}

// Calls the recursive sum function
int recSum(Node *head)
{
    return recSumHelper(head);
}

int main()
{
    // Array used to create the linked list
    int numbers[] = {1, 2, 3, 4, 5};
    int arraySize = 5;

    // Create the linked list from the array
    Node *head = createLinkedList(numbers, arraySize);

    // Display the linked list using iteration
    display(head);

    // Display heading for recursive traversal
    cout << "Recursive display" << endl;

    // Display the linked list using recursion
    recursiveDisplay(head);

    // Print the node count using both iterative and recursive methods
    cout << "Count Nodes : " << countNodes(head) << " And count Nodes recursively " << recCountNodes(head) << endl;

    // Print the sum of all node values using both methods
    cout << "Sum of all elements in nodes " << sum(head) << " And sum of all elements in nodes " << recSum(head) << endl;

    return 0;
}