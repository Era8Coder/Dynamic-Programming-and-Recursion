#include<bits/stdc++.h>
using namespace std;

int min_distance(string s1, string s2, int m, int n, vector<vector<int>> &dp){           // Writing the Min_Distance Function
    if(n == 0){
        return dp[m][n];
    }

    if(m == 0){
        return dp[m][n];
    }

    if(dp[m][n] != -1){
        return dp[m][n];
    }

    if(s1[m-1] == s2[n-1]){             // That is basically their last elements
        return dp[m][n] = min_distance(s1, s2, m-1, n-1,dp);          // We had removed the last two elements :_
    }

    return dp[m][n] = 1+min(min((min_distance(s1,s2,m-1,n-1,dp)), min_distance(s1,s2,m,n-1,dp)), min_distance(s1,s2,m-1,n,dp));         // (m-1,n-1) => Case of deletion of last element
    // (m,n-1) => Case of Insertion 
    // (m-1,n) => Case of Deletion from main string 
}

int main(){
    string s1;  cin>>s1;
    string s2;  cin>>s2;
    int m = s1.size();
    int n = s2.size();
    vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
    for(int i=0; i<m+1; i++){
        dp[i][0] = i;
    }
    for(int j=0; j<n+1; j++){
        dp[0][j] = j;
    }
    cout << min_distance(s1,s2,m,n,dp) << endl;
    return 0;
}