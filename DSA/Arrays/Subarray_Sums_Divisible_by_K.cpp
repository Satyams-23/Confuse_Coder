// What is Subaarray?
// A subarray is a contiguous part of an array. An array that is inside another array. For example, consider the array [1,2,3], There are 6 non-empty subarrays. The subarrays are [1], [2], [3], [1,2], [2,3], [1,2,3].

// What is contiguous subarray?
// ////////////////////////////////
// contiguos means all the elements of the subarray are adjacent to each other. for example [4,5,0] is a subarray but [4,0,1] is not a subarray of [4,5,0,-2,-3,1].
// n()

// What is the problem?
// Given an array A of integers, return the number of (contiguous, non-empty) subarrays that have a sum divisible by K.
// Example 1:
// Input: A = [4,5,0,-2,-3,1], K = 5
// Output: 7
// Explanation: There are 7 subarrays with a sum divisible by K = 5:
// [4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], [-2, -3]
// Note:
// 1 <= A.length <= 30000
// -10000 <= A[i] <= 10000
// 2 <= K <= 10000
// What is the solution?

// Approach 1: Brute Force
// The simplest method is to consider every possible subarray of the given array, find the sum of the elements of each of those subarrays, and check if the sum is divisible by K. If it is, we increment the count of such subarrays. We then return the final count of subarrays that have a sum divisible by K.

// Complexity Analysis
// Time complexity: O(n^2)
// Space complexity: O(1)

// code for approach 1
// #include <iostream>
// #include <vector>
// using namespace std;

// vector<int> subarraySum(vector<int> &nums, int k)
// {
//     int n = nums.size();
//     int count = 0;
//     for (int i = 0; i < n; i++)
//     {
//         int sum = 0; // sum of elements of subarray nums[i, j] where i is fixed and j varies from i to n-1
//         for (int j = i; j < n; j++)
//         {
//             sum += nums[j];

//             if (sum % k == 0)

//                 count++;
//         }
//     }
//     cout << count << endl;
//     return nums;
// }

// int main()
// {
//     vector<int> nums = {4, 5, 0, -2, -3, 1};
//     int k = 5;
//     subarraySum(nums, k);
//     return 0;
// }

// Approach 2: Using HashMap
// Intuition  ////////////////////////////
//  means the ability to understand or know something without needing to think about it or use reason to discover it, or a feeling of understanding the truth without evidence.
// what is the prefix sum? ////////////////////////////
// The prefix sum of a subarray A[i, j] is the sum of all the elements up to the jth element in the array, including the jth element. It is denoted as P[j]. The prefix sum of the subarray A[i, j] can be expressed as P[j] - P[i - 1], where P[i - 1] is the prefix sum of the subarray A[0, i - 1]. for example, if the given array is [1,2,3,4,5] then the prefix sum of the array is [1,3,6,10,15]. like prefix sum of 3rd element is 6 because 1+2+3=6.

// If the cumulative sum(represented by sum[i] for sum upto i^{th} index) upto two indices is the same, the sum of the elements lying in between those indices is zero. Extending the same thought further, if the cumulative sum upto two indices, say i and j is at a difference of k i.e. if sum[i] - sum[j] = k, the sum of elements lying between indices i and j is k.
// If the prefix sum P[j] - P[i] is divisible by K, then the subarray A[i]...A[j] is divisible by K. Also, as the subarray is contiguous, P[j] - P[i] is the sum of the subarray A[i]...A[j]. If we know the remainder of the prefix sum P[i] when divided by K, say it's R, and we also know the remainder of the prefix sum P[j] when divided by K, say it's R, then we can figure out the remainder of this subarray when divided by K. It's simple: R = (P[j] - P[i]) % K.
// Thus, based on the above observation, we can keep track of the remainders of the prefix sum of the elements of the array A when divided by K in a HashMap map.

// why we use p[j]
// The prefix sum of a subarray A[i, j] is the sum of all the elements up to the jth element in the array, including the jth element. It is denoted as P[j]. The prefix sum of the subarray A[i, j] can be expressed as P[j] - P[i - 1], where P[i - 1] is the prefix sum of the subarray A[0, i - 1]. for example, if the given array is [1,2,3,4,5] then the prefix sum of the array is [1,3,6,10,15]. like prefix sum of 3rd element is 6 because 1+2+3=6. p[j] is the prefix sum of the array upto jth element.

// Complexity Analysis
// Time complexity: O(n)
// Space complexity: O(n)

// code for approach 2
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int subarraySum(vector<int> &nums, int k)
{
    unordered_map<int, int> prefixSumCount; // Map to store count of prefix sums modulo k
    int prefixSum = 0;
    int count = 0;

    prefixSumCount[0] = 1; // Initialize with 0 to handle cases where prefix sum itself is divisible by k

    for (int num = 0; num < nums.size(); num++)

    {

        prefixSum = (prefixSum + num) % k;
        if (prefixSum < 0)
        {
            // Handle negative prefix sums by adding k to make them positive
            prefixSum += k;
        }
        count += prefixSumCount[prefixSum];
        prefixSumCount[prefixSum]++;
    }

    cout << "Number of subarrays with sum divisible by " << k << ": " << count << endl;

    return count;
}

int main()
{
    vector<int> nums = {4, 5, 0, -2, -3, 1};
    int k = 5;
    subarraySum(nums, k);
    return 0;
}
