#include<bits/stdc++.h>
using namespace std;
                    /*
                        Number of Variables changing = That much dimension of Dp {Dynamic Array}       
                                    -->> Here i,m,n were varying <<--
                    */
int solve(vector<pair<int,int>> &vp, int m, int n, int i, vector<vector<vector<int>>> &dp) {
    int sz = vp.size();
    if (i == sz || m < 0 || n < 0) {
        return 0;
    }
    if (dp[i][m][n] != -1) {
        return dp[i][m][n];
    }
    if (vp[i].first > m || vp[i].second > n) {
        dp[i][m][n] = solve(vp, m, n, i + 1, dp);
    } else {
        int include = solve(vp, m - vp[i].first, n - vp[i].second, i + 1, dp) + 1;
        int exclude = solve(vp, m, n, i + 1, dp);
        dp[i][m][n] = max(include, exclude);
    }
    return dp[i][m][n];
}

int findMaxForm(vector<string> &strs, int m, int n) {
    vector<pair<int,int>> vp;
    int cnt0 = 0;
    int cnt1 = 0;
    for(int i=0; i<strs.size(); i++){
        cnt0 = 0;
        cnt1 = 0;
        for(int j=0; j<strs[i].size(); j++){
            if(strs[i][j] == '0'){
                cnt0++;
            }else{
                cnt1++;
            }
        }
        vp.push_back(make_pair(cnt0, cnt1));
    }
    int sz = vp.size();
    vector<vector<vector<int>>> dp(sz, vector<vector<int>>(m + 1, vector<int>(n + 1, -1)));
    return solve(vp, m, n, 0, dp);
}

int main(){
    vector<string> strs = {"10","0","1"};
    int m = 1;
    int n = 1;
    cout << findMaxForm(strs, m, n) << endl;
    return 0;
}
