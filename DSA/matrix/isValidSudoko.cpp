class Solution
{

private:
    bool hasDuplicate(const vector<char> &group)
    {
        for (int i = 0; i < group.size(); i++)
        {
            for (int j = i + 1; j < group.size(); j++)
            {
                if (group[i] != '.' && group[i] == group[j])
                {
                    return true;
                }
            }
        }
        return false;
    }

public:
    bool isValidSudoku(vector<vector<char>> &board)
    {

        // check row
        for (const auto &row : board)
        {
            if (hasDuplicate(row))
            {
                return false;
            }
        }

        // check col

        for (int col = 0; col < 9; col++)
        {
            vector<char> column;
            for (int row = 0; row < 9; row++)
            {
                column.push_back(board[row][col]);
            }
            if (hasDuplicate(column))
            {
                return false;
            }
        }

        // check 3*3

        for (int col = 0; col < 9; col += 3)
        {
            for (int row = 0; row < 9; row += 3)
            {
                vector<char> subgrid;
                for (int i = col; i < col + 3; i++)
                {
                    for (int j = row; j < row + 3; j++)
                    {
                        subgrid.push_back(board[j][i]);
                    }
                }

                if (hasDuplicate(subgrid))
                {
                    return false;
                }
            }
        }

        return true;
    }
};