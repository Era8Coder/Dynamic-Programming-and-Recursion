#include<bits/stdc++.h>
using namespace std;

bool solve(int idx, string s, int cnt, vector<vector<int>> &dp){         // Index on which we are currently I am standing || String on which I have to work || Count of Open Brackets
    if(idx == s.size() && cnt == 0){
        return true;                // That is we had reached the end of string and no open brackets are left
    }else if(idx == s.size() && cnt != 0){
        return false;
    }
    if(dp[idx][cnt] != -1){
        return dp[idx][cnt];
    }
    if(s[idx] == '('){
        return dp[idx][cnt] = solve(idx+1, s, cnt+1, dp);
    }else if(s[idx] == ')'){
        if(cnt == 0){
            return false;
        }else{          // Case when {cnt > 0}          => positive open brackets exist
            return dp[idx][cnt] = solve(idx+1, s, cnt-1, dp);      // Reducing cnt => that we are decreasing the size  
        }
    }else{
        bool open = solve(idx+1, s, cnt+1, dp);     // if assuming star as open bracket then increase "cnt"
        bool empty= solve(idx+1, s, cnt, dp);       // if assuming star as empty then no change
        bool close= false;      
        if(cnt > 0){
            close = solve(idx+1, s, cnt-1, dp);         // Assuming it as Closed bracket then it will resolve from here :)
        }               
        return dp[idx][cnt] = open || empty || close;
    }
    return true;
}

bool checkValidString(string s){
    int idx = 0;
    int cnt = 0;
    vector<vector<int>> dp(s.size(), vector<int> (s.size(), -1));
    return solve(idx, s, cnt, dp);
};

int main(){
    string s;   cin>>s;
    cout << checkValidString(s) << endl;
    return 0;
}