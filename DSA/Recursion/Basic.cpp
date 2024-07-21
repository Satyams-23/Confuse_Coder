// factorial of a number using recursion

// #include <iostream>
// using namespace std;

// int factorial(int n)
// {
//     if (n == 0)
//     {
//         return 1;
//     }

//     return n * factorial(n - 1);
// }

// int main()
// {
//     int n = 5;
//     cout << factorial(n) << endl;
//     return 0;
// }

// fibonacci series using recursion

// #include <iostream>
// using namespace std;

// int fibonacci(int n)
// {
//     if (n == 0 || n == 1)
//     {
//         return n;
//     }

//     return fibonacci(n - 1) + fibonacci(n - 2);
// }

// int main()
// {
//     int n = 5;
//     cout << fibonacci(n) << endl;
//     return 0;
// }

// sum of digits of a number using recursion

// #include <iostream>
// using namespace std;

// int sumOfDigits(int n)
// {
//     if (n == 0)
//     {
//         return 0;
//     }

//     return n % 10 + sumOfDigits(n / 10);
// }

// int main()
// {
//     int n = 12345;
//     cout << sumOfDigits(n) << endl;
//     return 0;
// }

// sum of natural numbers using recursion

// #include <iostream>
// using namespace std;

// int sumOfNaturalNumbers(int n)
// {
//     if (n == 0)
//     {
//         return 0;
//     }

//     return n + sumOfNaturalNumbers(n - 1);
// }

// int main()
// {
//     int n = 5;
//     cout << sumOfNaturalNumbers(n) << endl;
//     return 0;
// }

// how many ways to reverse a string using recursion

// #include <iostream>
// #include <string>
// using namespace std;

// void substr(string s, string ans)
// {
//     if (s.size() == 0)
//     {
//         cout << ans << endl;
//         return;
//     }

//     char ch = s[0];
//     string ros = s.substr(1);
//     substr(ros, ans);
//     substr(ros, ans + ch);
//     cout << ans << endl;
// }

// void reverse(string s)
// {
//     if (s.size() == 0)
//     {
//         return;
//     }

//     reverse(s.substr(1));           //  s.substr(1) means from 1 to end of the string s
//     cout << s.substr(0, 1) << endl; // s.substr(0, 1) means from 0 to 1 of the string s
//     cout << s[0];                   // s[0] means first character of the string s
// }

// int main()
// {
//     string s = "hello";
//     reverse(s);
//     cout << endl;
//     return 0;
// }

// how to binary search using recursion in an array of integers using recursion in c++

// #include <iostream>
// #include <vector>
// using namespace std;

// int binarySearch(vector<int> &arr, int target, int start, int end)
// {
//     if (start > end)
//     {
//         return -1;
//     }

//     int mid = start + (end - start) / 2; // to avoid overflow error in case of large numbers we use this formula to calculate mid point of the array or vector
//     if (arr[mid] == target)
//     {
//         return mid;
//     }
//     else if (arr[mid] > target)
//     {
//         return binarySearch(arr, target, start, mid - 1);
//     }
//     else
//     {
//         return binarySearch(arr, target, mid + 1, end);
//     }
//     // cout << mid << endl;
// }

// int main()
// {
//     vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};
//     int target = 5;
//     cout << binarySearch(arr, target, 0, arr.size() - 1) << endl;
//     return 0;
// }

// how to find in not sorted array using recursion in c++

// #include <iostream>
// #include <vector>
// using namespace std;

// int find(vector<int> &arr, int target, int start)
// {
//     if (start == arr.size())
//     {
//         return -1;
//     }

//     if (arr[start] == target)
//     {
//         return start;
//     }

//     return find(arr, target, start + 1);
// }

// int main()
// {
//     vector<int> arr = {1, 2, 5, 1, 1, 2, 6, 7, 8, 9};
//     int target = 5;
//     cout << find(arr, target, 0) << endl;
//     return 0;
// }

// #include <iostream>
// #include <vector>
// using namespace std;

// void backtrack(int start, vector<int> &nums, vector<int> &current, vector<vector<int>> &result)
// {
//     // Add the current subset to the result
//     result.push_back(current);
//     cout << "Added subset: [ ";
//     for (int num : current)
//         cout << num << " ";
//     cout << "]" << endl;

//     // Iterate through the remaining elements to explore subsets
//     for (int i = start; i < nums.size(); i++)
//     {
//         cout << "Include element " << nums[i] << " and recurse" << endl;
//         // Include the element
//         current.push_back(nums[i]);

//         // Recurse
//         backtrack(i + 1, nums, current, result);

//         // Exclude the element (backtrack)
//         cout << "Exclude element " << nums[i] << " and backtrack" << endl;
//         current.pop_back();
//     }
// }

// vector<vector<int>> subsets(vector<int> &nums)
// {
//     vector<vector<int>> result;
//     vector<int> current;
//     backtrack(0, nums, current, result);
//     return result;
// }

// int main()
// {
//     vector<int> nums = {1, 2, 3};
//     vector<vector<int>> result = subsets(nums);

//     cout << "All subsets: " << endl;
//     for (const auto &subset : result)
//     {
//         cout << "[ ";
//         for (int num : subset)
//             cout << num << " ";
//         cout << "]" << endl;
//     }

//     return 0;
// }

#include <vector>
#include <iostream>

void backtrack(std::vector<int> &candidates, int target, std::vector<std::vector<int>> &result, std::vector<int> &combination, int start)
{
    if (target == 0)
    {
        result.push_back(combination);
        return;
    }
    for (int i = start; i < candidates.size(); i++)
    {
        if (candidates[i] <= target)
        {
            combination.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i], result, combination, i);
            combination.pop_back(); // backtrack
        }
    }
}

std::vector<std::vector<int>> combinationSum(std::vector<int> &candidates, int target)
{
    std::vector<std::vector<int>> result;
    std::vector<int> combination;
    backtrack(candidates, target, result, combination, 0);
    return result;
}

int main()
{
    std::vector<int> candidates = {2, 3, 6, 7};
    int target = 7;
    std::vector<std::vector<int>> result = combinationSum(candidates, target);

    std::cout << "Combinations that sum to " << target << ":" << std::endl;
    for (const auto &combination : result)
    {
        std::cout << "[";
        for (int num : combination)
        {
            std::cout << num << " ";
        }
        std::cout << "]" << std::endl;
    }

    return 0;
}
