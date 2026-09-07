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

    /**
     * Calculates the height of a node in the Binary Search Tree.
     * An empty node has a height of 0.
     *
     * @param p   Pointer to the current node.
     * @return    The maximum depth/height of the subtree.
     */
    int height(Node *p)
    {
        // Base Case: An empty node contributes 0 to the height
        if (p == nullptr)
        {
            return 0;
        }

        // Compute the height of both subtrees
        int leftHeight = height(p->left);
        int rightHeight = height(p->right);

        // The height of the current node is 1 plus the maximum of its children's heights
        return (leftHeight > rightHeight) ? (leftHeight + 1) : (rightHeight + 1);
    }

    /**
     * Finds the value of the inorder predecessor.
     * Traverses to the rightmost node of the given left subtree.
     *
     * @param p   Pointer to the left child of the node being replaced.
     * @return    The maximum data value in this subtree.
     */
    int inorderPredessor(Node *p)
    {
        // Guard against a nullptr argument
        if (p == nullptr)
            return -1; // Or a suitable error value depending on your tree data

        // Go to the rightmost leaf node
        while (p->right != nullptr)
        {
            p = p->right;
        }

        return p->data;
    }

    /**
     * Finds the value of the inorder successor.
     * Traverses to the leftmost node of the given right subtree.
     *
     * @param p   Pointer to the right child of the node being replaced.
     * @return    The minimum data value in this subtree.
     */
    int inorderSuccesor(Node *p)
    {
        // Guard against a nullptr argument
        if (p == nullptr)
            return -1; // Or a suitable error value depending on your tree data

        // Go to the leftmost leaf node
        while (p->left != nullptr)
        {
            p = p->left;
        }

        return p->data;
    }

    /**
     * Helper function to recursively delete a node from a Binary Search Tree (BST).
     * Balances the tree during deletion by checking subtree heights.
     *
     * @param p      Pointer to the current node in the BST.
     * @param data   The value to be deleted.
     * @return       Pointer to the updated subtree root.
     */
    Node *recDeleteHelper(Node *p, int data)
    {
        // Base Case 1: The tree or subtree is empty
        if (p == nullptr)
        {
            return nullptr;
        }

        // Base Case 2: Found the target node, and it is a leaf node
        if (data == p->data && p->left == nullptr && p->right == nullptr)
        {
            delete p;
            return nullptr;
        }

        // Recursive Case: Target value is not yet found or node is an internal node
        if (data < p->data)
        {
            // Target is in the left subtree
            p->left = recDeleteHelper(p->left, data);
        }
        else if (data > p->data)
        {
            // Target is in the right subtree
            p->right = recDeleteHelper(p->right, data);
        }
        else
        {
            // Base Case 3: Found the target node, and it is an internal node (has children)
            // Optimize tree balance by replacing the node using the taller subtree
            if (height(p->left) > height(p->right))
            {
                // Replace with the largest value from the left subtree (Inorder Predecessor)
                int inpre = inorderPredessor(p->left);
                p->data = inpre;
                p->left = recDeleteHelper(p->left, inpre);
            }
            else
            {
                // Replace with the smallest value from the right subtree (Inorder Successor)
                int insuc = inorderSuccesor(p->right);
                p->data = insuc;
                p->right = recDeleteHelper(p->right, insuc);
            }
        }

        return p;
    }

    /**
     * Public wrapper function to delete a value from the BST.
     *
     * @param data   The value to be deleted.
     */
    void recDelete(int data)
    {
        root = recDeleteHelper(root, data);
    }
};

int main()
{
    int arr[] = {100, 50, 150, 60, 140, 130}; // Input array elements to build the BST
    BST bt(arr, 6);                           // Instantiate BST object and build tree
    bt.preorder();                            // Print elements using preorder traversal
    bt.recDelete(100);
    cout << "after ";
    bt.preorder();
    return 0;
}
