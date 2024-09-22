//Number of Islands

#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<char>> &grid, int i, int j){
    int n = grid.size(); //no of rows
    int m = grid[0].size(); //no of columns

    if(i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == '0') return;//boundary conditions and if it is water then return 

    grid[i][j] = '0';

    dfs(grid, i+1, j);//down
    dfs(grid, i-1, j);//up
    dfs(grid, i, j+1);//right
    dfs(grid, i, j-1);//left

        
}

int numIslands(vector<vector<char>> &grid){
    int n = grid.size();
    int m = grid[0].size();
    int count = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == '1'){
                dfs(grid, i, j);
                count++;
            }
        }
    }
    return count;
}


int main(){
    vector<vector<char>> grid = {
        {'1', '1', '0', '0', '1'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}
    };

    cout << numIslands(grid) << endl;

    return 0;
    
}
