
#include<bits/stdc++.h>
using namespace std;
int dfs(vector<vector<char>> &grid, int i, int j)
{
    if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size()){
        return;
    }
    if(grid[i][j] == '2' || grid[i][j] == '0')
        return; 
    grid[i][j] = '2';
    dfs(grid, i, j - 1);
    dfs(grid, i - 1, j);
    dfs(grid, i + 1, j);
    dfs(grid, i, j + 1);

}
int numIslands(vector<vector<char>>& grid) {
    int islands = 0;
    for (size_t i = 0; i < grid.size(); i++)
    {
        for (size_t i = 0; i < grid[0].size(); i++)
        {
            if(grid[i][j] == '1'){ 
                dfs(grid, i, j);
                islands++;
            }
        }
                
    }
    
}
    