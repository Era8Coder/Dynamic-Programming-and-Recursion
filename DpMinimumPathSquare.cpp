#include<bits/stdc++.h>
using namespace std;

bool is_valid(int x, int y, int rows, int cols){
    return (x>=0 && y>=0 && x<rows && y<cols);
}

int solve(vector<vector<int>> &grid, int x, int y, vector<vector<int>> &dp){
    int rows = grid.size();
    int cols = grid[0].size();
    if(x == rows-1 && y == cols-1){
        return grid[x][y];
    }

    if(dp[x][y] != -1){
        return dp[x][y];
    }

    if(is_valid(x+1,y,rows,cols) && is_valid(x,y+1,rows,cols)){
        return dp[x][y] = min(solve(grid,x+1,y,dp) + grid[x][y], solve(grid,x,y+1,dp) + grid[x][y]);
    }

    if(is_valid(x+1,y,rows,cols) && !is_valid(x,y+1,rows,cols)){
        return dp[x][y] = solve(grid, x+1, y, dp) + grid[x][y];
    }

    if(is_valid(x,y+1,rows,cols) && !is_valid(x+1,y,rows,cols)){
        return dp[x][y] = solve(grid, x, y+1, dp) + grid[x][y];
    }

    return dp[rows][cols];
}

int main(){
    int n;  cin >> n;
    int m;  cin >> m;
    vector<vector<int>> grid(n, vector<int>(m,-1));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> grid[i][j];
        }
    }
    int x = 0;
    int y = 0;
    vector<vector<int>> dp(n,vector<int> (m,-1));
    cout << solve(grid, x, y, dp) << endl;
    return 0;
}