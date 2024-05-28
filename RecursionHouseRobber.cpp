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

int calc(vector<int> &nums, int idx, bool take){       // int idx => index on which I am currently standing and Bool take => should I take that index of not
    if(idx >= nums.size()){
        return 0;
    }

    if(take){               // this means we are taking the idx index one
        return max(nums[idx] + calc(nums, idx+1, false), 0 + calc(nums, idx+1, true));
        // if u add nums[idx] => Then u can't add the immediate next to it    // if u hadn't taken it then u can add the next one to ir
    }

    return calc(nums, idx+1, true);             // not taking the current one due to false and then adding the immediate next one
}

int main(){
    int n;  cin>>n;
    vector<int> nums(n);
    for(int i=0; i<n; i++){
        cin >> nums[i];
    }
    int idx = 0;
    bool take = true;
    cout << calc(nums, idx, take) << endl;
    return 0;
}