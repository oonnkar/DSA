#include <iostream>
using namespace std;
// Time complexity is the amount of time taken by prosedure to complete task. It is denoted by O(n) where n is the size of input.
// Space complexity is the amount of space taken by prosedure to complete task. It is denoted by O(n) where n is the size of input.

// time complexity of swap function is O(1) because it takes constant time to swap two numbers.
// we assume single statement takes constant time. So, the time taken by swap function is constant time. statements like assignment, arithmetic operations, etc. take constant time. So, the time complexity of swap function is O(1).
// space complexity of swap function is O(1) because it takes constant space to swap two numbers. We are using only a constant amount of space to store the temporary variable. So, the space taken by swap function is constant space. Hence, the space complexity of swap function is O(1).
int swap(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
    return 0;
}
// time complexity of for loop is O(n) because it takes linear time to execute the loop n times. The loop runs n times and each iteration takes constant time. So, the total time taken by the loop is proportional to n. Hence, the time complexity of for loop is O(n).
int forLoop() {
    int arr[5] ={1 , 2, 3, 4, 5};
    int c = 0;
    for (int i = 0; i < 5; i++) {
        c += arr[i];
    }
    return 0;
}
// time complexity of nested for loops is O(n^2) because it takes quadratic time to execute the nested loops. The outer loop runs n times and the inner loop runs n times for each iteration of the outer loop. So, the total time taken by the nested loops is proportional to n^2. Hence, the time complexity of nested for loops is O(n^2).
// accurate time function 2n^2 + 2n + 1 we consider only the highest order term which is n^2 and ignore the constant and lower order terms. So, the time complexity of nested for loops is O(n^2).
int forforLoop(int n) {
    cout << "Nested for loops: " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << i << " " << j << endl;
        }
    }
    return 0;
}

int main() {
    swap(5, 10);
    forLoop();
    forforLoop(5);
    return 0;
}