#include <iostream>
#include <unordered_set>
#include <vector>

// abs(i - j) <= k
using namespace std;

bool containsDuplicate(vector<int> &nums, int k)
{
    std::unordered_set<int> set;
    for (int i = 0; i < nums.size(); i++)
    {
        if (set.find(nums[i]) != set.end())
        {
            cout << "Duplicate found: " << nums[i] << endl;
            return true;
        }
        set.insert(nums[i]);
        cout << "Set contents: ";
        for (const auto &num : set)
        {
            cout << num << " ";
        }
        if (set.size() > k)
        {
            set.erase(nums[i - k]);
            cout << "\nRemoved: " << nums[i - k] << endl;
            cout << "Set after removal: ";
            for (const auto &num : set)
            {
                cout << num << " ";
            }
            cout << endl;
        }
    }
    return false;
}

int main()
{
    std::vector<int> nums = {1, 2, 3, 4, 1, 4, 5};
    int k = 3;
    if (containsDuplicate(nums, k))
    {
        std::cout << "Contains duplicates within range " << k << std::endl;
    }
    else
    {
        std::cout << "No duplicates within range " << k << std::endl;
    }
    return 0;
}
