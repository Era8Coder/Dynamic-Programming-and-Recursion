/*
    Problem Statement :
    Given a set of distinct positive integers nums, return the largest subset answer such that 
    every pair (answer[i], answer[j]) of elements in this subset satisfies:

    answer[i] % answer[j] == 0, or
    answer[j] % answer[i] == 0
    If there are multiple solutions, return any of them.
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int> nums){
    int n = nums.size();
    sort(nums.begin(), nums.end());
    vector<int> dp(n,1);
    vector<int> ans(n,-1);
    for(int i=0; i<n; i++){
        for(int j=0; j<i; j++){
            if((nums[i]%nums[j] == 0) && (dp[i] < dp[j] + 1)){
                dp[i] = max(dp[i], dp[j] + 1);
                ans[i]= j;
            }
        }
    }
    int maxi = *max_element(dp.begin(), dp.end());
    int idx = 0;
    for(int i=0; i<n; i++){
        if(dp[i] == maxi){
            idx = i;
            break;
        }
    }
    vector<int> res;
    int k = idx;
    while(k != -1){
        res.push_back(nums[k]);
        k = ans[k];
    }
    reverse(res.begin(), res.end());
    return res;
}

int main(){
    int n=3;
    vector<int> v = {1,2,4,8};
    vector<int> ans = solve(v);
    for(auto it : ans){
        cout << it << " ";
    }
    cout << endl;
    return 0;
}