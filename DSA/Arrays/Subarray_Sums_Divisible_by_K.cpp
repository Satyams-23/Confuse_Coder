// What is Subaarray?
// A subarray is a contiguous part of an array. An array that is inside another array. For example, consider the array [1, 2, 3, 4], There are 10 non-empty sub-arrays. The subarrays are [1], [2], [3], [4], [1, 2], [2, 3], [3, 4], [1, 2, 3], [2, 3, 4] and [1, 2, 3, 4]. In general, an array of n elements will have n(n+1)/2 subarrays.

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
