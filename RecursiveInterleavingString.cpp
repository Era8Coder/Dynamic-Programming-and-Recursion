#include<bits/stdc++.h>
using namespace std;

bool solve(string s1, string s2, string s3, int n, int m, int l){
    // Base case: If all strings are empty, then interleaving is possible
    if(n == s1.size() && m == s2.size() && l == s3.size()){
        return true;
    }


    
    // If s1 and s3 match at current index l, recurse by incrementing n and l
    if(n < s1.size() && s1[n] == s3[l]){
        if(solve(s1, s2, s3, n+1, m, l+1)){
            return true;
        }
    }

    // If s2 and s3 match at current index l, recurse by incrementing m and l
    if(m < s2.size() && s2[m] == s3[l]){
        if(solve(s1, s2, s3, n, m+1, l+1)){
            return true;
        }
    }
    
    return false;
}

int main(){
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    int n = 0, m = 0, l = 0;
    vector<vector<bool>> dp(n,vector<bool>(m,false));

    return 0;
}
