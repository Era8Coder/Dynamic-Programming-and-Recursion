#include<bits/stdc++.h>
using namespace std;

int solve(int idx, vector<int> &nums, vector<int> &dp, int end){
    if(idx > end){
        return 0;
    }

    if(dp[idx] != -1){
        return dp[idx];
    }

    int take = solve(idx+2, nums, dp, end) + nums[idx];
    int not_take = solve(idx+1, nums, dp, end);

    return dp[idx] = max(take, not_take);
}

int rob(vector<int> &nums){
    int n = nums.size();
    vector<int> dp1(n+1,-1), dp2(n+1,-1);
    int first_to_second_last_index = solve(0,nums,dp1,n-2);
    int second_to_last_index = solve(1,nums,dp2,n-1);
    return max(first_to_second_last_index, second_to_last_index);
}

int main(){
    int n;  cin>>n;
    vector<int> nums(n);
    for(int i=0; i<n; i++){
        cin >> nums[i];
    }
    cout << rob(nums) << endl;
    return 0;
}