//  Add Sum of two numbers in an array
//  #nums = [2,7,11,15], target = 9
//  code here
//  optimal solution
//  #nums = [2,7,11,15], target = 9

#include <iostream>
#include <vector>
using namespace std;

vector<int> addSum(vector<int> &nums, int target)
{
    vector<int> result;
    int i = 0, j = nums.size() - 1; //
    while (i < j)                   //
    {
        if (nums[i] + nums[j] == target) //
        {
            result.push_back(i);
            result.push_back(j);
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

int main()
{
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> result = addSum(nums, target);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    return 0;
}

//  Approach 2: Using Hash Map

// #include <iostream>
// #include <vector>
// #include <unordered_map>
// using namespace std;

// vector<int> addSum(vector<int> &nums, int target)
// {
//     vector<int> result;
//     unordered_map<int, int> map;
//     for (int i = 0; i < nums.size(); i++)
//     {
//         if (map.find(target - nums[i]) != map.end())
//         {
//             result.push_back(map[target - nums[i]]);// means the index of the number which is already present in the map
//             result.push_back(i);//
//             return result;
//         }
//         map[nums[i]] = i;
//     }
//     return result;
// }

// int main()
// {

//     vector<int> nums = {2, 7, 11, 15};
//     int target = 9;
//     vector<int> result = addSum(nums, target);
//     for (int i = 0; i < result.size(); i++)
//     {
//         cout << result[i] << " ";
//     }
//     return 0;
// }
