/*
    Here we are going to write the *Recursive* code for Longest Common Subsequence
*/

#include<bits/stdc++.h>
using namespace std;

int solve(string s1, string s2, int n, int m){
    /*
        Where n = s1.size()
        Where m = s2.size()    
    */
    if(n == 0 || m == 0){
        return 0;
    }

    if(s1[n-1] == s2[m-1]){                 
        return 1 + solve(s1, s2, n-1, m-1);             // Reducing the size of strings
    }

    return max(solve(s1, s2, n, m-1),solve(s1, s2, n-1, m));
}

int main(){
    string s1; cin >> s1;
    string s2; cin >> s2;
    int n = s1.size();
    int m = s2.size();
    cout << solve(s1, s2, n, m) << endl;
    return 0;
}
