// sort the unordered array without use sort function

#include <iostream>
#include <vector>
#include <algorithm>

void sort(std::vector<int> &nums)
{
    for (size_t i = 0; i < nums.size(); i++)
    {
        for (size_t j = i + 1; j < nums.size(); j++)
        {
            if (nums[i] > nums[j])
            {
                std::swap(nums[i], nums[j]); // swap the elements if the first element is greater than the second element std::swap(nums[i], nums[j]);
            }
        }
    }
}

int main()
{
    std::vector<int> nums = {1, 3, 1, 4, 2, 2};

    sort(nums);

    for (size_t i = 0; i < nums.size(); i++)
    {
        std::cout << nums[i] << " ";
    }

    return 0;
}