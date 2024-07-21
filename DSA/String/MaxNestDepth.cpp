// Given a valid parentheses string s, return the nesting depth of s. The nesting depth is the maximum number of nested parentheses.

// A parentheses string is a valid parentheses string (denoted VPS) if it meets one of the following:

// It is an empty string "", or a single character not equal to "(" or ")",

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int maxDepth(string s)
{
    int depth = 0;
    int maxDepth = 0;
    for (char c = 0; c < s.size(); c++)
    {
        if (s[c] == '(')
        {
            depth++;
            maxDepth = max(maxDepth, depth);
        }
        else if (s[c] == ')')
        {
            depth--;
        }
    }
    return maxDepth;
}

int main()
{
    string s = "(1+(2*3)+(((8)/4))+1";
    cout << maxDepth(s) << endl;
    return 0;
}