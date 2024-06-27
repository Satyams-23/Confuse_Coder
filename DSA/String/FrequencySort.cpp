

// Given a string s, sort it in decreasing order based on the frequency of the characters. The frequency of a character is the number of times it appears in the string.
// Return the sorted string. If there are multiple answers, return any of them.

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

string frequencySort(string s)
{
    unordered_map<char, int> freq;
    for (char c : s)
    {
        // cout << c << " ";
        freq[c]++;
        // cout << freq[c] << " " << c << endl;
    }

    // store the frequency of each character in the string
    priority_queue<pair<int, char>> pq; // means that the pair with the highest frequency will be at the top examle: (3, 'e') (2, 't') (1, 'r')
    for (auto p : freq)
    {
        pq.push({p.second, p.first});
        // cout << p.second << " " << p.first << endl;
    }

    string ans = "";

    // pop the top element from the priority queue and append it to the answer string that many times as its frequency is there in the string s
    while (!pq.empty())
    {
        auto p = pq.top();
        pq.pop();
        ans += string(p.first, p.second);
        cout << p.first << " " << p.second << endl;
        cout << ans << endl;
    }
}

int main()
{
    string s = "tree";
    cout << frequencySort(s) << endl;
    return 0;
}