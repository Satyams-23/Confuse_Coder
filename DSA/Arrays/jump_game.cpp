// Jump game probLem

// Given an array of non-negative integers, you are initially positioned at the first index of the array. Each element in the array represents your maximum jump length at that position. Determine if you are able to reach the last index.

// Example 1:

// Input: nums = [2,3,1,1,4]
// Output: true

// code

// #include <bits/stdc++.h>
// using namespace std;

// bool canJump(vector<int> &nums)
// {
//     int n = nums.size();
//     int maxReach = 0;
//     for (int i = 0; i < n; i++)
//     {
//         if (i > maxReach)
//             return false;
//         maxReach = max(maxReach, i + nums[i]);
//     }
//     return true;
// }

// int main()
// {
//     vector<int> nums = {2, 3, 1, 1, 4};
//     cout << canJump(nums) << endl;
//     return 0;
// }

// Time complexity: O(n)
// Space complexity: O(1)

// another approach

#include <bits/stdc++.h>
using namespace std;

bool canJump(vector<int> &nums)
{
    int n = nums.size() - 1;

    for (int i = nums.size() - 2; i >= 0; i--) //
    {
        if (i + nums[i] >= n)
            n = i;
        cout << nums[i] << endl;
    }
    return n == 0;
}

int main()
{
    vector<int> nums = {1, 1, 3, 4, 5, 6, 7, 8};
    cout << canJump(nums) << endl;
    return 0;
}
