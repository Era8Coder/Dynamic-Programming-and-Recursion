#include<bits/stdc++.h>
using namespace std;
/*
    Dijkstra's Algorithm is commonly used for Directed Graphs
    You can Use BFS Algorithm to Calculate shortest distance in Undirected Graph
*/

struct edge{
    int dest;
    int weight;
};

void printvec(vector<int> v){
    for(int i=0; i<v.size(); i++){
        cout << v[i] << " ";
    }
}

vector<int> dijkstra(vector<vector<edge>> &graph, int source){
    int V = graph.size();       // Node of nodes/vertices in the graph
    vector<int> dist(V,INT_MAX);        // Initiating with max. distance
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;                // Making it as Min heap 
    /*
        How does above functioning work ?
        a) DATA STRUCTURE U'R USING
        b) store that DS in vector 
        c) at last use greater to make min heap or less to make max {By default priority queue is Max Heap :)}
    */

    dist[source] = 0;       
    pq.push({0,source});
    // Priority Queue stores
    /*
        Distance firstly and then Node
    */
    // Using Dijkstra's Algorithm
    while(!pq.empty()){
        int u = pq.top().second;            // node with the smallest distance {tentatively}
        pq.pop();

        // Iterate through all neighbouring nodes of the extracted node
        for(auto it : graph[u]){
            int v  = it.dest;
            int wt = it.weight;

            // Relaxation => Updating of the distance using comparators :)
            if(dist[u] + wt < dist[v]){
                dist[v] = dist[u] + wt;
                pq.push({dist[v],v});       // New node which has shorter distance :)
            }
        }
    }
    return dist;
}

int main(){
    // Below is the representation of the Graph using Adjacency List
    vector<vector<edge>> graph = {{{1,4},{2,1}},{{3,2}},{{1,1},{3,5}},{{4,3}},{}};

    // Perform Dijkstra's algo using source node 0
    vector<int> ans = dijkstra(graph,0);
    printvec(ans);
    return 0;
}