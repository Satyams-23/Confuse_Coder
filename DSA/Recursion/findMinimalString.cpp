#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

// Function to check if a substring exists in the set of substrings
bool findMinimalString(string &b, const unordered_set<string> &substrings, size_t pos)
{
    if (pos == b.length())
    {
        cout << "Checking substring: " << b << endl;
        return substrings.find(b) == substrings.end();
    }
    for (char ch = 'a'; ch <= 'z'; ++ch)
    {
        b[pos] = ch;
        cout << "Trying character: " << ch << " at position: " << pos << " -> " << b << endl;
        if (findMinimalString(b, substrings, pos + 1))
        {
            return true;
        }
    }
    return false;
}

// Function to find all substrings of a given string and store them in a set
void findAllSubstrings(const string &s, unordered_set<string> &substringSet)
{
    size_t n = s.length();
    for (size_t len = 1; len <= n; ++len)
    {
        for (size_t i = 0; i <= n - len; ++i)
        {
            string sub = s.substr(i, len);
            substringSet.insert(sub);
            cout << "Inserting substring: " << sub << endl;
        }
    }
}

// Function to find the lexicographically smallest minimal string b using DP
string findSmallestMissingSubstring(const string &s)
{
    unordered_set<string> substrings;
    findAllSubstrings(s, substrings);

    string b;
    for (size_t len = 1;; ++len)
    {
        b.resize(len);
        cout << "Trying length: " << len << " for string b" << endl;
        if (findMinimalString(b, substrings, 0))
        {
            return b;
        }
    }
}

int main()
{
    string s = "abac";
    cout << "The lexicographically smallest minimal string is: " << findSmallestMissingSubstring(s) << endl;
    return 0;
}
