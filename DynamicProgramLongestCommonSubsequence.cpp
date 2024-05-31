#include<bits/stdc++.h>
using namespace std;

int solve(string txt1, string txt2, int n, int m, vector<vector<int>> &dp){
    if(n == 0 || m == 0){                   // When size of any one of the strings become zero then it's over
        return 0;
    }

    if(dp[n][m] != -1){
        return dp[n][m];
    }

    if(txt1[n-1] == txt2[m-1]){
        return dp[n][m] = 1 + solve(txt1, txt2, n-1, m-1, dp);
    }

    return dp[n][m] = max(solve(txt1, txt2, n-1, m, dp), solve(txt1, txt2, n, m-1, dp));               // Return the maximum length from anyone of them 
}

int main(){
    string txt1;
    string txt2;
    cin >> txt1;
    cin >> txt2;
    int n = txt1.size();
    int m = txt2.size();
    vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
    cout << solve(txt1, txt2, n, m, dp) << endl;
    return 0;
}