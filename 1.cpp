//  How to use unordered_map in C++11

// unordered_map is an associated container that stores elements formed by the combination of a key value and a mapped value. The key value is used to uniquely identify the element, and the mapped value is the content associated with the key. Both key and value can be of any type. The key value is immutable, which means it cannot be changed. The mapped value can be changed.

// unordered_map is implemented using a hash table, which means that the elements are not stored in any particular order, and the elements are accessed using the key value.

// unordered_map is part of the C++ Standard Template Library (STL).

// example of unordered_map

#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int function(string s)
{
    unordered_map<char, int> map;
    for (int i = 0; i < s.size(); i++)
    {
        map[s[i]]++;
        cout << map[s[i]] << endl;
    }

    for (auto i : map)
    {
        cout << i.first << " " << i.second << endl;
    }
    return 0;
}

int main()
{
    string s = "tree";
    cout << function(s) << endl;
    return 0;
}

// example array of unordered_map

// #include <iostream>
// #include <unordered_map>
// #include <vector>
// using namespace std;

// int funtion(vector<int> &arr)
// {
//     unordered_map<int, int> map;
//     for (int i = 0; i < arr.size(); i++)
//     {
//         map[arr[i]]++;
//         cout << map[arr[i]] << endl;
//     }

//     int res = 0;
//     for (auto i : map)
//     {
//         if (i.second == 1)
//         {
//             res += i.first;
//         }
//         cout << i.first << " " << i.second << endl;
//     }
//     return res;
// }

// int main()
// {
//     vector<int> arr = {1, 2, 3, 4, 5, 1, 2, 3, 4};
//     cout << funtion(arr) << endl;
//     return 0;
// }

// example of code
