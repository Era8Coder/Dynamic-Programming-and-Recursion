#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a; i<b; i++)
typedef long long ll;
using namespace std;

int solve(vector<int> &v){      // Solve will just have the input pararmeter as v :_
    int n = v.size();
    vector<int> dp(n,1);        // This implies a DP array with initial values 1{Minm. size possible initially is "1"}

    for(int i=1; i<n; i++){
        for(int j=0; j<i; j++){     // LIS logic is to compare the current element with all the previous ones 
            if(v[i] > v[j]){            // that is basically the current element > in the series of it
                dp[i] = max(dp[i],dp[j]+1);
            }
        }
    }

    return *max_element(dp.begin(),dp.end());
}

int main(){
    int n;  cin>>n;
    vector<int> v(n);
    rep(i,0,n){
        cin>>v[i];
    }
    int idx = 1;
    int prev_idx = 0;
    cout << solve(v) << endl;
    return 0;
}