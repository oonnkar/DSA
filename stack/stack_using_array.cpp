#include <iostream>
using namespace std;

/**
 * @brief Array-based Stack Implementation
 *
 * Stack is a linear data structure operating on the Last-In, First-Out (LIFO) principle.
 * Elements are inserted and removed from the same end, referred to as 'top'.
 */
class stkArr
{
private:
    int size; // Maximum capacity of the stack
    int *arr; // Pointer to dynamically allocated array
    int top;  // Index of the current top element (-1 when stack is empty)

public:
    /**
     * @brief Constructor to initialize stack with a given capacity
     * @param size Maximum number of elements the stack can store
     */
    stkArr(int size)
    {
        this->size = size;
        arr = new int[size]; // Dynamically allocate memory for array
        top = -1;            // Initialize top to -1 (empty state)
    }

    /**
     * @brief Destructor to deallocate memory and avoid memory leaks
     */
    ~stkArr()
    {
        delete[] arr; // Free dynamically allocated array memory
    }

    /**
     * @brief Displays stack elements from Top to Bottom
     */
    void display()
    {
        if (isEmpty())
        {
            cout << "Stack is empty." << endl;
            return;
        }

        cout << "Stack contents (top to bottom):" << endl;
        for (int i = top; i >= 0; i--)
        {
            cout << arr[i] << endl;
        }
    }

    /**
     * @brief Inserts an element onto the top of the stack
     * @param x Element to be pushed
     */
    void push(int x)
    {
        // Check for Stack Overflow condition
        if (isFull())
        {
            cout << "Stack Overflow: Cannot push " << x << ", stack is full." << endl;
        }
        else
        {
            top++;        // Increment top index
            arr[top] = x; // Place element at top
        }
    }

    /**
     * @brief Removes the top element from the stack
     */
    void pop()
    {
        // Check for Stack Underflow condition
        if (isEmpty())
        {
            cout << "Stack Underflow: Cannot pop, stack is empty." << endl;
        }
        else
        {
            arr[top] = -1; // Optional: Reset popped element value
            top--;         // Decrement top index
        }
    }

    /**
     * @brief Retrieves the element at a specific 1-based position from the top
     * @param position 1-based position relative to top (1 = top element, 2 = 2nd from top)
     * @return Value at the position, or -1 if invalid
     */
    int peekFromTop(int position)
    {
        // Formula to calculate array index from top offset: index = top - position + 1
        int targetIndex = top - position + 1;

        if (position >= 1 && targetIndex >= 0)
        {
            return arr[targetIndex];
        }

        cout << "Invalid position!" << endl;
        return -1;
    }

    /**
     * @brief Returns the value of the top element without removing it
     * @return Top element value, or -1 if empty
     */
    int peek()
    {
        return !isEmpty() ? arr[top] : -1;
    }

    /**
     * @brief Checks whether the stack is empty
     * @return 1 if true, 0 if false
     */
    int isEmpty()
    {
        return (top == -1) ? 1 : 0;
    }

    /**
     * @brief Checks whether the stack has reached maximum capacity
     * @return 1 if true, 0 if false
     */
    int isFull()
    {
        return (top == size - 1) ? 1 : 0;
    }
};

int main()
{
    // Initialize stack with capacity of 5
    stkArr sa(5);

    // Push elements into stack
    sa.push(1);
    sa.push(2);
    sa.push(3);
    sa.push(4);
    sa.push(5);

    // Attempting to push into a full stack triggers Stack Overflow
    sa.push(6);

    // Inspect top element
    cout << "Current top element: " << sa.peek() << endl
         << endl;

    // Display entire stack
    sa.display();

    // Query stack state
    cout << "\nIs stack empty? " << (sa.isEmpty() ? "Yes" : "No") << endl;
    cout << "Is stack full?  " << (sa.isFull() ? "Yes" : "No") << endl;

    return 0;
}