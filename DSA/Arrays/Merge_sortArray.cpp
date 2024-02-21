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