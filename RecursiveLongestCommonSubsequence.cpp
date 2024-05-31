#include<bits/stdc++.h>
using namespace std;

int solve(string txt1, string txt2, int n, int m){
    if(n == 0 || m == 0){                   // When size of any one of the strings become zero then it's over
        return 0;
    }

    if(txt1[n-1] == txt2[m-1]){
        return 1 + solve(txt1, txt2, n-1, m-1);
    }

    return max(solve(txt1, txt2, n-1, m), solve(txt1, txt2, n, m-1));               // Return the maximum length from anyone of them 
}

int main(){
    string txt1;
    string txt2;
    cin >> txt1;
    cin >> txt2;
    int n = txt1.size();
    int m = txt2.size();
    cout << solve(txt1, txt2, n, m) << endl;
    return 0;
}