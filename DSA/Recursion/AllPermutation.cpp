// Print All Permutation of a string/array

// A permutation, also called an “arrangement number” or “order,” is a rearrangement of the elements of an ordered list S into a one-to-one correspondence with S itself. A string of length n has n! permutation.

// Recursion Approach

#include <iostream>
#include <vector>
using namespace std;

void printPermutation(string str, string ans)
{
    cout << "Called printPermutation with str = \"" << str << "\" and ans = \"" << ans << "\"" << endl;

    if (str.length() == 0)
    { // base case when string is empty print the ans
        cout << "Base case reached: ans = \"" << ans << "\"" << endl;
        cout << ans << endl;
        return;
    }

    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];
        cout << "Character: " << ch << " at index " << i << endl;
        string ros = str.substr(0, i) + str.substr(i + 1); // remove the character from the string and call the function recursively with the remaining string and ans + ch as the new ans
        cout << "Remaining string: \"" << ros << "\" after removing character \"" << ch << "\"" << endl;
        printPermutation(ros, ans + ch);
        cout << "Returning from call with str = \"" << ros << "\" and ans = \"" << ans + ch << "\"" << endl;
    }
}

int main()
{
    string str = "ABC";
    cout << "Starting permutations for string: \"" << str << "\"" << endl;
    printPermutation(str, "");
    return 0;
}
