
#include <vector>
using namespace std;

class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int row = matrix.size();
        int col = matrix[0].size();

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (matrix[i][j] == 0)
                {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for (int i = 1; i < row; i++)
        {
            for (int j = 1; j < col; j++)
            {
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                {
                    matrix[i][j] = 0;
                }
            }
        }

        if (matrix[0][0] == 0)
        {
            for (int j = 0; j < col; j++)
            {
                matrix[0][j] = 0;
            }
        }

        bool firstColZero = false;

        for (int i = 0; i < row; i++)
        {
            if (matrix[i][0] == 0)
            {
                firstColZero = true;
                break;
            }
        }

        if (firstColZero)
        {
            for (int i = 0; i < row; i++)
            {
                matrix[i][0] = 0;
            }
        }
    }
};

//     int rows = matrix.size();
//     int cols = matrix[0].size();
//     bool firstRowZero = false;
//     bool firstColZero = false;

//     // Check if first row has a zero
//     for (int j = 0; j < cols; j++)
//     {
//         if (matrix[0][j] == 0)
//         {
//             firstRowZero = true;
//             break;
//         }
//     }

//     // Check if first column has a zero
//     for (int i = 0; i < rows; i++)
//     {
//         if (matrix[i][0] == 0)
//         {
//             firstColZero = true;
//             break;
//         }
//     }

//     // Use first row and column as markers
//     for (int i = 1; i < rows; i++)
//     {
//         for (int j = 1; j < cols; j++)
//         {
//             if (matrix[i][j] == 0)
//             {
//                 matrix[i][0] = 0;
//                 matrix[0][j] = 0;
//             }
//         }
//     }

//     // Set matrix cells to zero based on markers
//     for (int i = 1; i < rows; i++)
//     {
//         for (int j = 1; j < cols; j++)
//         {
//             if (matrix[i][0] == 0 || matrix[0][j] == 0)
//             {
//                 matrix[i][j] = 0;
//             }
//         }
//     }

//     // Set first row to zero if needed
//     if (firstRowZero)
//     {
//         for (int j = 0; j < cols; j++)
//         {
//             matrix[0][j] = 0;
//         }
//     }

//     // Set first column to zero if needed
//     if (firstColZero)
//     {
//         for (int i = 0; i < rows; i++)
//         {
//             matrix[i][0] = 0;
//         }
//     }
// }
// };