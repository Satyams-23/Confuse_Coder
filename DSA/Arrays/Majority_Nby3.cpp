// Problem Statement Given an array of N integers. Find the elements that appear more than N/3 times in the array. If no such element exists, return an empty vector.

// example
// Input: [3, 2, 3]
// Output: [3]

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<vector<int>> majorityElement(vector<int> &nums)
{
    vector<vector<int>> res;
    unordered_map<int, int> map;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        map[nums[i]]++; // means if the element is already present in the map then increment its value by 1
    }
    for (int i = 0; i < map.size(); i++)
    {
        if (map[i] > n / 3)
        {
            res.push_back({i});
        }
    }
    return res;
}

int main()
{
    vector<int> nums = {1, 1, 1, 3, 3, 2, 2, 2};
    vector<vector<int>> res = majorityElement(nums);
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++) //
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}