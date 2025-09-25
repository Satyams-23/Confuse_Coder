// #include <iostream>
// #include <vector>
// using namespace std;

// bool isPalindrome(const string &s)
// {
//     int left = 0;
//     int right = s.size() - 1;

//     while (left < right)
//     {
//         if (s[left] != s[right])
//         {
//             return false;
//         }
//         left++;
//         right--;
//     }
//     return true;
// }

// int main()
// {
//     string s = "racecar";
//     if (isPalindrome(s))
//         cout << s << true << endl;
//     else
//         cout << s << false << endl;
//     return 0;
//     //             result.push_back(map[target - nums[i]]);
// }
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s = "racecar";
    string result = "";

    for (char c : s)
    {
        if (isalnum(c))
        {
            result = c + result;
        }
    }

    // compare reversed
    if (result == s)
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }

    return 0;
}
