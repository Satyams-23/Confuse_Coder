
// // Find The Multiple Duplicate Number in the array

// #include <iostream>
// #include <vector>
// #include <algorithm>

// using namespace std;

// vector<int> findDuplicates(vector<int> &nums)
// {
//     vector<int> result;

//     for (size_t i = 0; i < nums.size(); i++)
//     {
//         int index = nums[i] % nums.size();
//         nums[index] += nums.size();
//     }

//     for (size_t i = 0; i < nums.size(); i++)
//     {
//         if (nums[i] > 2 * nums.size()) //
//         {
//             result.push_back(i);
//         }
//     }

//     return result;
// }

// int main()
// {

//     vector<int> nums = {4, 3, 2, 77, 8, 2, 3, 77};
//     vector<int> result = findDuplicates(nums);

//     for (size_t i = 0; i < result.size(); i++)
//     {
//         cout << result[i] << " ";
//     }

//     return 0;
// }

// // time complexity: O(n)
// // space complexity: O(n)

#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

vector<int> findDuplicates(const vector<int> &nums)
{
    unordered_set<int> numSet; // Create a set to store the numbers in the array and check for duplicates
    vector<int> duplicates;

    for (int num : nums)
    {
        if (numSet.count(num) > 0) // if the number is already in the set then add it to the duplicates vector
        {
            // Duplicate found
            duplicates.push_back(num);
        }
        else
        {
            // Add the number to the set
            numSet.insert(num);
        }
    }

    return duplicates;
}

int main()
{
    // Example usage:
    vector<int> inputArray = {1, 2, 3, 20, 44, 20, 44};
    vector<int> result = findDuplicates(inputArray);

    // Output the duplicate numbers
    cout << "Duplicate numbers: ";
    for (int num : result)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

// // time complexity: O(n)
// // space complexity: O(n)

class Solution
{
public:
    vector<int> findDuplicates(vector<int> &nums)
    {
        if (nums.empty())
            return {};
        sort(nums.begin(), nums.end());
        vector<int> ans;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i] != nums[i + 1])
                continue; // if the number is not a duplicate then continue to the next number in the array
            ans.push_back(nums[i]);
            i++;
        }

        return ans;
    }
};