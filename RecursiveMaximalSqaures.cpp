#include<bits/stdc++.h>
using namespace std;

int solve(vector<vector<int>> &matrix, int n, int m, int &maxi){
    if(n >= matrix.size() || m >= matrix[0].size()){            // Anyone of these if satisfied then return 0 => Since not possible cases
        return 0;
    }

    int right = solve(matrix, n, m+1, maxi);
    int diagonal = solve(matrix, n+1, m+1, maxi);
    int down = solve(matrix, n+1, m, maxi);

    if(matrix[n][m] == 1){
        int ans = 1 + min(min(right,diagonal),down);        // Visualise this we will take the minimum of the square side from all the three sides
        maxi = max(ans,maxi);               // That is maximum of all the squares possible
        return ans;
    }
    
    return 0;
}

int main(){
    int n;  cin>>n;
    int m;  cin>>m;
    vector<vector<int>> matrix(n,vector<int>(m,0));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> matrix[i][j];
        }
    }
    int maxi = 0;
    solve(matrix, 0, 0, maxi);            // Making the function to calculate the maximal square
    cout << maxi*maxi << endl;              // Area of the Maximal Triangle
}