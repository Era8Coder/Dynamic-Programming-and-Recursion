/*
    One of the classic Recursive or Dp problem on string Data_Structure Asked by Google and then by many companies :)
*/
#include<bits/stdc++.h>
using namespace std;

bool word_break(string str, vector<string> &word_dict){
    if(str.size() == 0){
        return true;            // Since string of length 0 can always be made from the given word dictionary
    }

    for(int i=1; i<=str.size(); i++){
        string test = str.substr(0,i);              // Last index is not included in the substring function
        if(find(word_dict.begin(), word_dict.end(), test) != word_dict.end() && word_break(str.substr(i), word_dict)){ 
            // First condition ensures that if substring is found in the array // Second one is recursive call to find the remaining part in the same array
            // If both are satisfied then U had found the answer otherwise not :_
            return true;
        }
    }
    return false;
}

int main(){
    vector<string> word_dict1 = {"apple","pen","apple"};
    string str1 = "applepenapple";
    vector<string> word_dict2 = {"cats","dog","sand","and","cat"};
    string str2 = "catsandog";
    cout << word_break(str1, word_dict1) << endl;
    cout << word_break(str2, word_dict2) << endl;
    return 0;
}