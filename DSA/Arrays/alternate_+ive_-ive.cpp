
// Alternate positive and negative numbers
// Given an array of integers, rearrange the array such that positive and negative numbers are placed alternatively. The order of the numbers should be maintained.

// Example
// Input: [-1, 2, -3, 4, 5, 6, -7, 8, 9]

// Output: [2, -1, 4, -3, 5, -7, 6, 8, 9]

// Explanation: The positive and negative numbers are placed alternatively in the array


// Brute force approach

// #include<iostream>
// #include<vector>

// using namespace std;

// void alternatePositiveNegative(vector<int> &nums){
//     int n = nums.size();
//     vector<int> result(n);
//     int positiveIndex = 0; 
//     int negativeIndex = 1; 

//     for(int i = 0; i < n; i++){
//         if(nums[i] >= 0){
//             result[positiveIndex] = nums[i];// [2, 0, 4, 0, 5, 0, 6, 0, 9]
//             positiveIndex += 2;
//         }else{
//             result[negativeIndex] = nums[i];// [2, -1, 4, -3, 5, -7, 6, 8, 9]
//             negativeIndex += 2;
//         }
//     }

//     for(int i = 0; i < n; i++){
//         nums[i] = result[i];
//     }
// }


// int main(){
//     vector<int> nums = {-1, 2, -3, 4, 5, 6, -7, 8, 9};
//     alternatePositiveNegative(nums);
//     for(int i = 0; i < nums.size(); i++){
//         cout<<nums[i]<<" ";
//     }
//     return 0;
// }

// time complexity: O(n)
// space complexity: O(n)

// Optimized approach


#include <iostream>
#include <vector>


using namespace std;

vector<int> RearrangebySign(vector<int> A, int n) {
    int i = 0, j = 1; // Pointers to track next positions for positive and negative numbers
    while (i < n && j < n) {
        // Find next position to place positive number
        while (i < n && A[i] >= 0) i += 2;
        // Find next position to place negative number
        while (j < n && A[j] < 0) j += 2;
        // Swap positive and negative numbers
        if (i < n && j < n) swap(A[i], A[j]);
    }
    // Handle remaining positive numbers
    while (i < n && A[i] >= 0) i += 2;
    // Handle remaining negative numbers
    while (j < n && A[j] < 0) j += 2;
    // Place remaining positive numbers
    while (i < n) swap(A[i], A[i += 2]);
    // Place remaining negative numbers
    while (j < n) swap(A[j], A[j += 2]);
    return A;
}

int main() {
    int n = 6;
    vector<int> A {1, 2, -4, -5, 3, 4};
    vector<int> ans = RearrangebySign(A, n);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    return 0;
}

// time complexity: O(n)
// space complexity: O(1)