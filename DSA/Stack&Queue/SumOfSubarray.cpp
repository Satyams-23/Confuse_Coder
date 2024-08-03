

// Brute Force Approach

// Question : You are given an integer array nums. The range of a subarray of nums is the difference between the largest and smallest element in the subarray.

// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// long long subArrayRanges(vector<int> &nums)
// {
//     long long ans = 0;
//     int n = nums.size();
//     for (int i = 0; i < n; i++)
//     {
//         int maxEle = INT_MIN;
//         int minEle = INT_MAX;
//         for (int j = i; j < n; j++)
//         {
//             maxEle = max(maxEle, nums[j]);

//             minEle = min(minEle, nums[j]); //
//             cout << maxEle << " " << minEle << endl;
//             ans += maxEle - minEle;
//         }
//     }
//     return ans;
// }

// int main()
// {
//     vector<int> nums = {1, 2, 3, 4};
//     cout << subArrayRanges(nums) << endl;
//     return 0;
// }
// // optimal Approach

// Using monotonic stack

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

long long subArrayRanges(vector<int> &nums)
{
    int n = nums.size();
    vector<int> nextGreater(n, n); //
    vector<int> prevGreater(n, -1);
    vector<int> nextSmaller(n, n);
    vector<int> prevSmaller(n, -1);

    stack<int> s;

    // Finding the next greater elements
    for (int i = 0; i < n; ++i)
    {
        while (!s.empty() && nums[s.top()] < nums[i])
        {
            nextGreater[s.top()] = i;
            cout << "Next greater for index " << s.top() << " is at index " << i << endl;
            s.pop();
        }
        s.push(i);
    }

    // Clearing stack for reuse
    while (!s.empty())
        s.pop();

    // Finding the previous greater elements
    for (int i = n - 1; i >= 0; --i)
    {
        while (!s.empty() && nums[s.top()] <= nums[i])
        {
            prevGreater[s.top()] = i;
            cout << "Previous greater for index " << s.top() << " is at index " << i << endl;
            s.pop();
        }
        s.push(i);
    }

    // Clearing stack for reuse
    while (!s.empty())
        s.pop();

    // Finding the next smaller elements
    for (int i = 0; i < n; ++i)
    {
        while (!s.empty() && nums[s.top()] > nums[i])
        {
            nextSmaller[s.top()] = i;
            cout << "Next smaller for index " << s.top() << " is at index " << i << endl;
            s.pop();
        }
        s.push(i);
    }

    // Clearing stack for reuse
    while (!s.empty())
        s.pop();

    // Finding the previous smaller elements
    for (int i = n - 1; i >= 0; --i)
    {
        while (!s.empty() && nums[s.top()] >= nums[i])
        {
            prevSmaller[s.top()] = i;
            cout << "Previous smaller for index " << s.top() << " is at index " << i << endl;
            s.pop();
        }
        s.push(i);
    }

    long long sumMax = 0;
    long long sumMin = 0;

    // Calculate the sum of ranges using the contribution of each element
    for (int i = 0; i < n; ++i)
    {
        // Contribution as maximum
        sumMax += (long long)nums[i] * (i - prevGreater[i]) * (nextGreater[i] - i);
        cout << "Element " << nums[i] << " contributes " << (nums[i] * (i - prevGreater[i]) * (nextGreater[i] - i)) << " as max" << endl;

        // Contribution as minimum
        sumMin += (long long)nums[i] * (i - prevSmaller[i]) * (nextSmaller[i] - i);
        cout << "Element " << nums[i] << " contributes " << (nums[i] * (i - prevSmaller[i]) * (nextSmaller[i] - i)) << " as min" << endl;
    }

    return sumMax - sumMin;
}

int main()
{
    vector<int> nums = {1, 2, 3};
    cout << "Sum of all subarray ranges: " << subArrayRanges(nums) << endl; // Output: 4

    return 0;
}
