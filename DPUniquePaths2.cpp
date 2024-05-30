// Problem Statement
/*
You are given an m x n integer array grid. There is a robot initially located at the top-left corner (i.e., grid[0][0]). 
The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or 
right at any point in time.
An obstacle and space are marked as 1 or 0 respectively in grid. A path that the robot takes cannot 
include any square that is an obstacle.
Return the number of possible unique paths that the robot can take to reach the bottom-right corner.
*/

#include<bits/stdc++.h>
using namespace std;

int solve(vector<vector<int>> &grid, vector<vector<int>> &dp,  int x, int y){                // Function to return the Minimum number of Paths
    int rows = grid.size();
    int cols = grid[0].size();

    if(x>=rows || y>=cols || grid[x][y] == 1){                  // That is when any one of the three conditions is satisfied
        return 0;
    }

    if(x == rows - 1 && y == cols - 1){             // When we are at end
        return 1;
    }

    // Checking that if the dp array is pre-cmoputed or not
    if(dp[x][y] != -1){
        return dp[x][y];
    }

    dp[x][y] = solve(grid, dp, x+1, y) + solve(grid, dp, x, y+1);           // Considering both the sides <<--
    return dp[x][y];
}

int main()
{
    int m;  cin >> m;
    int n;  cin >> n;
    vector<vector<int>> grid(m,vector<int>(n,0));
    vector<vector<int>> dp(m,vector<int>(n,-1));
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cin >> grid[i][j];
        }
    }
    int x = 0;
    int y = 0;
    cout << solve(grid, dp, x, y) << endl;
    return 0;
}