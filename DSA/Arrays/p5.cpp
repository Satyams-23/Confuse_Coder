// Finding the duplicate number in an array using Floyd's tortoise and hare Algorithm

// nums = [ 1, 2, 3, 4, 5, 6, 3, 7 ] array linked list cycle

// Floyd's tortoise and hare Algorithm
// Step 1: Find the intersection point of the two runners
// Step 2: Find the entrance to the cycle
// Step 3: Find the duplicate number

#include <iostream>
#include <vector>
#include <algorithm>
int funtion1(std::vector<int> &nums)
{
    std::sort(nums.begin(), nums.end());

    for (size_t i = 0; i < nums.size(); i++)
    {
        if (nums[i] == nums[i + 1])
        {
            return nums[i];
        }
    }

    return 1;
}

// flloyd's tortoise and hare algorithm to find the duplicate number

int function(std::vector<int> &nums)
{
    size_t tortoise = nums[0];
    size_t hare = nums[0];
    // step 1: find the intersection point of the two runners
    do
    {
        tortoise = nums[tortoise]; // move one step
        hare = nums[nums[hare]];   // move two steps
    } while (tortoise != hare);

    // step 2: find the "entrance" to the cycle
    tortoise = nums[0];
    while (tortoise != hare)
    {
        tortoise = nums[tortoise];
        hare = nums[hare];
    }

    return hare, tortoise;
}

int main()
{
    std::vector<int> nums = {1, 3, 1, 4, 2, 2};

    int resultSort = funtion1(nums);
    std::cout << "Duplicate (Sorting): " << resultSort << std::endl;

    int resultFloyd = function(nums);
    std::cout << "Duplicate (Floyd's Algorithm): " << resultFloyd << std::endl;

    return 0;
}

// sort the array

// 1 1 2 2 3 4

#include <iostream>
#include <vector>
#include <algorithm>
