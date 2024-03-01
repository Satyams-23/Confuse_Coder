// Given an m x n grid of characters board and a string word, return true if word exists in the grid.

// code
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool exist(vector<vector<char>> &board, string word)
    {
        int m = board.size(); // Number of rows
        int n = board[0].size();
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            { // Loop through the matrix to find the first character of the word and then call the dfs function
                if (board[i][j] == word[0] && dfs(board, i, j, 0, word))
                {
                    return true;
                }
            }
        }
        return false;
    }

    bool dfs(vector<vector<char>> &board, int i, int j, int count, string word)
    {
        if (count == word.length())
        {
            return true;
        }
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[count])
        {
            return false;
        }
        char temp = board[i][j];
        board[i][j] = '*';

        bool found = dfs(board, i + 1, j, count + 1, word) || dfs(board, i - 1, j, count + 1, word) || dfs(board, i, j + 1, count + 1, word) || dfs(board, i, j - 1, count + 1, word);
        board[i][j] = temp;
        return found;
    }
};

int main()
{
    vector<vector<char>> board = {{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
    string word = "ABCCED";
    Solution obj;
    cout << obj.exist(board, word);
    return 0;
}

// complexity analysis
// The time complexity is O(N * 3^L) where N is the number of cells in the board and L is the length of the word to be matched.
//  there is 4 possible directions from each cell, hence 3 recursive calls for each cell. The maximum depth of the recursive call stack would be L. Hence the time complexity is O(N * 3^L) where N is the number of cells in the board and L is the length of the word to be matched.
