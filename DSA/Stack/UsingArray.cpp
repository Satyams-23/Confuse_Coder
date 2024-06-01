

#include <iostream>

using namespace std;
class Stack
{
    int size;
    int *arr;
    int top;

public:
    Stack()
    {
        size = 10;
        arr = new int[size];
        top = -1;
    }

    void push(int x)
    {
        top++;
        arr[top] = x;
    }

    int pop()
    {
        int x = arr[top];
        top--;
        return x;
    }

    int peek()
    {
        return arr[top];
    }

    int stackTop()
    {
        return arr[top];
    }

    int Size()
    {
        return top + 1;
    }

    bool isEmpty()
    {
        return top == -1;
    }

    bool isFull()
    {
        return top == size - 1;
    }
};

int main()
{
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    cout << "Top Element: " << s.stackTop() << endl;
    cout << "Size: " << s.Size() << endl;
    cout << "Is Empty: " << s.isEmpty() << endl;
    cout << "Is Full: " << s.isFull() << endl;
    cout << "Popped Element: " << s.pop() << endl;
    cout << "Top Element: " << s.stackTop() << endl;

    return 0;
}
