#include <iostream>
using namespace std;

class Stack
{
private:
    class Node
    {
    public:
        int data;
        Node *next;
    };
    Node *top;

public:
    // Default Constructor
    Stack()
    {
        top = nullptr;
    }

    // Single Value Constructor
    Stack(int x)
    {
        top = nullptr; // Always initialize top first
        push(x);
    }

    // Array Constructor
    Stack(int *a, int size)
    {
        top = nullptr; // Crucial: set initial top to nullptr
        for (int i = 0; i < size; i++)
        {
            push(a[i]);
        }
    }

    // Destructor to free dynamic memory
    ~Stack()
    {
        while (top != nullptr)
        {
            pop();
        }
    }

    void push(int x)
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

    int pop()
    {
        int x = -1;
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

    void display()
    {
        Node *p = top;
        cout << "Stack (top to bottom): ";
        while (p)
        {
            cout << p->data << " "; // Added space for legibility
            p = p->next;
        }
        cout << endl;
    }

    int peek()
    {
        return top ? top->data : -1;
    }

    // FIX: Initialize p = top
    int peekAtPosition(int pos)
    {
        Node *p = top; // Fixed uninitialized pointer
        for (int i = 0; p != nullptr && i < pos - 1; i++)
        {
            p = p->next;
        }
        return p ? p->data : -1;
    }
};

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    Stack st(arr, 5);

    st.display();                                                            // Output: 5 4 3 2 1
    cout << "Item at position 2 from top: " << st.peekAtPosition(2) << endl; // Output: 4

    return 0;
}