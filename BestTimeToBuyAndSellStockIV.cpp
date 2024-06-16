/*
                                -->> MASTER TRICK FOR DYNAMIC PROGRAMMING <<--
    Number of Variables which are changing in the Recursive Solution = N - Dimensional DP We have to Make :)
*/

#include<bits/stdc++.h>
using namespace std;

// Recursive Solution <<--
int solve(vector<int>& prices, int k, int i, bool buy_or_sell) {
    if (i >= prices.size() || k == 0) {
        return 0;
    }

    int ans = 0;

    if (!buy_or_sell) { // Buying case
        int buy = solve(prices, k, i + 1, true) - prices[i];
        int nobuy = solve(prices, k, i + 1, false); // When not buying the stock
        ans = max(buy, nobuy);
    } else { // Selling case
        int sell = solve(prices, k - 1, i + 1, false) + prices[i]; // Selling the stock
        int nosell = solve(prices, k, i + 1, true); // Not selling the stock
        ans = max(sell, nosell);
    }

    return ans;
}

// Dynamic Programming Solution <<--
int dp_solve(vector<int> &prices, int i, int k, bool buy_or_sell, vector<vector<vector<int>>> &dp){
    if(i >= prices.size() || k == 0){   
        return 0;
    }

    if(dp[i][k][buy_or_sell] != -1){
        return dp[i][k][buy_or_sell];
    }

    int ans = 0;

    if(!buy_or_sell){
        int buy = dp_solve(prices, i+1, k, true, dp) - prices[i];      // That is I had purchased the stock on i'th day // and made true so that I can sell now
        int nobuy = dp_solve(prices, i+1, k, false, dp);            // That is when I hadn't purchased then let it be false since I can buy in future
        ans = max(buy, nobuy);
    }else{
        int sell = dp_solve(prices, i+1, k-1, false, dp) + prices[i];       // That is I had sold it on i'th day
        int nosell = dp_solve(prices, i+1, k, true, dp);                    // That decided not to sel and to hold and will sell it later
        ans = max(sell,nosell);
    }

    return dp[i][k][buy_or_sell] = ans;             // That is marking the answer :)
}

int main() {
    int n;
    cin >> n;
    int k;
    cin >> k;
    vector<int> prices(n);
    for (int i = 0; i < n; i++) {
        cin >> prices[i];
    }
    cout << "Recursively programmed Solution: " << endl;
    cout << solve(prices, k, 0, false) << endl;
    vector<vector<vector<int>>> dp(n,vector<vector<int>>(k+1, vector<int>(2,-1)));          // First one is for indexes and second one is for k and last one vector is for true or false         
    cout << "Dynamically Programmed Solution: " << endl;
    cout << dp_solve(prices, 0, k, false, dp);
    return 0;
}
