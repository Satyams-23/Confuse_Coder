// #include <iostream>
// #include <vector>
// #include <unordered_map>
// using namespace std;

// int maxSubArray(vector<int> &nums)
// {

//     int Max = INT_MIN;

//     for (int i = 0; i < nums.size(); i++)
//     {
//         for (int j = i; j < nums.size(); j++)
//         {

//             int sum = 0;

//             for (int k = i; k <= j; k++)
//             {
//                 sum += nums[k];
//             }
//             Max = max(Max, sum);
//         }
//     }
//     return Max;
// }

// int main()
// {

//     vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
//     int maxsum = maxSubArray(nums);
//     cout << "Max number : " << maxsum << endl;
//     return 0;
// }

// Better Approach

// #include <iostream>
// #include <vector>
// #include <unordered_map>
// using namespace std;

// int maxSubArray(vector<int> &nums)
// {

//     int Max = INT_MIN;

//     for (int i = 0; i < nums.size(); i++)
//     {
//         int sum = 0;
//         for (int j = i; j < nums.size(); j++)
//         {

//             sum += nums[j];

//             Max = max(Max, sum);
//         }
//     }
//     return Max;
// }

// int main()
// {

//     vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
//     int maxsum = maxSubArray(nums);
//     cout << "Max number : " << maxsum << endl;
//     return 0;
// }

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int sum = nums[0];
        int maxSum = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            sum = max(nums[i], sum + nums[i]);
            maxSum = max(maxSum, sum);
        }
        return maxSum;
    }
};

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int n = nums.size();
        long long maxi = LONG_MIN;
        long long sum = 0;

        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
            if (sum > maxi)
            {
                maxi = sum;
            }
            if (sum < 0)
            {
                sum = 0;
            }
        }
        return maxi;
    }
};

// print the maximum subarray sum with subarray also

#include <bits/stdc++.h>
using namespace std;

long long maxSubarraySum(int arr[], int n)
{
    long long maxi = LONG_MIN; // maximum sum
    long long sum = 0;

    int start = 0;
    int ansStart = -1, ansEnd = -1;
    for (int i = 0; i < n; i++)
    {

        if (sum == 0)
            start = i; // starting index

        sum += arr[i];

        if (sum > maxi)
        {
            maxi = sum;

            ansStart = start; // starting index of the subarray with maximum sum
            ansEnd = i;       //
        }

        // If sum < 0: discard the sum calculated
        if (sum < 0)
        {
            sum = 0;
        }
    }

    // printing the subarray:
    cout << "The subarray is: [";
    for (int i = ansStart; i <= ansEnd; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "]n";

    // To consider the sum of the empty subarray
    // uncomment the following check:

    // if (maxi < 0) maxi = 0;

    return maxi;
}

int main()
{
    int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    long long maxSum = maxSubarraySum(arr, n);
    cout << "The maximum subarray sum is: " << maxSum << endl;
    return 0;
}
