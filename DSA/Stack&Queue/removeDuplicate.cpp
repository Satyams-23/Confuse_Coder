// Remove duplicate elements with string

#include <iostream>
#include <string>
#include <stack>

using namespace std;

string removeDuplicate(string s)
{
    stack<char> st;
    for (char c : s)
    {
        if (!st.empty() && st.top() == c)
        {
            st.pop();
        }
        else
        {
            st.push(c);
        }
    }
    string ans = "";
    while (!st.empty())
    {
        ans = st.top() + ans;
        st.pop();
    }
    return ans;
}

// Remove duplicate elements with string 2
// input: "deeedbbdbaa" k = 3
// output: "aa"

string removeDuplicate2(string s, int k)
{
    stack<pair<char, int>> st;
    if (k == 1)
    {
        return "";
    }

    for (char c : s)
    {
        if (!st.empty() && st.top().first == c)
        {
            st.top().second++;
            if (st.top().second == k)
            {
                st.pop();
            }
        }
        else
        {
            st.push({c, 1});
        }
    }

    string ans = "";
    while (!st.empty())
    {
        ans = string(st.top().second, st.top().first) + ans;
        st.pop();
    }
    return ans;
}