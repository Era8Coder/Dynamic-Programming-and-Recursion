#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a; i<b; i++)
typedef long long ll;
using namespace std;

int solve(vector<int> &v, int idx, int prev_idx){
    if(idx == v.size()){
        return 0;
    }

    int max_length = 0;
    if(prev_idx == -1 || v[idx] > v[prev_idx]){         // that is the case of starting index and increasing subsequence
        max_length = max(max_length, solve(v, idx+1, idx) + 1);         // Second case is when I had included the current index and added 1 in it :_
    }

    // Not taking the Element :_
    max_length = max(max_length, solve(v, idx+1, prev_idx));          // When prev_idx is immediate previous one :)
    return max_length;
}

int main(){
    int n;  cin>>n;
    vector<int> v(n);
    rep(i,0,n){
        cin>>v[i];
    }
    int idx = 0;
    int prev_idx = -1;
    cout << solve(v, idx, prev_idx) << endl;
    return 0;
}