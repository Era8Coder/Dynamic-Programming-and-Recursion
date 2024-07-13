#include<bits/stdc++.h>
using namespace std;

int solve(vector<vector<int>> &offers, int n, int idx, int sz, vector<int> &dp) {
    if (idx >= sz) {
        return 0;
    }

    if (dp[idx] != -1) {
        return dp[idx];
    }

    // Find the next index that does not overlap with the current offer
    int nxt_idx = idx + 1;
    while (nxt_idx < sz && offers[nxt_idx][0] <= offers[idx][1]) {
        nxt_idx++;
    }
    
    // Calculate the value of taking or not taking the current offer
    int take = solve(offers, n, nxt_idx, sz, dp) + offers[idx][2];
    int not_take = solve(offers, n, idx + 1, sz, dp);
    
    return dp[idx] = max(take, not_take);
}

int maximizeTheProfit(int n, vector<vector<int>> &offers) {
    sort(offers.begin(), offers.end());
    int sz = offers.size();
    vector<int> dp(sz, -1);
    return solve(offers, n, 0, sz, dp);
}