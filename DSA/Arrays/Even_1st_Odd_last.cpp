// Given an integer array nums, move all the even integers at the beginning of the array followed by all the odd integers.

#include <iostream>
#include <vector>
using namespace std;

vector<int> evenOdd(vector<int> &nums)
{
    int n = nums.size();
    int i = 0, j = n - 1;
    while (i < j)
    {
        if (nums[i] % 2 == 0)
        {
            i++;
        }
        else
        {
            swap(nums[i], nums[j]);
            j--;
        }
    }
    return nums;
}

int main()
{
    vector<int> nums = {1, 1, 3, 4, 5, 6, 7, 8};
    vector<int> result = evenOdd(nums);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    return 0;
}

// class Solution
// {
// public:
//     vector<int> sortArrayByParity(vector<int> &arr)
//     {
//         int left = 0, right = arr.size() - 1;
//         int n = arr.size();
//         while (left < right)
//         {
//             while (left < right && arr[left] % 2 == 0)
//                 left++;
//             while (right > left && arr[right] % 2 != 0)
//                 right--;
//             if (left < right)
//                 swap(arr[left], arr[right]);
//         }
//         return arr;
//     }
// };
