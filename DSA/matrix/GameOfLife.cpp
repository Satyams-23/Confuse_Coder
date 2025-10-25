#include <include <vector>
using namespace std;

void gameoflife(vector<vector<int>> &board)
{
    \/ Directions for the 8 neighbors
    vector<pair<int, int>> directions = {
        {-1, -1}, {-1, 0}, {-1, 1},
        {0, -1},          {0, 1},
        {1, -1},  {1, 0},  {1, 1}
    };
    int r = board.size();
    int c = board[0].size();
    vector<vector<int>> temp = board; // Create a copy of the original board to reference original states during updates
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            int liveNeighbors = 0;
            for (auto dir : directions)
            {
                int newRow = i + dir.first;
                int newCol = j + dir.second;
                if (newRow >= 0 && newRow < r && newCol >= 0 && newCol < c)
                {

                    // Count live neighbors (considering both original live cells and those marked to die)
                    if (temp[newRow][newCol] == 1)
                    {
                        liveNeighbors++;
                    }
                }
            }
            // Apply the Game of Life rules
            if (temp[i][j] == 1) // why we dont check from board? because board is being updated in place
            {
                // Rule 1 or Rule 3: Live cell with fewer than two or more than three live neighbors dies
                if (liveNeighbors < 2 || liveNeighbors > 3)
                {
                    board[i][j] = 0; // Mark as dead
                }
                // Rule 2: Live cell with two or three live neighbors lives on to the next generation
                // (No action needed, remains alive)
            }
            else
            {
                // Rule 4: Dead cell with exactly three live neighbors becomes a live cell
                if (liveNeighbors == 3)
                {
                    board[i][j] = 1; // Mark as alive
                }
            }
        }
    }

    return;
}

//////////////////////////// Another Approach Using In-Place State Encoding
void gameOfLifeInPlace(vector<vector<int>> &board)

{
    int rows = board.size();
    int cols = board[0].size();

    // First pass: determine the next state and encode it in the current state
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            int liveNeighbors = 0;

            // Count live neighbors
            for (int x = -1; x <= 1; x++)
            {
                for (int y = -1; y <= 1; y++)
                {
                    if (x == 0 && y == 0) // why need this check?
                        continue;         // Skip the cell itself
                    int ni = i + x;
                    int nj = j + y;
                    if (ni >= 0 && ni < rows && nj >= 0 && nj < cols)
                    {
                        liveNeighbors += board[ni][nj] & 1; // Only consider the current state why & 1? because we are encoding next state in 2nd bit
                        // board[ni][nj] can be 0,1,2,3 but we only care about current state which is stored in least significant bit
                        // (0 or 1)
                        // 0 -> 00 (dead to dead)
                        // 1 -> 01 (live to dead)
                    }
                }
            }

            // Apply the Game of Life rules and encode the next state
            if (board[i][j] == 1 && (liveNeighbors == 2 || liveNeighbors == 3))
            {
                board[i][j] = 3; // Live to live
            }
            else if (board[i][j] == 0 && liveNeighbors == 3)
            {
                board[i][j] = 2; // Dead to live
            }
        }
    }

    // Second pass: update the board to the next state
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            board[i][j] >>= 1; // Update to the next state
        }
    }

    return;
}

// dry run the code with example input and output

// matrix = {{0,1,0},
//           {0,0,1},
//           {1,1,1},
//           {0,0,0}}

// After first pass (encoding next state):
// matrix = {{0,1,0},
//           {0,0,1},
//           {1,1,3},
