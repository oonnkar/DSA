#include <iostream>
using namespace std;

struct Student
{
    int id;
    string name;
};

int main()
{
    Student s1 = {1, "Alice"};
    Student *ptr = &s1;

    // Accessing struct members using pointer
    // ptr->id accesses the 'id' member of the struct that ptr points to
    // ptr->name accesses the 'name' member of the struct that ptr points to
    // -> is the member access operator for pointers to structs we cannot use the dot operator (.) directly on a pointer, so we use the arrow operator (->) instead. we have other ways to access the members of a struct using pointers, such as dereferencing the pointer and then using the dot operator, like (*ptr).id and (*ptr).name. However, using the arrow operator is more concise and preferred in this case.
    cout << "ID: " << ptr->id << ", Name: " << ptr->name << endl;
    cout << "ID: " << (*ptr).id << ", Name: " << (*ptr).name << endl;

    // both methods will give the same output, but using the arrow operator is more common and readable when working with pointers to structs.

    // create another object of Student in heap memory using new operator
    Student *ptr2 = new Student{2, "Bob"};
    cout << "ID: " << ptr2->id << ", Name: " << ptr2->name << endl;

    // Don't forget to free the memory allocated with 'new'
    delete ptr2;

    return 0;
}