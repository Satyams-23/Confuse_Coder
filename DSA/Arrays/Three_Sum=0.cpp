#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> threeSum(vector<int> &nums)
{
    vector<vector<int>> res;

    sort(nums.begin(), nums.end());

    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
        if (i > 0 && nums[i] == nums[i - 1])
        {
            continue;
        }

        int l = i + 1;
        int r = n - 1;
        while (l < r)
        {
            int sum = nums[i] + nums[l] + nums[r];
            if (sum < 0)
            {
                l++;
            }
            else if (sum > 0)
            {
                r--;
            }
            else
            {
                res.push_back({nums[i], nums[l], nums[r]});

                // Commented out duplicate skipping code
                // while (l < r && nums[l] == nums[l + 1])
                // {
                //     l++;
                // }
                // while (l < r && nums[r] == nums[r - 1])
                // {
                //     r--;
                // }

                l++;
                r--;
            }
        }
    }
    return res;
}

int main()
{
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> res = threeSum(nums);
    for (auto i : res)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}
