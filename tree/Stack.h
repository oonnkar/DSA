#ifndef STACK_H
#define STACK_H
#include<iostream>
using namespace std;
class TreeNode;

class Stack
{
private:
    class Node
    {
    public:
        TreeNode *data;
        Node *next;
    };
    Node *top;

public:
    // Default Constructor
    Stack()
    {
        top = nullptr;
    }

    void push(TreeNode *x)
    {
        Node *temp = new Node;
        if (temp)
        {
            temp->data = x;
            temp->next = top;
            top = temp;
        }
        else
        {
            cout << "Stack overflow (Heap Memory Full)" << endl;
        }
    }

    TreeNode *pop()
    {
        TreeNode *x = nullptr;
        if (top)
        {
            Node *p = top;
            x = p->data;
            top = top->next;
            delete p;
            return x;
        }
        return x;
    }

    int isEmpty()
    {
        return top ? 0 : 1;
    }
};



#endif // STACK_H
