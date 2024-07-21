// Remove K digits from the number so that the new number is the smallest possible.

// Brute force approach: Remove K digits from the number and find the smallest number.

// approach: use stack to remove the digits from the number.

// #include <iostream>
// #include <stack>
// #include <string>

// using namespace std;

// string removeKdigit(string num, int k)

// {
//     stack<char> s;
//     for (int i = 0; i < num.length(); i++)
//     {
//         while (!s.empty() && k > 0 && s.top() > num[i])
//         {
//             s.pop();
//             k--;
//         }
//         if (num[i] != '0' || !s.empty())
//         {
//             s.push(num[i]);
//         }
//     }
//     while (!s.empty() && k > 0)
//     {
//         s.pop();
//         k--;
//     }
//     string ans = "";
//     while (!s.empty())
//     {
//         ans = s.top() + ans;
//         s.pop();
//     }
//     if (ans == "")
//     {
//         return "0";
//     }
//     return ans;
// }

// int main()
// {
//     string num = "1432219";
//     int k = 3;
//     cout << removeKdigit(num, k);
//     return 0;
// }

// Time complexity: O(n)
// Space complexity: O(n)

// optimized approach: use stack to remove the digits from the number. Use string instead of stack.  O(n) time complexity and O(n) space complexity.

#include <iostream>
#include <string>

using namespace std;

string removeKdigit(string num, int k)

{
    string ans = "";
    for (int i = 0; i < num.length(); i++)
    {
        while (!ans.empty() && k > 0 && ans.back() > num[i]) //
        {
            ans.pop_back(); //
            k--;
        }
        if (num[i] != '0' || !ans.empty()) //
        {
            ans.push_back(num[i]);
        }
    }
    while (!ans.empty() && k > 0)
    {
        ans.pop_back();
        k--;
    }
    if (ans == "")
    {
        return "0";
    }
    return ans;
}

int main()
{
    string num = "1432219";
    int k = 3;
    cout << removeKdigit(num, k);
    return 0;
}
/

    // Time complexity: O(n)
    // Space complexity: O(n)
