// #include <iostream>
// #include <vector>
// #include <string>
// using namespace std;

// void generatePermutation(int n, vector<int> &nums, vector<vector<int>> &res, vector<int> &path, vector<bool> &used)
// {
//     cout << "Entering generatePermutation with path size: " << path.size() << endl;
//     if (path.size() == n) //
//     {
//         res.push_back(path);
//         cout << "Path found: ";
//         for (auto num : path)
//         {
//             cout << num << " ";
//         }
//         cout << endl;
//         return;
//     }

//     for (int i = 0; i < n; i++)
//     {
//         if (used[i])
//         {
//             cout << "Skipping used element: " << nums[i] << endl;
//             continue;
//         }

//         path.push_back(nums[i]);
//         cout << "Adding " << nums[i] << " to path, current path: ";
//         for (auto num : path) // means for each element num in path print num and space " " after num is printed
//         {
//             cout << num << " ";
//         }
//         cout << endl;

//         used[i] = true; // means marking the element as used
//         cout << "Marking " << nums[i] << " as used" << endl;

//         cout << "Calling generatePermutation recursively  " << n << " " << nums[i] << " " << res.size() << " " << path.size() << " " << used[i] << endl;

//         generatePermutation(n, nums, res, path, used); // recursive call to generatePermutation

//         path.pop_back();
//         cout << "Backtracking, removing " << nums[i] << " from path" << endl;

//         used[i] = false;
//         cout << "Marking " << nums[i] << " as unused" << endl;
//     }

//     cout << "Exiting generatePermutation with path size: " << path.size() << endl;
// }

// string getPermutation(int n, int k)
// {
//     vector<int> nums(n);
//     vector<vector<int>> res;
//     vector<int> path;
//     vector<bool> used(n, false);

//     for (int i = 0; i < n; i++)
//     {
//         nums[i] = i + 1;
//         cout << "Initializing nums[" << i << "] = " << nums[i] << endl;
//     }

//     generatePermutation(n, nums, res, path, used);

//     string ans = "";
//     for (int i = 0; i < n; i++)
//     {
//         ans += to_string(res[k - 1][i]);
//     }

//     return ans;
// }

// int main()
// {
//     int n = 3, k = 3;
//     cout << "Calling getPermutation with n = " << n << " and k = " << k << endl;
//     cout << "Result: " << getPermutation(n, k) << endl;
//     return 0;
// }

// time complexity: O(n!)
// space complexity: O(n)

// Optimal Approach (Using Factorial Number System)

// #include <iostream>
// #include <vector>
// #include <string>
// using namespace std;

// int factorial(int n)
// {
//     int fact = 1;
//     for (int i = 1; i <= n; i++)
//     {
//         fact *= i;
//     }
//     return fact;
// }

// string getPermutation(int n, int k)
// {
//     vector<int> nums(n);         // nums is a vector of size n
//     vector<int> fact(n + 1, 1);  // fact is a vector of size n+1 with all elements initialized to 1 using vector constructor
//     vector<bool> used(n, false); // used is a vector of size n with all elements initialized to false using vector constructor

//     // for loop to initialize nums vector with values from 1 to n and print the values of nums vector
//     for (int i = 0; i < n; i++)
//     {
//         nums[i] = i + 1;
//         cout << "nums[" << i << "] = " << nums[i] << endl;
//     }

//     // for loop to calculate factorial of i and print the values of fact vector
//     for (int i = 1; i <= n; i++)
//     {
//         fact[i] = fact[i - 1] * i;
//         cout << "fact[" << i << "] = " << fact[i] << endl;
//     }

//     // // initializing ans as an empty string and k as k-1
//     string ans = "";
//     k--;

//     cout << "Initial k = " << k << endl;
//     // for loop to calculate the index and new k value and print the values of index and new k
//     for (int i = 1; i <= n; i++)
//     {
//         int index = k / fact[n - i]; // index is k divided by fact[n-i]

//         k = k % fact[n - i];

//         cout << "Step " << i << ": index = " << index << ", new k = " << k << endl;

//         for (int j = 0; j < n; j++)
//         {
//             if (!used[j])
//             {
//                 if (index == 0)
//                 {
//                     ans += to_string(nums[j]);
//                     used[j] = true;
//                     cout << "Chose num[" << j << "] = " << nums[j] << ", ans = " << ans << endl;
//                     break;
//                 }
//                 index--;
//             }
//         }
//     }

//     return ans;
// }

// int main()
// {
//     int n = 3, k = 3;
//     cout << "Permutation: " << getPermutation(n, k) << endl;
//     return 0;
// }

// time complexity: O(n^2) // time complexity is O(n^2) because we are using two nested for loops
// space complexity: O(n) // space complexity is O(n) because we are using three vectors of size n

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string getPermutation(int n, int k)
    {
        int fact = 1;
        vector<int> numbers;
        for (int i = 1; i < n; i++)
        {
            fact = fact * i;
            numbers.push_back(i);
            cout << "fact = " << fact << ", numbers = ";
            for (int num : numbers)
                cout << num << " ";
            cout << endl;
        }
        numbers.push_back(n);
        cout << "Final numbers vector: ";
        for (int num : numbers)
            cout << num << " ";
        cout << endl;
        string ans = "";
        k = k - 1;
        cout << "Initial k (0-based): " << k << endl;

        while (true)
        {
            cout << "Current fact: " << fact << ", k: " << k << endl;
            cout << "Choosing index: " << k / fact << ", value: " << numbers[k / fact] << endl;

            ans = ans + to_string(numbers[k / fact]);
            numbers.erase(numbers.begin() + k / fact);

            cout << "Updated numbers vector: ";
            for (int num : numbers)
                cout << num << " ";
            cout << endl;

            if (numbers.size() == 0)
            {
                break;
            }

            k = k % fact;
            fact = fact / numbers.size();
            cout << "Updated k: " << k << ", updated fact: " << fact << endl;
        }
        return ans; // Return the final permutation string
    }
};

int main()
{
    int n = 3, k = 3;
    Solution obj;
    string ans = obj.getPermutation(n, k);
    cout << "The Kth permutation sequence is " << ans << endl;

    return 0;
}
