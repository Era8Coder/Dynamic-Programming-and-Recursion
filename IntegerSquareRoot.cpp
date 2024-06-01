#include<bits/stdc++.h>
using namespace std;
/*
    Use "Ctrl + Alt + Up/Down" -> To select multiple cursors at a time :_
*/

int main(){
    long long x;  cin>>x;
    long long l = 0;
    long long r = x;
    long long mid = (l+r)/2;
    long long ans = 0;
    while(l <= r){
        if(mid*mid == x){
            ans = mid;
            break;
        }else if(mid*mid > x){
            r = mid - 1;
        }else{
            l = mid + 1;
            ans = mid;      // Updating answer as we move close to mid
        }
        mid = (l+r)/2;
    }
    cout << ans << endl;
    return 0;
}