#include <iostream>
using namespace std;

/**
 * @brief A Queue implementation using a singly linked list.
 */
class Queue
{
private:
    /**
     * @brief Represents a node in the linked list.
     */
    class Node
    {
    public:
        int data;   ///< Stores the queue element.
        Node *next; ///< Pointer to the next node.
    };

    Node *front; ///< Points to the front element of the queue.
    Node *rear;  ///< Points to the rear element of the queue.

public:
    /**
     * @brief Constructs an empty queue.
     */
    Queue()
    {
        front = rear = nullptr;
    }

    /**
     * @brief Inserts a new element at the rear of the queue.
     *
     * @param x The integer value to be inserted into the queue.
     *
     * @return void
     */
    void enqueue(int x)
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

    /**
     * @brief Removes and returns the front element of the queue.
     *
     * @return int The removed element. Returns -1 if the queue is empty.
     */
    int dequeue()
    {
        int x = -1;

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

    /**
     * @brief Displays all elements of the queue from front to rear.
     *
     * @return void
     */
    void display()
    {
        Node *p = front;

        while (p)
        {
            cout << p->data << " ";
            p = p->next;
        }

        cout << endl;
    }
};

int main()
{
    Queue q;

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);

    q.dequeue();

    q.display();

    return 0;
}