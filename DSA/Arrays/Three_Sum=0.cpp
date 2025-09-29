class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> result;
        int n = nums.size();
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i++)
        {

            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }

            int L = i + 1;
            int R = n - 1;

            while (L < R)
            {

                int sum = nums[i] + nums[L] + nums[R];

                if (sum == 0)
                {

                    result.push_back({nums[i], nums[L], nums[R]});
                    while (L < R && nums[L] == nums[L + 1])
                    {
                        L++;
                    }
                    while (L < R && nums[R] == nums[R - 1])
                    {
                        R--;
                    }
                    L++;
                    R--;
                }
                else if (sum > 0)
                {
                    R--;
                }
                else
                {
                    L++;
                }
            }
        }
        return result;
    }
};