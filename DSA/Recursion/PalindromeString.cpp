// PalindromeString - Check if a string is palindrome or not

// brute force approach - reverse the string and check if it is equal to the original string
#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string s)
{
    int start = 0;
    int end = s.size() - 1;

    while (start < end)
    {
        if (s[start++] != s[end--])
        {
            return false;
            cout << "0" << endl;
        }
        cout << "1" << endl;
    }
    return true;
    cout << "1" << endl;
}

int main()
{
    string s = "madam1";
    isPalindrome(s);
    return 0;
}

// Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.

// brute force approach - generate all possible substrings and check if they are palindrome or not
// #include <iostream>
// #include <vector>
// #include <string>
// using namespace std;

// bool isPalindrome(string s)
// {
//     int i = 0, j = s.size() - 1;
//     while (i < j)
//     {
//         if (s[i] != s[j])
//         {
//             return false;
//         }
//         i++;
//         j--;
//     }
//     return true;
// }

// void partition(string s, vector<string> &path, vector<vector<string>> &result)
// {
//     if (s.size() == 0)
//     {
//         result.push_back(path);
//         cout << "Path found: [";
//         for (auto str : path)
//         {
//             cout << "\"" << str << "\", ";
//         }
//         cout << "]" << endl;
//         return;
//     }

//     for (int i = 1; i <= s.size(); i++)
//     {
//         string prefix = s.substr(0, i);
//         cout << "Prefix: " << prefix << endl;

//         if (isPalindrome(prefix))
//         {
//             path.push_back(prefix);
//             cout << "Adding \"" << prefix << "\" to path, current path: [";
//             for (auto str : path)
//             {
//                 cout << "\"" << str << "\", ";
//             }
//             cout << "]" << endl;

//             partition(s.substr(i), path, result);

//             path.pop_back();
//             cout << "Backtracking, removing \"" << prefix << "\" from path, current path: [";
//             for (auto str : path)
//             {
//                 cout << "\"" << str << "\", ";
//             }
//             cout << "]" << endl;
//         }
//         else
//         {
//             cout << "Skipping \"" << prefix << "\" as it is not a palindrome" << endl;
//         }
//     }
// }

// int main()
// {
//     string s = "aabb";
//     vector<vector<string>> result;
//     vector<string> path;
//     partition(s, path, result);

//     cout << "Final Result: " << endl;
//     cout << "[";
//     for (auto vec : result) // means for each vector vec in result print vec and comma " " after vec is printed
//                             // cout << result << endl;
//     {
//         cout << "[";
//         for (auto str : vec)
//         {
//             cout << "\"" << str << "\", ";
//         }
//         cout << "], ";
//     }
//     cout << "]" << endl;

//     return 0;
// }

// Time Complexity: O(n * 2^n)
// Space Complexity: O(n)

// Optimized approach - backtracking
