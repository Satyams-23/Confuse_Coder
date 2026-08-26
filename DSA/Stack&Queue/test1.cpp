#include <iostream>
#include <stack>
#include <string>
using namespace std;

class ArrayStack{
    private:
    int top;
    int capacity;
    int *array;
    public:
    ArrayStack(int size){
        top = -1;
        capacity = size;
        array = new int[capacity];
    }
    ~ArrayStack(){//destructor to free the memory
        delete[] array;
    }
    bool isEmpty(){//check if the stack is empty
        return top == -1;
    }
    bool isFull(){
        return top == capacity - 1;
    }
    void push(int element){
}