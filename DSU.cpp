// dsu => NOT ASKED IN COMPANIES INTERVIEW
/* Mostly used in Competitive Programming Problems */
/*
    Where it is used ??
    a) When to make groups/sets => or to combine :)
    b) Can be used to find the number of connected components
    
    Three Function are there in DSU =>
        i) Make -> A new node is added in the network {Independent Nodes are made}
        ii)Find -> find(A) => It will return the parent of the Group
        iii) Union -> Combine A and B and return the whole group 

    Union(1,2) =>       [2] -> [1]   
                    "2 is connected below 1"
    Union(3,4) =>       [4] -> [3]
                    "4 is connected below 3"
                OR 1,3 are parent Nodes
    Find()  => Returns the root of the Tree
    Union(2,4) => We always join the root nodes
        =>         [2] -> [1] <- [3] <- [4]
        Find(4) => [1] {Since new root is 1 now} :)
            ""
                We can also optimize it **
            ""
*/
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
vector<int> parent(N,0);
int size[N];

void make(int v){
    parent[v] = v;
    size[v] = 1;
}

int find(int v){    // We will make recursive function which will run till we return to the node whose parent is itself that node
    if(v == parent[v]) return v;    // Termination / Base Condition
    return find(parent[v]);     // recursively calling
}

int find_pathcompression(int v){
    if(v == parent[v]) return v;
    return parent[v] = find(parent[v]);
}

void Union(int a, int b){
    // Get the root of both 
    a = find(a);
    b = find(b);
    // If a and b have same roots then they are in same group 
    if (a != b) {       // Then this implies that they don't have same parent
        parent[b] = a;
    }
}

void Union_bysize(int a, int b){
    a = find(a);
    b = find(b);
    if(a != b){     // => Parent's are not same
        if(size[a] < size[b]){
            swap(a,b);
        }
        parent[b] = a;
        size[a] += size[b];
    }
}

/*
    Simple Union can lead to O(nodes) complexity when they are added in series
    Since we are combining the Right tree below left tree
    We can reduce it's complexity on the basis of size{Number of nodes} or Rank{Depth}
*/
/* Path compression is basically to reduce the path and making the direct link between parent and it's node*/
/*
    Amortized Time Complexity => O(Alpha(n)) -> Reverse Ackermann Function
    Alpha(n) -> Increases slowly :)
*/
int main(){
    int n, k;  cin>>n>>k;
    for(int i=1; i<=n; i++){
        make(i);
    }
    while(k--){
        int u,v;
        cin >> u >> v;
        Union(u,v);
    }
    int connected_ct = 0;
    for(int i=1; i<=n; i++){
        if(i == find(i)){
            connected_ct++;
        }
    }
    cout << connected_ct << endl;
    return 0;
}