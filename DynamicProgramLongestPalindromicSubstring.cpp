#include<bits/stdc++.h>
using namespace std;

bool solve(string &str, int l, int r, vector<vector<int>> &dp){
    if(l >= r){
        return true;
    }

    if(dp[l][r] != -1){
        return dp[l][r];
    }

    if(str[l] == str[r]){
        return dp[l][r] = solve(str, l+1, r-1, dp);
    }

    return dp[l][r] = false;
}

string long_palindrome(string str){
    int n = str.length();
    int max_len = INT_MIN;
    int start_idx = 0;
    vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            if(solve(str,i,j,dp)){                  // If it's a palindrome then we can proceed
                if(j - i + 1 > max_len){    
                    max_len = j - i + 1;
                    start_idx = i;
                }
            }
        }
    }
    return str.substr(start_idx, max_len);
}       

int main(){
    string str; cin>>str;
    string ans = long_palindrome(str);
    cout << ans << endl;
    return 0;
}