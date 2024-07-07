// Example 1:

// Input: s = "42"

// Output: 42

// Explanation:

// The underlined characters are what is read in and the caret is the current reader position.
// Step 1: "42" (no characters read because there is no leading whitespace)
//          ^
// Step 2: "42" (no characters read because there is neither a '-' nor '+')
//          ^
// Step 3: "42" ("42" is read in)

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int myAtoi(string s)
{
    int i = 0;
    int sign = 1;
    int result = 0;
    while (i < s.size() && s[i] == ' ')
    {
        i++;
    }
    if (i < s.size() && (s[i] == '+' || s[i] == '-'))
    {
        sign = (s[i++] == '-') ? -1 : 1;
    }
    while (i < s.size() && isdigit(s[i]))
    {
        if (result > INT_MAX / 10 || (result == INT_MAX / 10 && s[i] - '0' > INT_MAX % 10))
        {
            return (sign == 1) ? INT_MAX : INT_MIN;
        }
        result = result * 10 + (s[i++] - '0');
    }
    return result * sign;
}

int main()
{
    string s = "42";
    cout << myAtoi(s) << endl;
    return 0;
}
