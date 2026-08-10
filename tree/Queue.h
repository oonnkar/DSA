#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
using namespace std;

class TreeNode;

/**
 * @brief A Queue implementation using a singly linked list.
 */
class Queue
{
private:
    class Node
    {
    public:
        TreeNode *data; ///< Stores the queue element.
        Node *next;     ///< Pointer to the next node.
    };

    Node *front; ///< Points to the front element of the queue.
    Node *rear;  ///< Points to the rear element of the queue.

public:
    Queue()
    {
        front = rear = nullptr;
    }

    void enqueue(TreeNode *x)
    {
        Node *temp = new Node;

        if (!temp)
        {
            cout << "Queue is full" << endl;
            return;
        }

        temp->data = x;
        temp->next = nullptr;

        if (front == nullptr)
        {
            front = rear = temp;
            return;
        }

        rear->next = temp;
        rear = temp;
    }

    TreeNode *dequeue()
    {
        TreeNode *x = nullptr;

        if (front == nullptr)
        {
            cout << "Queue is empty" << endl;
            return x;
        }

        Node *p = front;
        x = p->data;
        front = front->next;
        delete p;

        // If the queue becomes empty, update rear as well.
        if (front == nullptr)
        {
            rear = nullptr;
        }

        return x;
    }

    int isEmpty()
    {
        return front ? 0 : 1;
    }
};

#endif // QUEUE_H
