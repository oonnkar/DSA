#include <iostream>
using namespace std;

// Class representing the Binary Search Tree (BST)
class BST
{
private:
    // Internal Node structure representing each individual element in the tree
    class Node
    {
    public:
        int data;    // Value stored in the node
        Node *left;  // Pointer to the left child node
        Node *right; // Pointer to the right child node
    };

    Node *root; // Pointer to the root node of the BST

public:
    // Constructor to initialize the BST and populate it from an array
    BST(int *arr, int size)
    {
        root = nullptr;       // Initialize root as null (empty tree)
        createBST(arr, size); // Call helper function to insert array elements
    }

    // Function to create a binary search tree by inserting elements iteratively
    void createBST(int *arr, int size)
    {
        for (int i = 0; i < size; i++)
        {
            recInsert(arr[i]); // Insert each element from the array into the BST
        }
    }

    // Function to insert a single key iteratively inside the binary search tree
    void insert(int key)
    {
        // Case 1: If the tree is empty, create a new root node
        if (!root)
        {
            Node *temp = new Node;
            temp->data = key;
            temp->left = temp->right = nullptr;
            root = temp;
            return;
        }

        // Case 2: Tree is not empty, find the correct insertion position
        // Pointer 'p' traverses the tree, and 'q' acts as a trailing pointer to 'p'
        Node *p = root, *q = nullptr;
        while (p)
        {
            q = p; // Keep track of the parent node

            // If the key already exists in the BST, do not insert duplicates and return
            if (key == p->data)
            {
                return;
            }
            // Navigate left if the key is smaller than the current node's data
            else if (key < p->data)
            {
                p = p->left;
            }
            // Navigate right if the key is greater than the current node's data
            else
            {
                p = p->right;
            }
        }

        // Create the new node for the key
        Node *temp = new Node;
        temp->data = key;
        temp->left = temp->right = nullptr;

        // Attach the new node to the correct parent position found by 'q'
        if (key < q->data)
        {
            q->left = temp;
        }
        else
        {
            q->right = temp;
        }
    }

    // Helper function for Preorder traversal (Root -> Left -> Right)
    void preorderHelper(Node *p)
    {
        if (p)
        {
            cout << p->data << endl;  // Visit and print the root/current node
            preorderHelper(p->left);  // Recursively traverse the left subtree
            preorderHelper(p->right); // Recursively traverse the right subtree
        }
    }

    // Public interface function to initiate Preorder traversal from the root
    void preorder()
    {
        preorderHelper(root);
    }

    Node *recInsertHelper(Node *p, int key)
    {
        if (!p)
        {
            Node *temp = new Node;
            temp->data = key, temp->left = temp->right = nullptr;
            if (!root)
                root = temp;
            return temp;
        }
        if (key < p->data)
        {
            p->left = recInsertHelper(p->left, key);
        }
        else
        {
            p->right = recInsertHelper(p->right, key);
        }
        return p;
    }

    void recInsert(int key)
    {
        recInsertHelper(root, key);
    }
};

int main()
{
    int arr[] = {3, 2, 4, 1}; // Input array elements to build the BST
    BST bt(arr, 4);           // Instantiate BST object and build tree
    bt.preorder();            // Print elements using preorder traversal

    return 0;
}
