// Balanced Parentheses

#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isBalanced(string s)
{
    stack<char> st;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
        {
            st.push(s[i]);
        }
        else if (s[i] == ')')
        {
            if (st.empty() || st.top() != '(')
            {
                return false;
            }
            st.pop();
        }
        else if (s[i] == '}')
        {
            if (st.empty() || st.top() != '{')
            {
                return false;
            }
            st.pop();
        }
        else if (s[i] == ']')
        {
            if (st.empty() || st.top() != '[')
            {
                return false;
            }
            st.pop();
        }
    }