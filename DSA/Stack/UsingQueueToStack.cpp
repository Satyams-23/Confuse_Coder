// Implementing Stack using Single Queue

#include <iostream>
#include <queue>

using namespace std;

class Stack
{

    queue<int> q;

public:
    void push(int x)
    {
        int size = q.size();
        q.push(x);
        for (int i = 0; i < size; i++)
        {
            q.push(q.front()); //
            q.pop();
        }
    }

    int pop()
    {
        int n = q.front();
        q.pop();
        return n;
    }

    int top()
    {
        return q.front();
    }

    int size()
    {
        return q.size();
    }

    bool isEmpty()
    {
        return q.empty();
    }
};

int main()
{
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    cout << s.top() << endl;
    cout << s.pop() << endl;
    cout << s.top() << endl;
    cout << s.size() << endl;
    cout << s.isEmpty() << endl;

    return 0;
}