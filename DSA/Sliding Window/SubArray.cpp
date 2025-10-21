#include <iostream>
#include <vector>

using namespace std;

int minSubArray(vector<int> &nums, int target)
{
    int n = nums.size();
    int left = 0, right = 0;
    int sum = 0;
    int minLength = n + 1;

    while (right < n)
    {
        sum += nums[right];
        right++;

        while (sum >= target)
        {
            minLength = min(minLength, right - left);
            sum -= nums[left];
            left++;
        }
    }

    return (minLength == n + 1) ? 0 : minLength;
}
