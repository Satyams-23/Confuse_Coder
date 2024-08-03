// Problem Statement: Implement Min Stack | O(2N) and O(N) Space Complexity. Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

#include <iostream>
#include <stack>

using namespace std;

class MinStack
{
    stack<int> st;
    stack<int> minSt;

public:
    void push(int x)
    {
        st.push(x);

        if (minSt.empty() || x <= minSt.top()) //
        {
            minSt.push(x);
        }
    }

    void pop()
    {
        if (st.top() == minSt.top()) // If the top element of the stack is the minimum element, then pop the top element of the minSt stack. //
        {
            minSt.pop();
        }
        st.pop();
    }

    int top()
    {
        return st.top();
    }

    int getMin()
    {
        return minSt.top();
    }
};

int main()
{
    MinStack minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    minStack.push(-4);
    minStack.push(-5);
    cout << minStack.getMin() << endl; // -3
    minStack.pop();
    cout << minStack.top() << endl;    // 0
    cout << minStack.getMin() << endl; // -2
    return 0;
}