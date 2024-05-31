/*
    It's not standard Problem it's way more thatn IT MORE thinking and directional based problem :_
*/

#include<bits/stdc++.h>
using namespace std;

int solve(vector<vector<int>> &matrix, int n, int m, int &maxi, vector<vector<int>> &dp){
    if(n >= matrix.size() || m >= matrix[0].size()){            // Anyone of these if satisfied then return 0 => Since not possible cases
        return 0;
    }

    if(dp[n][m] != -1){
        return dp[n][m];
    }

    int right = solve(matrix, n, m+1, maxi, dp);
    int diagonal = solve(matrix, n+1, m+1, maxi, dp);
    int down = solve(matrix, n+1, m, maxi, dp);

    if(matrix[n][m] == 1){
        dp[n][m] = 1 + min(min(right,diagonal),down);        // Visualise this we will take the minimum of the square side from all the three sides
        maxi = max(dp[n][m],maxi);               // That is maximum of all the squares possible
        return dp[n][m];            // Return the Square of Maximum Size => That's till that cell <<--
    }
    
    return 0;
}

int main(){
    int n;  cin>>n;
    int m;  cin>>m;
    vector<vector<int>> matrix(n,vector<int>(m,0));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> matrix[i][j];
        }
    }
    int maxi = 0;
    vector<vector<int>> dp(n,vector<int>(m,-1));
    solve(matrix, 0, 0, maxi, dp);            // Making the function to calculate the maximal square
    cout << maxi*maxi << endl;              // Area of the Maximal Triangle
}