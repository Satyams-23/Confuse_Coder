// postfix to infix

#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>

using namespace std;

int precedence(char c)
{
    if (c == '^')
    {
        return 3;
    }
    else if (c == '*' || c == '/')
    {
        return 2;
    }
    else if (c == '+' || c == '-')
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

string postfixToInfix(string s) //
{
    stack<string> st;
    string res;

    for (int i = 0; i < s.length(); i++)
    {
        // boolean check if the character is an operand
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
        {
            st.push(string(1, s[i])); //
        }
        else
        {
            string op1 = st.top();
            st.pop();
            string op2 = st.top();
            st.pop();
            st.push("(" + op2 + s[i] + op1 + ")");
        }
    }
    return st.top();
}

int main()
{
    string s = "ab*c+";
    cout << postfixToInfix(s) << endl; // ((a*b)+c)
    return 0;
}

// Time Complexity: O(N)
// Space Complexity: O(N)
