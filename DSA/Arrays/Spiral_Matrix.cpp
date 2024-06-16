// Given an m x n matrix, return all elements of the matrix in spiral order.

// Example 1:
// Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
// Output: [1,2,3,6,9,8,7,4,5]

#include <iostream>
#include <vector>
using namespace std;

vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    vector<int> result;       //
    int m = matrix.size();    // Number of rows
    int n = matrix[0].size(); // Number of columns
    int top = 0, bottom = m - 1, left = 0, right = n - 1;
    while (top <= bottom && left <= right)
    {
        for (int i = left; i <= right; i++)
        {
            result.push_back(matrix[top][i]);
        }
        top++;

        for (int j = top; j <= bottom; j++)
        {
            result.push_back(matrix[j][right]);
        }
        right--;

        if (top <= bottom)
        {
            for (int i = right; i >= left; i--)
            {
                result.push_back(matrix[bottom][i]);
            }
            bottom--;
        }

        if (left <= right)
        {
            for (int j = bottom; j >= top; j--)
            {
                result.push_back(matrix[j][left]);
            }
            left++;
        }
    }
    return result;
}

int main()
{
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<int> result = spiralOrder(matrix);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    return 0;
}

// time complexity : O(m *n)
// space complexity : O(1)