/*
    >-< Learning how to use Bitset in Bit Manipulation problems in C++ >-<
    /
        Compiling and Running the Program =>
            a) g++ Filename.cpp
            b) ./Filename.exe
    /
*/

#include<bits/stdc++.h>
using namespace std;

void printvec(vector<int> v){
    for(int i=0; i<v.size(); i++){
        cout << v[i] << " ";
    }
}

int main(){
    bitset<8> v(15);
    bitset<32>c(20);
    cout << v << endl;
    cout << c << endl;
    for(int i=0; i<8; i++){
        if(i%2 == 0){
            v[i] = 1;
        }
    }
    // Bitset prints in the same order as we write in copy or by Hands :)
    cout << v << endl;
    vector<int> b = {1,2,3,4,5};
    printvec(b);
    return 0;
}