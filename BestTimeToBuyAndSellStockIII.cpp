/*
                                -->> MASTER TRICK FOR DYNAMIC PROGRAMMING <<--
    Number of Variables which are changing in the Recursive Solution = N - Dimensional DP We have to Make :)
*/

#include<bits/stdc++.h>
using namespace std;

// Recursive Solution <<--
int maxProfit(vector<int> &prices, int i, int k, bool buy_or_sell){
    if(i >= prices.size() || k == 0){
        return 0;                       // If u had traversed the full array or u are exhausted with choices <<--
    }

    int ans = 0;            // That is the Final Answer

    if(!buy_or_sell){           // That is Here you have to Buy
        int buy = maxProfit(prices, i+1, k, true) - prices[i];              // When u had purchased the stock now it's time to Sell It
        int nobuy = maxProfit(prices, i+1, k, false);                         // When u had not purchaed in i'th day therefore u have to buy first
        ans = max(buy, nobuy);
    }else{              // Now we have to sell the stock            -->> Only Two things are changing ahere <<-- i and but_or_sell
        int sell = maxProfit(prices, i+1, k-1, false) + prices[i];            // We had purchased on the i'th day and marked but_or_sell as false -> we can buy now
        int nosell = maxProfit(prices, i+1, k, true);
        ans = max(sell, nosell);            // Get maximum after Selling or not-selling 
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

int main(){
    int n;  cin>>n;
    int k=2;
    vector<int> prices(n);
    for(int i=0; i<n; i++){
        cin >> prices[i];
    }
    cout << "Recursive Programmed is below: " << endl;
    cout << maxProfit(prices, 0, 2, false) << endl;
    vector<vector<vector<int>>> dp(n,vector<vector<int>>(k+1, vector<int>(2,-1)));          // First one is for indexes and second one is for k and last one vector is for true or false         
    cout << "Dynamic Programmed Solution is Below: " << endl;
    cout << dp_solve(prices, 0, 2, false, dp) << endl;
    return 0;
}