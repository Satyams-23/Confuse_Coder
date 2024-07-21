// //  How to use unordered_map in C++11

// // unordered_map is an associated container that stores elements formed by the combination of a key value and a mapped value. The key value is used to uniquely identify the element, and the mapped value is the content associated with the key. Both key and value can be of any type. The key value is immutable, which means it cannot be changed. The mapped value can be changed.

// // unordered_map is implemented using a hash table, which means that the elements are not stored in any particular order, and the elements are accessed using the key value.

// // unordered_map is part of the C++ Standard Template Library (STL).

// // example of unordered_map

// // #include <iostream>
// // #include <unordered_map>
// // #include <string>
// // using namespace std;

// // int function(string s)
// // {
// //     unordered_map<char, int> map;
// //     for (int i = 0; i < s.size(); i++)
// //     {
// //         map[s[i]]++;
// //         cout << map[s[i]] << endl;
// //     }

// //     for (auto i : map)
// //     {
// //         cout << i.first << " " << i.second << endl;
// //     }
// //     return 0;
// // }

// // int main()
// // {
// //     string s = "tree";
// //     cout << function(s) << endl;
// //     return 0;
// // }

// // example array of unordered_map

// // #include <iostream>
// // #include <unordered_map>
// // #include <vector>
// // using namespace std;

// // int funtion(vector<int> &arr)
// // {
// //     unordered_map<int, int> map;
// //     for (int i = 0; i < arr.size(); i++)
// //     {
// //         map[arr[i]]++;
// //         cout << map[arr[i]] << endl;
// //     }

// //     int res = 0;
// //     for (auto i : map)
// //     {
// //         if (i.second == 1)
// //         {
// //             res += i.first;
// //         }
// //         cout << i.first << " " << i.second << endl;
// //     }
// //     return res;
// // }

// // int main()
// // {
// //     vector<int> arr = {1, 2, 3, 4, 5, 1, 2, 3, 4};
// //     cout << funtion(arr) << endl;
// //     return 0;
// // }

// // example of code

// // integer to array
// // input: 4
// // output: 1 2 3 4

// // print prime number from array
// #include <iostream>
// #include <vector>
// #include <cmath>
// using namespace std;

// // Function to generate primes up to sqrt(n)
// vector<int> generatePrimes(int n)
// {
//     vector<int> res;
//     for (int i = 2; i <= n; i++)
//     {
//         bool flag = true;
//         for (int j = 2; j <= sqrt(i); j++)
//         {
//             if (i % j == 0)
//             {
//                 flag = false;
//                 break;
//             }
//         }
//         if (flag)
//         {
//             res.push_back(i);
//         }
//     }
//     return res;
// }

// // Function to find the minimum X + Y such that X^2 + Y^2 = n
// int findMinPrimeSum(int n)
// {
//     int limit = sqrt(n);
//     vector<int> primes = generatePrimes(limit);

//     int minSum = INT_MAX;
//     bool found = false;

//     for (int i = 0; i < primes.size(); i++)
//     {
//         for (int j = i; j < primes.size(); j++)
//         {
//             if (primes[i] * primes[i] + primes[j] * primes[j] == n)
//             {
//                 minSum = min(minSum, primes[i] + primes[j]);
//                 found = true;
//             }
//         }
//     }

//     if (found)
//     {
//         return minSum;
//     }
//     else
//     {
//         return -1;
//     }
// }

// int main()
// {
//     int n = 34; // Example input
//     int result = findMinPrimeSum(n);

//     cout << result << endl;

//     return 0;
// }

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Custom comparator function
bool compare(const string &X, const string &Y)
{
    // Compare concatenated results
    string XY = X + Y;
    string YX = Y + X;
    bool result = XY > YX;
    cout << "Comparing: " << X << " + " << Y << " (" << XY << ") and " << Y << " + " << X << " (" << YX << ") - Result: " << (result ? "True" : "False") << endl;
    return result;
}

string largestNumber(vector<string> &arr)
{
    // Print original array
    cout << "Original array: ";
    for (const auto &s : arr)
    {
        cout << s << " ";
    }
    cout << endl;

    // Sort the array using the custom comparator
    sort(arr.begin(), arr.end(), compare);

    // Print sorted array
    cout << "Sorted array: ";
    for (const auto &s : arr)
    {
        cout << s << " ";
    }
    cout << endl;

    // If the highest value is "0", return "0"
    if (arr[0] == "0")
    {
        return "0";
    }

    // Concatenate the sorted strings
    string result;
    for (string &s : arr)
    {
        result = result + s;
    }

    return result;
}

int main()
{
    vector<string> arr = {"54", "546", "548", "60"};
    string result = largestNumber(arr);
    cout << "Largest Number: " << result << endl; // Expected: "6054854654"

    return 0;
}
