
#include <iostream>
#include <queue>

using namespace std;

class Queue
{
    int front, rear, size;
    int *arr;
    queue<int> q;

public:
    Queue()
    {
        front = rear = -1;
        size = 10;
        arr = new int[size];
    }

    Queue(int size)
    {
        this->size = size;
        front = rear = -1;
        arr = new int[size];
    }

    void push(int x)
    {
        if (rear == size - 1)
        {
            cout << "Queue is full" << endl;
            return;
        }
        if (front == -1)
        {
            front = 0;
        }
        arr[++rear] = x;
    }

    int pop()
    {
        if (front == -1)
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        int x = arr[front];
        if (front >= rear)
        {
            front = rear = -1;
        }
        else
        {
            front++;
        }
        return x;
    }

    int top()
    {
        if (front == -1)
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return arr[front];
    }

    int size()
    {
        if (front == -1)
        {
            return 0;
        }
        return rear - front + 1;
    }
};

int main()
{
    Queue q(6);

    q.push(4);
    q.push(14);
    q.push(24);
    q.push(34);

    cout << "The peek of the queue before deleting any element " << q.top() << endl;
    cout << "The size of the queue before deletion " << q.size() << endl;
    cout << "The first element to be deleted " << q.pop() << endl;
    cout << "The peek of the queue after deleting an element " << q.top() << endl;
    cout << "The size of the queue after deleting an element " << q.size() << endl;

    return 0;
}