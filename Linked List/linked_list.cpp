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
    if (size > 0)
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
    return nullptr;
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
// Find maximum element in list
int findMax(Node *head)
{
    int max = INT32_MIN;
    Node *p = head;
    while (p)
    {
        if (p->data > max)
            max = p->data;
        p = p->next;
    }
    return max;
}

// Find maximum element recursively
int recFindMax(Node *p)
{
    if (p == nullptr)
        return INT32_MIN;
    else
    {

        int x = recFindMax(p->next);
        if (p->data > x)
            return p->data;
        else
            return x;
    }
}

// Linear Search
Node *linearSearch(Node *p, int key)
{
    while (p)
    {

        if (p->data == key)
            return p;
        p = p->next;
    }
    return nullptr;
}

// Linear Search using recursion
Node *recLinearSearch(Node *p, int key)
{
    // if(node is present) check node's data is equal to key if it is equal return address of node. if not check next node and if(node's not present means we have checked all node's we doesn't found match) return nullptr
    if (p)
    {
        if (p->data == key)
            return p;
        else
            return recLinearSearch(p->next, key);
    }
    return nullptr;
}

// Linear Search impoved using move to front method
Node *linearSearchMoveToFront(Node *p, int key)
{
    Node *head = p;
    Node *q = nullptr;
    while (p)
    {
        if (p->data == key)
        {

            if (p != head)
            {
                q->next = p->next;
                p->next = head;
                head = p;
            }
            return head;
        }

        q = p;
        p = p->next;
    }
    return nullptr;
}
// Insert element at given position in linkedlist
void insert(Node *p, int pos, int key)
{
    if (p)
    {

        Node *head = p;
        int validPosition = countNodes(p);
        if (pos >= 0 && pos <= validPosition)
        {
            if (pos == 0)
            {
                Node *temp = new Node;
                temp->data = key;
                temp->next = head;
                head = temp;
            }
            else
            {
                for (int i = 1; i < pos; i++)
                {
                    p = p->next;
                }
                Node *temp = new Node;
                temp->data = key;
                temp->next = p->next;
                p->next = temp;
            }
        }
    }
}
// Insert in sorted linkedlist
Node *insertSortedLinkedList(Node *p, int data)
{
    Node *head = p, *q = nullptr;
    Node *temp = new Node;
    temp->data = data;
    while (p && p->data < data)
    {
        q = p;
        p = p->next;
    }
    if (p == head)
    {
        temp->next = head;
        head = temp;
    }
    else
    {
        temp->next = q->next;
        q->next = temp;
    }
    return head;
}
// Delete node from linkedlist using index
// index starts from 1 onwards
Node *deleteNode(Node *p, int index)
{
    Node *head = p;
    int noOfNodes = countNodes(p);
    if (index > 0 && index <= noOfNodes)
    {
        if (index == 1)
        {
            head = p->next;
            delete p;
        }
        else
        {
            Node *q = nullptr;
            for (int i = 1; i < index; i++)
            {
                q = p;
                p = p->next;
            }
            q->next = p->next;
            delete p;
        }
    }
    return head;
}
// Check LinkedList is sorted
bool isSorted(Node *p)
{
    int x = p->data;
    p = p->next;
    while (p)
    {
        if (p->data < x)
            return false;
        x = p->data;
        p = p->next;
    }
    return true;
}
// Remove duplicates in sorted linked list
Node *removeDuplicates(Node *p)
{
    Node *head = p;
    Node *q = p;
    if (p->next)
    {

        p = p->next;
    }
    while (p)
    {
        if (p->data)
        {
            if (p->data == q->data)
            {
                q->next = p->next;
                delete p;
                p = q->next;
            }
            else
            {
                q = p;
                p = p->next;
            }
        }
    }
    return head;
}
// Reverse linkedlist using auxaliry array
Node *reverseLinkedListUsingArray(Node *p)
{
    Node *head = p;

    int noOfNodes = countNodes(p);
    int *arr = new int[noOfNodes];

    int i = 0;
    while (p)
    {
        arr[i] = p->data;
        p = p->next;
        i++;
    }
    i--;
    p = head;
    while (p)
    {
        p->data = arr[i];
        i--;
        p = p->next;
    }
    return head;
}
// Reverse LinkedList using sliding pointers
Node *reverseLinkedList(Node *p)
{
    Node *r = nullptr, *q = nullptr;
    while (p)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    return q;
}
// Reverse linkedlist using recursion with help of two pointers
Node *recReverseLinkedList(Node *q, Node *p)
{
    static Node *head =  nullptr;
    if (p)
    {
        recReverseLinkedList(p, p->next);
        p->next = q;
    }
    else
    {
        head = q;
    }
    return head;
}
int main()
{
    // Array used to create the linked list
    int numbers[] = {1, 2, 2, 2, 4, 5};
    int arraySize = 6;

    // Create the linked list from the array
    Node *head = createLinkedList(numbers, arraySize);
    Node *first = recReverseLinkedList(nullptr, head);
    display(first);
    return 0;
}