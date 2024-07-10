#include<bits/stdc++.h>
using namespace std;

int LIS(vector<int> v){
    int n = v.size();
    vector<int> dp(n,1);
    vector<int> ans(n,-1);
    for(int i=0; i<n; i++){
        for(int j=0; j<i; j++){
            if(v[j] < v[i] && dp[i] < dp[j] + 1){
                dp[i] = max(dp[i],dp[j]+1);
                ans[i]= j;
            }
        }
    }
    int maxi = *max_element(v.begin(), v.end());
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
        res.push_back(v[k]);
        k = ans[k];
    }
    cout << res.size() << endl; 
    reverse(res.begin(),res.end());
    for(auto it : res){
        cout << it << " ";
    }
    cout << endl;
    return maxi;
}

int main(){
    int n;  cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    cout << LIS(v) << endl;
    return 0;
}