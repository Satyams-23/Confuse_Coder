// Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    int i = m - 1, j = n - 1, k = m + n - 1;

    while (i >= 0 && j >= 0)
    {
        if (nums1[i] > nums2[j])
        {
            nums1[k] = nums1[i];
            i--;
        }
        else
        {
            nums1[k] = nums2[j];
            j--;
        }
        k--;
    }

    while (j >= 0)
    {
        nums1[k] = nums2[j];
        j--;
        k--;
    }
}

int main()
{
    vector<int> nums1 = {1, 2, 3, 4, 5, 10};
    vector<int> nums2 = {7, 8, 9};
    int m = 6, n = 3;
    merge(nums1, m, nums2, n);

    // Print the merged array
    for (int i = 0; i < m + n; i++)
    {
        cout << nums1[i] << " ";
    }
    return 0;
}

// i = m - 1 j = n - 1 k = m + n - 1

// #nums = [2,7,11,15], target = 22

// Add sum of two numbers in an array
// #nums = [2,7,11,15], target = 9
// code here
// optimal solution
// #nums = [2,7,11,15], target = 9
// code here

include<iostream>
#include <vector>
    using namespace std;

vector<int> twoSum(vector<int> &nums, int target)
{
    vector<int> result;
    int i = 0, j = nums.size() - 1;
    while (i < j)
    {
        if (nums[i] + nums[j] == target)
        {
            result.push_back(i + 1);
            result.push_back(j + 1);
            return result;
        }
        else if (nums[i] + nums[j] < target)
        {
            i++;
        }
        else
        {
            j--;
        }
    }
    return result;
}
