#include<bits/stdc++.h>
using namespace std;

int min_distance(string s1, string s2, int m, int n){           // Writing the Min_Distance Function
    if(n == 0){
        return m;
    }

    if(m == 0){
        return n;
    }

    if(s1[m-1] == s2[n-1]){             // That is basically their last elements
        return min_distance(s1, s2, m-1, n-1);          // We had removed the last two elements :_
    }

    return 1+min(min((min_distance(s1,s2,m-1,n-1)), min_distance(s1,s2,m,n-1)), min_distance(s1,s2,m-1,n));         // (m-1,n-1) => Case of deletion of last element
    // (m,n-1) => Case of Insertion 
    // (m-1,n) => Case of Deletion from main string 
}

int main(){
    string s1;  cin>>s1;
    string s2;  cin>>s2;
    int m = s1.size();
    int n = s2.size();
    cout << min_distance(s1,s2,m,n) << endl;
    return 0;
}