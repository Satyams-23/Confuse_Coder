// Implementing Queue using Stack

#include <iostream>
#include <stack>

using namespace std;
class Queue
{
    stack<int> s1, s2;

public:
    void push(int x)
    {
        s1.push(x);
    }

    int pop()
    {
        if (s1.empty() && s2.empty())
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        if (s2.empty())
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        int topVal = s2.top();
        s2.pop();
        return topVal;
    }

    int peek()
    {
        if (s1.empty() && s2.empty())
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        if (s2.empty())
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();
    }

    bool empty()
    {
        if (s1.empty() && s2.empty())
        {
            return true;
        }
        return false;
    }

    int size()
    {
        return s1.size() + s2.size();
    }
};

int main()
{
    Queue q;
    q.push(3);
    q.push(4);
    cout << "The element poped is " << q.pop() << endl;
    q.push(5);
    cout << "The top of the queue is " << q.peek() << endl;
    cout << "The size of the queue is " << q.size() << endl;

    return 0;
}
