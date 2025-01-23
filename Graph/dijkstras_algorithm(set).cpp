//Using set daata structure
//Set-> stores unique values in ascending order
//set(dist, node)

//Solving using set
#include<bits/stdc++.h>
using namespace std;

#define le9 1000000

vector<int> dijkstra(int V, vector<vector<int>>adj[], int S){

    set<pair<int,int>> st;
    vector<int> dist(V, le9);


    st.insert({0,S});
    dist[S] = 0;

    while(!st.empty()){
        auto it = *(st.begin()); //it points to the value
        int node = it.second;
        int dis = it.first;
        st.erase(it);

        for(auto it : adj[node]){
            int adjNode = it[0];
            int edgeWeight = it[1];

            if(dis + edgeWeight < dist[adjNode]){
                if(dist[adjNode] != le9){ 
                    st.erase({dist[adjNode], adjNode});
                }
                dist[adjNode] = dis + edgeWeight;
                st.insert({dist[adjNode], adjNode});
            }

        }
    }

    return dist;

}

int main(){

    int V = 3, E = 3, S = 0;
    vector<vector<int>> adj[V];
    
    // Adding edges to the adjacency list
    adj[0].push_back({1, 1});  // edge from node 0 to node 1 with weight 1
    adj[0].push_back({2, 6});  // edge from node 0 to node 2 with weight 6
    adj[1].push_back({2, 3});  // edge from node 1 to node 2 with weight 3
    adj[1].push_back({0, 1});  // edge from node 1 to node 0 with weight 1
    adj[2].push_back({1, 3});  // edge from node 2 to node 1 with weight 3
    adj[2].push_back({0, 6});  // edge from node 2 to node 0 with weight 6

    // Running Dijkstra's algorithm
    vector<int> res = dijkstra(V, adj, S);

    // Printing the shortest distances from the source node S
    for(int i = 0; i < V; i++){
        if (i == S) {
            cout << "Shortest distance from node " << S << " to itself is 0.\n";
        } else {
            cout << "Shortest distance from node " << S << " to node " << i << " is " << res[i] << ".\n";
        }
    }


    return 0;
}