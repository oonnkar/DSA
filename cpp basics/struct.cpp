#include <iostream>
using namespace std;

// struct is a user-defined data type that allows us to combine data items of different kinds

struct Student {
    int id;
    string name;
    float score;
};


// struct padding occurs when the compiler adds extra bytes between members of a struct to align them in memory for performance reasons. This can lead to the size of the struct being larger than the sum of its individual members.   
struct PaddingExample {
    int a;      // 4 bytes
    int b;       // 4 bytes
    char c;      // 1 byte
    // Total size may be larger than the sum of individual sizes due to padding
}; 

int main() {
    Student student1; // create a Student object

    // assign values to the members of student1
    student1.id = 1;
    student1.name = "John Doe";
    student1.score = 95.5;

    // print the values of student1
    cout << "Student ID: " << student1.id << endl;
    cout << "Student Name: " << student1.name << endl;
    cout << "Student Score: " << student1.score << endl;

    // intialize a Student object using an initializer list
    Student student2 = {2, "Jane Smith", 88.0};


    // demonstrate struct padding
    PaddingExample example;
    cout << "Size of PaddingExample struct: " << sizeof(example) << " bytes" << endl;
    return 0;
}