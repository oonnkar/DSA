#include <iostream>
#include "Queue.h"
#include "Stack.h"
using namespace std;

class TreeNode
{
public:
    TreeNode *left;
    int data;
    TreeNode *right;
};

class Tree
{
private:
    TreeNode *root;

public:
    Tree() { root = nullptr; }
    void create();
    void preorder()
    {
        preorder(root);
    };
    void preorder(TreeNode *p);
    void postorder()
    {
        postorder(root);
    }
    void postorder(TreeNode *p);
    void inorder() { inorder(root); }
    void inorder(TreeNode *p);
    void Ipreorder();
    int nodeCount() { return nodeCount(root); }
    int nodeCount(TreeNode *p);
    int height(TreeNode *p);
    int height(){return height(root);};
};

int main()
{
    Tree tr;
    tr.create();
    cout << "preorder" << endl;
    tr.preorder();
    cout << "postorder" << endl;
    tr.postorder();
    cout << "inorder" << endl;
    tr.inorder();
    cout << "Iterative preorder" << endl;
    tr.Ipreorder();
    cout << "Height of tree is: "<< tr.height() << endl << "Number of nodes of tree are: " << tr.nodeCount() << endl;

    return 0;
}

void Tree::create()
{
    Queue q;
    TreeNode *temp;
    int x;
    cout << "Enter value in root node: ";
    cin >> x;
    cout << endl;
    if (x != -1)
    {
        temp = new TreeNode;
        temp->data = x;
        temp->left = temp->right = nullptr;
        q.enqueue(temp);
        root = temp;
    }
    else
    {
        return;
    }
    while (!q.isEmpty())
    {
        TreeNode *p = q.dequeue();
        cout << "Enter left child of " << p->data << "";
        cin >> x;
        cout << endl;
        if (x != -1)
        {
            temp = new TreeNode;
            temp->data = x;
            temp->left = temp->right = nullptr;
            p->left = temp;
            q.enqueue(temp);
        }
        cout << "Enter right child of " << p->data << " ";
        cin >> x;
        cout << endl;
        if (x != -1)
        {
            temp = new TreeNode;
            temp->data = x;
            temp->left = temp->right = nullptr;
            p->right = temp;
            q.enqueue(temp);
        }
    }
}

void Tree::preorder(TreeNode *p)
{
    if (p)
    {
        cout << p->data << endl;
        preorder(p->left);
        preorder(p->right);
    }
}

void Tree::postorder(TreeNode *p)
{
    if (p)
    {
        postorder(p->left);
        postorder(p->right);
        cout << p->data << endl;
    }
}

void Tree::inorder(TreeNode *p)
{
    if (p)
    {
        inorder(p->left);
        cout << p->data << endl;
        inorder(p->right);
    }
}

void Tree::Ipreorder()
{
    Stack st;
    TreeNode *p = root;
    while (p || !st.isEmpty())
    {
        if (p)
        {
            st.push(p);
            cout << p->data;
            p = p->left;
        }
        else
        {
            p = st.pop();
            p = p->right;
        }
    }
}

int Tree::nodeCount(TreeNode *p)
{
    if (p)
    {
        return nodeCount(p->left) + nodeCount(p->right) + 1;
    }
    return 0;
}

int Tree::height(TreeNode *p)
{
    if (p)
    {
        int x = height(p->left);
        int y = height(p->right);

        if (x > y)
        {
            return x + 1;
        }
        else if(y > x)
        {
            return y + 1;
        }
        else {return x + 1;}
    }
    return 0;
}

