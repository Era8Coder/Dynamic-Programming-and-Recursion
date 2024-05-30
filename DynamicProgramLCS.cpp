/*
    Here we are going to write the *Recursive* code for Longest Common Subsequence
*/

#include<bits/stdc++.h>
using namespace std;

int solve(string s1, string s2, int n, int m, vector<vector<int>> &dp){
    /*
        Where n = s1.size()
        Where m = s2.size()    
    */
    if(n == 0 || m == 0){
        return 0;
    }

    if(dp[n][m] != -1){
        return dp[n][m];
    }

    if(s1[n-1] == s2[m-1]){                 
        return dp[n][m] = 1 + solve(s1, s2, n-1, m-1, dp);             // Reducing the size of strings
    }

    return dp[n][m] = max(solve(s1, s2, n, m-1, dp),solve(s1, s2, n-1, m, dp));
}

int main(){
    string s1; cin >> s1;
    string s2; cin >> s2;
    int n = s1.size();
    int m = s2.size();
    vector<vector<int>> dp(n+1,vector<int> (m+1,-1));                // All first rows and first columns are filled with zeros Since in both cases one of the strigs is empty
    for(int i=0; i<n; i++){
        dp[i][0] = 0;
    }
    for(int j=0; j<m; j++){
        dp[0][j] = 0;
    }

    cout << solve(s1, s2, n, m, dp) << endl;
    return 0;
}
