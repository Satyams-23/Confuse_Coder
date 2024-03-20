// Rotate a matrix by 90 degree in clockwise direction without using extra space.


#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<vector<int>> rotateMatrix(vector<vector<int>> &matrix)

{

    // Transpose of a matrix
    for(int i=0;i<matrix.size();i++)
    {
        for(int j=i;j<matrix[0].size();j++)
        {
            swap(matrix[i][j],matrix[j][i]);
        }
    }//N^2
// Reverse of a matrix
    for(int i=0;i<matrix.size();i++)
    {
        reverse(matrix[i].begin(),matrix[i].end());
    }//N/2
    return matrix;

}

int main()
{
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    rotateMatrix(matrix);
    for(int i=0;i<matrix.size();i++)
    {
        for(int j=0;j<matrix[0].size();j++)
        {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}


///N^2
/// 1

