
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

bool canConstruct(string &magazine, string &ransomNote)
{
    unordered_map<char, int> charCount;
    // Count characters in the magazine
    for (char ch : magazine)
    {
        charCount[ch]++;
    }
    cout << "Character counts from magazine:" << endl; // Debug statement
    // Check if ransomNote can be constructed
    for (char ch : ransomNote)
    {
        if (charCount[ch] > 0)
        {

            cout << "Using character: " << ch << endl; // Debug statement
            charCount[ch]--;
            cout << "Remaining count of " << ch << ": " << charCount[ch] << endl; // Debug statement
        }
        else
        {
            return false; // Character not available or insufficient count
        }
    }

    return true; // All characters found
}

int main()
{
    string magazine = "aab";
    string ransomNote = "aa";

    if (canConstruct(magazine, ransomNote))
    {
        cout << "Ransom note can be constructed from the magazine." << endl;
    }
    else
    {
        cout << "Ransom note cannot be constructed from the magazine." << endl;
    }

    return 0;
}