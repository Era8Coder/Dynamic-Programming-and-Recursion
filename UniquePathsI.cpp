#include<bits/stdc++.h>
using namespace std;

int solve(int x, int y, int m, int n, vector<vector<int>> &dp){
    if(x >= m || y >= n){
        return 0;
    }
    if(x == m-1 && y == n-1){
        return 1;
    }
    if(dp[x][y] != -1){
        return dp[x][y];
    }
    return dp[x][y] = solve(x+1,y,m,n,dp) + solve(x,y+1,m,n,dp);
}

int uniquePaths(int m, int n) {
    int x = 0;
    int y = 0;
    vector<vector<int>> dp(m,vector<int>(n,-1));
    return solve(x,y,m,n,dp);
}

int main(){
    int m,n;    cin>>m>>n;
    cout << uniquePaths(m,n) << endl;
    return 0;
}