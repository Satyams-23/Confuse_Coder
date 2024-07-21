// // word break problem

// #include <iostream>
// #include <vector>
// #include <unordered_set> // unordered_set is used to store unique elements in the set and it is faster than set because it uses hashing
// using namespace std;

// bool wordBreakhelper(string s, unordered_set<string> &dict, int start, vector<int> &dp)
// {
//     if (start == s.size())

//     {
//         return true;
//     }

//     if (dp[start] != -1)
//     {
//         return dp[start];
//     }

//     for (int end = start + 1; end <= s.size(); end++)
//     {
//         if (dict.find(s.substr(start, end - start)) != dict.end() && wordBreakhelper(s, dict, end, dp))

//         {
//             cout << "start" << start << endl;
//             cout << "end" << end << endl;
//             cout << "s.substr(start, end - start)" << s.substr(start, end - start) << endl;
//             return dp[start] = 1;
//         }

//         cout << " substr" << s.substr(start, end - start) << endl;
//     }

//     return dp[start] = 0; //
//     cout << "dp[start]" << dp[start] << endl;
//     cout << endl;
// }

// bool wordBreak(string s, vector<string> &wordDict)
// {
//     unordered_set<string> dict(wordDict.begin(), wordDict.end()); // unordered_set is used to store unique elements in the set and it is faster than set because it uses hashing
//     cout << dict.size() << endl;
//     vector<int> dp(s.size(), -1);
//     cout << "dp size" << dp.size() << endl;
//     return wordBreakhelper(s, dict, 0, dp); //
// }

// int main()
// {
//     string s = "leetcode";
//     vector<string> wordDict = {"leet", "code"};
//     cout << wordBreak(s, wordDict) << endl;
//     return 0;
// }

// Tabulation Method

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

bool wordBreak(string s, vector<string> &wordDict)
{
    unordered_set<string> dict(wordDict.begin(), wordDict.end());

    cout << dict.size() << endl;
    vector<int> dp(s.size() + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= s.size(); i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (dp[j] && dict.find(s.substr(j, i - j)) != dict.end()) // s.substr(j, i - j) means from j to i-j of the string s and dict.find(s.substr(j, i - j)) != dict.end() means if the substring is present in the dictionary then return true

                cout << "s.substr(j, i - j)" << s.substr(j, i - j) << endl;
            {

                cout << "j" << j << endl;
                cout << "i" << i << endl;
                cout << "dp[j]" << dp[j] << endl;
                cout << "dp[i]" << dp[i] << endl;

                dp[i] = 1;
                break;
            }
        }
    }

    return dp[s.size()];
}

int main()
{
    string s = "leetcode";
    vector<string> wordDict = {"leet", "code"};
    cout << (wordBreak(s, wordDict) ? "True" : "False") << endl;
    return 0;
}