#include<bits/stdc++.h>
using namespace std;

bool solve(string a, string b, string c, int n, int m, int l, vector<vector<int>> &dp){
    if(l == 0){
        return 1;
    }

    if(dp[n][m] != -1){
        return dp[n][m];
    }

    if(n > 0 && a[n-1] == c[l-1]){
        return dp[n][m] = solve(a,b,c,n-1,m,l-1,dp);
    }
    if(m > 0 && b[m-1] == c[l-1]){
        return dp[n][m] = solve(a,b,c,n,m-1,l-1,dp);
    }
}

int main(){
    string a,b,c;
    cin >> a >> b >> c;
    int n,m,l;
    n = a.size();
    m = b.size();
    l = c.size();
    if(n + m != l){
        cout << 0 << endl;
    }else{
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        cout << solve(a,b,c,n,m,l,dp) << endl;
    }
    return 0;
}