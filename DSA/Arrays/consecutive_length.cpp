// longest consecutive subsequence

//what is consecutive subsequence?
// A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.

// Given an array of integers, find the length of the longest sub-sequence such that elements in the subsequence are consecutive integers, the consecutive numbers can be in any order.

// Example
// Input: [1, 9, 3, 10, 4, 20, 2]   1,2,3,4,9,10,20

// Output: 4

// Explanation: The longest consecutive subsequence is [1, 3, 4, 2] which has length 4


// Brute force approach

// #include<iostream>
// #include<algorithm>
// #include<vector>

// using namespace std;

// int longestConsecutiveSubsequence(vector<int> &nums){
//     int n = nums.size();
    
//     int longestStreak = 0;

//     for(int num : nums){//

//         int currentNum = num;
//         int currentStreak = 1;
//         while(find(nums.begin(), nums.end(), currentNum + 1) != nums.end()){

//              // means the current number is present in the array and we can increment the current number and the current streak by 1
//             currentNum += 1;
//             currentStreak += 1;// 
//         }
//         longestStreak = max(longestStreak, currentStreak);// means the current streak is greater than the longest streak so update the longest streak with the current streak value 
//     }
//     return longestStreak;
// }

// int main(){
//     vector<int> nums = {1, 9, 3, 10, 4, 20, 2};
//     cout<<longestConsecutiveSubsequence(nums)<<endl;
//     return 0;
// }

// time complexity: O(n^2)
// space complexity: O(1)

// Optimized approach

// #include<iostream>
// #include<algorithm>
// #include<vector>

// using namespace std;

// int longestConsecutiveSubsequence(vector<int> &nums){
//     int n = nums.size();
//     if(n == 0) return 0;
//     sort(nums.begin(), nums.end());
//     int longestStreak = 1;
//     int currentStreak = 1;
//     for(int i = 1; i < n; i++){
//         if(nums[i] != nums[i-1]){
//             if(nums[i] == nums[i-1] + 1){
//                 currentStreak += 1;
//             }else
//             {// means the current number is not consecutive to the previous number 
//                 longestStreak = max(longestStreak, currentStreak);
//                 currentStreak = 1;
//             }
//         }
//     }
//     return max(longestStreak, currentStreak);
// }

// int main(){
//     vector<int> nums = {1, 9, 3, 10, 4, 20, 2};
//     cout<<longestConsecutiveSubsequence(nums)<<endl;
//     return 0;
// }

// time complexity: O(nlogn) + n 

// space complexity: O(1)











// Optimized approach using hashset

#include<iostream>
#include<algorithm>
#include<vector>
#include <unordered_set>

using namespace std;

int longestConsecutiveSubsequence(vector<int> &nums){
    int n = nums.size();
    if(n == 0) return 0;

    unordered_set<int> numSet;
    for(int num : nums){
        numSet.insert(num);
    }

    int longestStreak = 0;
    for(int num : numSet){
        if(numSet.find(num - 1) == numSet.end()){// 
            int currentNum = num;
            int currentStreak = 1;
            while(numSet.find(currentNum + 1) != numSet.end()){
                currentNum += 1;
                currentStreak += 1;
            }
            longestStreak = max(longestStreak, currentStreak);
        }
    }
    return longestStreak;
}


int main(){
    vector<int> nums = {1, 9, 3, 10, 4, 20, 2};
    cout<<longestConsecutiveSubsequence(nums)<<endl;
    return 0;
}

// time complexity: O(n) + O(n) = O(n)

// space complexity: O(n) + O(1) = O(n)










