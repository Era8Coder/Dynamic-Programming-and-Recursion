/*
You are a professional robber planning to rob houses along a street. 
Each house has a certain amount of money stashed, the only constraint 
stopping you from robbing each of them is that adjacent houses have 
security systems connected and it will automatically contact the police if 
two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, 
return the maximum amount of money you can rob tonight without alerting the police.
*/
#include<bits/stdc++.h>
using namespace std;
// It's one of the Good 1D DP Problem :)

int calc(int idx, int n, vector<int> &dp, vector<int> nums){
    if(idx >= n){           // this means that we are out of range
        return 0;
    }

    if(dp[idx]!=-1){                // this means that it has been precomputed
        return dp[idx];
    }

    return dp[idx] = max(nums[idx] + calc(idx+2, n, dp, nums), 0 + calc(idx+1, n, dp, nums));
    // max(A,B) 
    /*
        A -> that we had included current one and we have to include now the next after leaving one index
        B -> that we hadn't included now next to be included is idx + 1 onwards
    */
}

int main(){
    int n;  cin>>n;
    vector<int> nums(n);
    for(int i=0; i<n; i++){
        cin >> nums[i];
    }
    vector<int> dp(n,-1);       // Initialising the 1D array with -1 :)
    cout << calc(0, n, dp, nums) << endl;
    return 0;
}