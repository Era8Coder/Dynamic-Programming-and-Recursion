#include<bits/stdc++.h>
using namespace std;

int solve(vector<vector<int>> &v, int idx, int depth, int n){
    if(depth == n-1){       // Then return the last element not zero :_
        return v[depth][idx];
    }

    return min(solve(v,idx,depth+1,n) + v[depth][idx], solve(v,idx+1,depth+1,n) + v[depth][idx]);
}

int main(){
    int n;  cin>>n;
    vector<vector<int>> v(n);
    int x;
    for(int i=0; i<n; i++){
        for(int j=0; j<=i; j++){
            cin >> x;
            v[i].push_back(x);
        }
    }

    int idx = 0;
    int depth = 0;          // MAXIMUM Depth is "n"
    cout << solve(v,idx,depth,n) << endl;
    return 0;
}
