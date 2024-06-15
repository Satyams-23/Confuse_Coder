// pascals traingle using c++

//  find the pascal's triangle upto n rows using c++ and also print the nth row of the pascal's triangle and also print the nth element of the mth row of the pascal's triangle

// better approach

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> generatePascalsTriangle(int n)
{
    vector<vector<int>> triangle(n);
    for (int i = 0; i < n; i++)
    {
        triangle[i].resize(i + 1);
        triangle[i][0] = triangle[i][i] = 1;
        for (int j = 1; j < i; j++)
        {
            triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
        }
    }
    return triangle;
}

int main()
{
    int n, m;
    cout << "Enter the row number: ";
    cin >> n;
    cout << "Enter the element number: ";
    cin >> m;
    vector<vector<int>> triangle = generatePascalsTriangle(n);
    cout << "The element at row " << n << " and column " << m << " is: " << triangle[n - 1][m - 1] << endl;
    return 0;
}

// time complexity: O(n^2)
// space complexity: O(n^2) //

// Pascal's Triangle is a triangle of numbers which is constructed by following these rules:

#include <iostream>
#include <vector>
using namespace std;

vector<int> pascalsTriangle(int n)
{

    long long ans = 1;
    vector<int> row;
    row.push_back(1);
    for (int i = 1; i < n; i++)
    {
        ans = ans * (n - i); //
        ans = ans / i;       //
        row.push_back(ans);
    }
    return row;
}

vector<vector<int>> generatePascalsTriangle(int n)
{
    vector<vector<int>> triangle;
    for (int i = 0; i < n; i++)
    {
        triangle.push_back(pascalsTriangle(i + 1));
    }
    return triangle;
}

// int main()
// {
//     int n;
//     cout << "Enter the number of rows of the pascal's triangle: ";
//     cin >> n;
//     vector<vector<int>> triangle = generatePascalsTriangle(n);
//     cout << "The Pascal's Triangle upto " << n << " rows is: " << endl;
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < triangle[i].size(); j++)
//         {
//             cout << triangle[i][j] << " ";
//         }
//         cout << endl;
//     }
//     return 0;
// }

int main()
{
    int n, m;
    cout << "Enter the row number: ";
    cin >> n;
    cout << "Enter the element number: ";
    cin >> m;
    vector<vector<int>> triangle = generatePascalsTriangle(n);
    cout << "The element at row " << n << " and column " << m << " is: " << triangle[n - 1][m - 1] << endl;
    return 0;
}

// time complexity: O(n^2)
// space complexity: O(n^2)