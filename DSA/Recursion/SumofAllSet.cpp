// // Problem Statement: Given an array print all the sum of the subset generated from it, in the increasing order.

// // Bit manipulation approach:
// //  Generate all the subsets using bit manipulation and calculate the sum of each subset and store it in a vector. Sort the vector and print the elements of the vector.

// // #include <iostream>
// // #include <vector>
// // #include <algorithm>
// // using namespace std;

// // void sumOfAllSet(vector<int> &arr)
// // {
// //     int n = arr.size();
// //     vector<int> sum;
// //     for (int i = 0; i < (1 << n); i++)
// //     {
// //         int sum1 = 0;
// //         for (int j = 0; j < n; j++)
// //         {
// //             if (i & (1 << j))
// //             {
// //                 sum1 += arr[j];
// //             }
// //         }
// //         sum.push_back(sum1);
// //     }
// //     sort(sum.begin(), sum.end());
// //     for (int i = 0; i < sum.size(); i++)
// //     {
// //         cout << sum[i] << " ";
// //     }
// // }

// // int main()
// // {
// //     vector<int> arr = {1, 2, 3};
// //     sumOfAllSet(arr);
// //     return 0;
// // }

// // Time complexity: O(2^n * n)

// //  subset array

// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <bitset>

// using namespace std;

// vector<vector<int>> subset(vector<int> &arr)
// {
//     int n = arr.size();
//     vector<vector<int>> res;

//     cout << "Array size: " << n << endl;
//     for (int i = 0; i < (1 << n); i++) //
//     {
//         vector<int> subset;
//         cout << "i: " << i << " (Binary: " << bitset<8>(i) << ")" << endl;
//         for (int j = 0; j < n; j++)
//         {
//             cout << "  j: " << j << " (Binary: " << bitset<8>(1 << j) << ")" << endl;
//             if (i & (1 << j)) // means
//             {
//                 subset.push_back(arr[j]);
//                 cout << "    Adding arr[" << j << "] = " << arr[j] << " to subset" << endl;
//             }
//         }
//         cout << "  Subset formed: [";
//         for (int k = 0; k < subset.size(); k++) // printing the subset formed from the array arr
//         {
//             cout << subset[k];
//             if (k < subset.size() - 1) // if not the last element of the subset then print a comma after the element
//             {
//                 cout << ", ";
//             }
//         }
//         cout << "]" << endl;
//         res.push_back(subset);
//     }
//     return res;
// }

// int main()
// {
//     vector<int> arr = {1, 2, 3};
//     vector<vector<int>> res = subset(arr);
//     for (int i = 0; i < res.size(); i++)
//     {
//         cout << "[";
//         for (int j = 0; j < res[i].size(); j++)
//         {
//             cout << res[i][j];
//             if (j < res[i].size() - 1)
//             {
//                 cout << ", ";
//             }
//         }
//         cout << "]" << endl;
//     }
//     return 0;
// }

// // Time complexity: O(2^n * n) // because we are generating all the subsets

// // Recursive approach:

// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// void sumOfAllSet(vector<int> &arr, int index, int sum, vector<int> &sum1)
// {
//     cout << "Called sumOfAllSet with index: " << index << ", sum: " << sum << endl;
//     if (index == arr.size())
//     {
//         cout << "Reached end of array, adding sum: " << sum << " to sum1" << endl;
//         sum1.push_back(sum);
//         return;
//     }

//     // Include the current element
//     cout << "Including element " << arr[index] << " at index " << index << endl;

//     sum += arr[index];
//     sumOfAllSet(arr, index + 1, sum + arr[index], sum1);

//     // Exclude the current element
//     cout << "Excluding element " << arr[index] << " at index " << index << endl;
//     sumOfAllSet(arr, index + 1, sum, sum1);
// }

// vector<int> sumOfAllSet(vector<int> &arr)
// {
//     vector<int> sum1;
//     sumOfAllSet(arr, 0, 0, sum1); //  Call the recursive function with index = 0, sum = 0 and sum1 as an empty vector
//     sort(sum1.begin(), sum1.end());
//     return sum1;
// }

// int main()
// {
//     vector<int> arr = {1, 2, 3};
//     cout << "Input array: ";
//     for (int i = 0; i < arr.size(); i++)
//     {
//         cout << arr[i] << " ";
//     }
//     cout << endl;

//     vector<int> sum = sumOfAllSet(arr);
//     cout << "Resulting sums: ";
//     for (int i = 0; i < sum.size(); i++)
//     {
//         cout << sum[i] << " ";
//     }
//     cout << endl;
//     return 0;
// }

// Time complexity: O(2^n) // because we are generating all the subsets
// Space complexity: O(n) // because of the recursive stack

// Dynamic Programming approach:
// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// vector<int> sumOfAllSet(vector<int> &arr)
// {
//     int n = arr.size();
//     vector<int> sum;
//     sum.push_back(0); // Initial sum of the empty subset is 0

//     cout << "Initial sum array: ";
//     for (int s : sum)
//         cout << s << " ";
//     cout << endl;

//     for (int i = 0; i < n; i++)
//     {
//         cout << "Processing element: " << arr[i] << endl;
//         int m = sum.size();
//         for (int j = 0; j < m; j++)
//         {
//             sum.push_back(sum[j] + arr[i]);
//             cout << "Adding " << sum[j] + arr[i] << " to sum array." << endl;
//         }

//         cout << "Sum array after processing element " << arr[i] << ": ";
//         for (int s : sum)
//             cout << s << " ";
//         cout << endl;
//     }

//     sort(sum.begin(), sum.end());
//     cout << "Sum array after sorting: ";
//     for (int s : sum)
//         cout << s << " ";
//     cout << endl;

//     return sum;
// }

// int main()
// {
//     vector<int> arr = {1, 2, 3};
//     cout << "Input array: ";
//     for (int a : arr)
//         cout << a << " ";
//     cout << endl;

//     vector<int> sum = sumOfAllSet(arr);
//     cout << "All subset sums: ";
//     for (int i = 0; i < sum.size(); i++)
//     {
//         cout << sum[i] << " ";
//     }
//     cout << endl;

//     return 0;
// }

// Subset Unique using Recursion

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void subsetUnique(vector<int> &arr, int index, vector<int> &subset, vector<vector<int>> &res)
{
    // Step 3 : Add the subset to the result vector if the index is equal to the size of the array
    if (index == arr.size())
    {
        res.push_back(subset);
        return;
    }

    // Step 4: Include the current element in the subset and call the recursive function with the next index and the updated subset
    subset.push_back(arr[index]);              // Include the current element in the subset
    subsetUnique(arr, index + 1, subset, res); // Call the recursive function with the next index and the updated subset

    // Step 5: Remove the current element from the subset and call the recursive function with the next index and the updated subset
    subset.pop_back(); // Remove the current element from the subset

    while (index + 1 < arr.size() && arr[index] == arr[index + 1])
    {
        index++;
    } // Skip the duplicates to avoid duplicate subsets in the result vector and call the recursive function with the next index and the updated subset
    subsetUnique(arr, index + 1, subset, res); // Call the recursive function with the next index and the updated subset
}

vector<vector<int>> subset(vector<int> &arr)
{
    int n = arr.size();
    vector<vector<int>> res;
    vector<int> subset;

    // Step 1: Sort the array to get the unique subsets in the end result
    sort(arr.begin(), arr.end());

    // Step 2: Call the recursive function to generate the subsets
    subsetUnique(arr, 0, subset, res);

    return res;
}

int main()
{
    vector<int> arr = {1, 2, 2};
    vector<vector<int>> res = subset(arr);

    cout << "All subsets:" << endl;
    for (int i = 0; i < res.size(); i++)
    {
        cout << "[";
        for (int j = 0; j < res[i].size(); j++)
        {
            cout << res[i][j];
            if (j < res[i].size() - 1)
            {
                cout << ", ";
            }
        }
        cout << "]" << endl;
    }
    return 0;
}
