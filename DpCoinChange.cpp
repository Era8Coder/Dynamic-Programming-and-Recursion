#include<bits/stdc++.h>
using namespace std;

int coin_change(vector<int> &coins, int amount){
    // Initialisation of DP vector
    vector<int> dp(amount+1, INT_MAX);      // Here we are basically creating an array to store how many coins will be needed to make the amount at index "idx"
    dp[0] = 0;          // Base Case when amount = 0
    
    for(int i=1; i<=amount; i++){
        for(int denomination : coins){          // For loop for the coin's that belong to coins
            /*
                But Why the hell there was need of For loop inside ??
                    Ans: Because we don't know that how many times a coin of single denomination will be used ?
            */
            if(denomination <= i && dp[i-denomination] != INT_MAX){     // checking that we make the i'th place amount using the denomination and checking that i - denomination {previously one} => Exists OR Not :_
                dp[i] = min(dp[i],dp[i-denomination]+1);        // Here we are comparing that what will be minimum of the two cases when we had considered it and when not :_
            }
        }
    }

    if(dp[amount] == INT_MAX){
        return -1;
    }
    return dp[amount];
}

int main(){
    int n;  cin>>n;
    vector<int> coins(n);
    for(int i=0; i<n; i++){
        cin >> coins[i];
    }
    int amount; cin>>amount;
    cout << coin_change(coins, amount) << endl;
    return 0;
}