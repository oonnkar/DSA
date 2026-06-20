#include <iostream>
using namespace std;

// Template class is a blueprint for creating classes or functions that can work with any data type. It allows you to define a class or function that can operate on different data types without having to write separate code for each type. 
template <typename T>
class Arethamatic{
    private : T a; T b ; 
    public : Arethamatic(T a , T b){
        this->a = a ; 
        this->b = b ; 
    }

    T sum ();
    T multiply();
    T divide();
    T subtract();
};

template <typename T>
T Arethamatic<T>::sum(){
    
    return a + b ; 
}

template <typename T>
T Arethamatic<T>::multiply(){
    return a * b ; 
}

template <typename T>
T Arethamatic<T>::divide(){
    return a / b ; 
}

template <typename T>
T Arethamatic<T>::subtract(){
    return a - b ; 
}

int main() {
    Arethamatic<int> obj1(10, 5);
    Arethamatic<float> obj2(10.5, 5.2);
    Arethamatic<double> obj3(10.5, 5.2);
    return 0;
}