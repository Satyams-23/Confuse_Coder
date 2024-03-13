// #include <iostream>
// #include <vector>
// using namespace std;

// int subarraySum(vector<int> &nums, int k)
// {
//     int count = 0;
//     for (int i = 0; i < nums.size(); i++)
//     {
//         int sum = 0;
//         for (int j = i; j < nums.size(); j++)
//         {
//             sum += nums[j];

//             if (sum == k)
//             {
//                 count++;
//             }
//             // subarray also
//         }
//     }
//     return count;
// };

// int main()
// {
//     vector<int> nums = {1, 2, 1, 2, 1};
//     int k = 3;
//     int count = subarraySum(nums, k);
//     cout << " count : " << count << endl;
//     return 0;
// }

// optimal approach

// #include <iostream>
// #include <vector>
// #include <unordered_map>
// using namespace std;

// int subarraySum(vector<int> &nums, int k)
// {
//     int count = 0;
//     int sum = 0;
//     unordered_map<int, int> map;
//     map[0] = 1;
//     for (int i = 0; i < nums.size(); i++)
//     {
//         sum += nums[i];
//         if (map.find(sum - k) != map.end())// if sum-k is present in map then add its value to count
//         {
//             count += map[sum - k];// if sum-k is present in map then add its value to count
//         }
//         map[sum]++;
//     }
//     return count;
// };

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int subarraySum(vector<int> &nums, int k)
{
    int cnt = 0;
    unordered_map<int, int> map;
    map[0] = 1;
    int sum = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
        int remove = sum - k;
        cnt += map[remove];
        map[sum]++;
    }
    return cnt;
}
int main()
{
    vector<int> nums = {3, -3, 1, 1, 1};
    int k = 3;
    int count = subarraySum(nums, k);
    cout << "count : " << count << endl;
    return 0;
}
