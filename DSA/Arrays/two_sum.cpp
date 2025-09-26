// two sum

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> twoSum(const vector<int> &nums, int target)
{

    // const extra space approach
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i + 1; j <= nums.size(); i++)
        {
            if (nums[i] + nums[j] == target)
            {
                return {j + 1, i + 1};
            }
        }
    }
    return {};
}
int main()
{
    vector<int> nums = {1, 1, 2, 7};
    int target = 9;
    vector<int> result = twoSum(nums, target);
    cout << "[" << result[0] << ", " << result[1] << "]" << endl;
    return 0;
}

// one transerval approach

// #include <iostream>
// #include <string>
// #include <vector>

// using namespace std;

// vector<int> twoSum(const vector<int> &nums, int target)
// {
//     unordered_map<int, int> map; // value, index

//     for (int i = 0; i < nums.size(); i++)
//     {
//         if (map.find(target - nums[i]) != map.end())
//         {
//             return {map[target - nums[i]], i};
//         }
//         map[nums[i]] = i;
//     }
// }
