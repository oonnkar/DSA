#include <iostream>
using namespace std;

/**
 * @brief Circular Queue implementation using an array.
 *
 * This queue uses the circular queue technique to efficiently utilize the array. One array position is intentionally left unused to distinguish between a full queue and an empty queue.
 */
class Queue
{
public:
    int size;  ///< Total size of the array.
    int *arr;  ///< Pointer to the dynamically allocated array.
    int front; ///< Points to the position before the first element.
    int rear;  ///< Points to the last inserted element.

    /**
     * @brief Constructs a circular queue of the given size.
     *
     * @param size Maximum size of the underlying array.
     */
    Queue(int size)
    {
        this->size = size;
        front = rear = 0;
        arr = new int[size];
    }

    /**
     * @brief Inserts an element at the rear of the queue.
     *
     * If the queue is full, the element is not inserted.
     *
     * @param x Element to be inserted into the queue.
     * @return void
     */
    void enque(int x)
    {
        if ((rear + 1) % size == front)
        {
            cout << "Queue is full" << endl;
        }
        else
        {
            rear = (rear + 1) % size;
            arr[rear] = x;
        }
    }

    /**
     * @brief Removes and returns the front element of the queue.
     *
     * If the queue is empty, -1 is returned.
     *
     * @return int The dequeued element, or -1 if the queue is empty.
     */
    int dequeue()
    {
        int x = -1;

        if (front == rear)
        {
            cout << "Queue is empty" << endl;
            return x;
        }

        front = (front + 1) % size;
        x = arr[front];

        return x;
    }

    /**
     * @brief Displays all elements currently present in the queue.
     *
     * Elements are printed from the front of the queue to the rear.
     *
     * @return void
     */
    void display()
    {
        int i = (front + 1) % size;

        while (i != (rear + 1) % size)
        {
            cout << arr[i] << endl;
            i = (i + 1) % size;
        }
    }
};
int main()
{

    Queue q(5);
    q.enque(1);
    q.enque(2);
    q.enque(3);
    q.enque(4);
    q.enque(5);
    q.display();
    return 0;
}