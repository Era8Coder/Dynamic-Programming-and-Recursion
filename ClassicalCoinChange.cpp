// CLASSICAL COIN CHANGE PROBLEM :)
/*
You are given an integer array coins representing coins of different denominations 
and an integer amount representing a total amount of money.
Return the fewest number of coins that you need to make up that amount. 
If that amount of money cannot be made up by any combination of the coins, return -1.
You may assume that you have an infinite number of each kind of coin.
*/

#include<bits/stdc++.h>
using namespace std;

int solve(int idx, vector<int> &coins, int amount){
    if(amount == 0){
        return 0;
    }   

    if(idx >= coins.size()){            // This implies that we don't have enough to make up the given sum therefore it's the case of returning "-1"
        return -1;
    }

    int min_coins = INT_MAX;            // Initialising with the maximum number

    // Using cons[idx] in the solution
    if(coins[idx] <= amount){       // If the value is smaller than Amount       
        int using_coin = solve(idx, coins, amount - coins[idx]);        // Solving using the approach of using_coin
        if(using_coin != -1){       // => That after including the coins[idx] we can move further since the value != -1; {if it's then that implies we can't include it}
            min_coins = min(min_coins, 1 + using_coin);
        }
    }

    // -->> If we are not accounting coins[idx] <<--
    int not_using = solve(idx+1, coins, amount);            // If we hadn't counted the coins[idx] value :)
    if(not_using != -1){        // That is it's possible to make the sum with the given denominations
        min_coins = min(min_coins, not_using);
    }

    if(min_coins == INT_MAX){
        return -1;
    }
    return min_coins;
}

int main(){
    int n;  cin>>n;
    vector<int> coins(n);
    for(int i=0; i<n; i++){
        cin >> coins[i];        // Taking input 
    }
    int amount; cin >> amount;

    cout << solve(0,coins,amount) << endl;
    return 0;
}