#include <bits/stdc++.h>
using namespace std;

// void multistage(vector<vector<int>> &graph, int V){
//     int cost[V];
//     int path[V];

//     int destination = V - 1;
//     cost[destination] = 0;
//     path[destination] = destination;

//     for(int i = V - 2; i>=0; i--){
//         int mincost = INT_MAX;

//         for(int j = i+1; j<V; j++){
//             if(graph[i][j] != 0 && cost[j] + graph[i][j] < mincost){
//                 mincost = cost[j] + graph[i][j];
//                 path[i] = j;
//             }
//         }
//         cost[i] = mincost;
//     }

//     cout<<"Min cost is: "<<cost[0];
//     cout<<"Path is: ";
//     int curr = 0; //?source vertex which is 0
//     while(curr != destination){
//         cout<<curr<<" ";
//         curr = path[curr];
//     }
//     cout<<destination<<endl;
// }

// void prims(vector<vector<pair<int, int>>> &graph, int V){
//     priority_queue< pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pg;

//     vector<bool> inMST(V, false);
//     vector<int> key(V, INT_MAX);
//     vector<int> parent(V, -1);

//     key[0] = 0;
//     pq.push({0, 0});

//     while(!pq.empty()){
//         int currentnode = pq.top().second;
//         pq.pop();

//         if(inMST[currentnode]) continue;

//         inMST[currentnode] = true;

//         for(auto e : graph[currentnode]){
//             int adjnode = e.first;
//             int weight = e.second;

//             if(!inMST[adjnode] && weight < key[adjnode]){
//                 key[adjnode] = weight;
//                 pq.push({key[adjnode], adjnode});
//                 parent[adjnode] = currentnode;
//             }
//         }
//     }

//     int totalweight = 0;
//     cout<<"edge\tweight"<<endl;
//     for(int i = 0; i<V; i++){
//         cout<<parent[i]<<" - "<<i<<"\t"<<key[i]<<endl;
//         totalweight += key[i];
//     }

//     cout<<"The total weight is: "<<totalweight<<endl;
// }

void bellmanFord( vector<vector<pair<int, int>>> &graph, int V, int src){

    vector<int> dist(V, INT_MAX);
    dist[src] = 0;

    for(int i = 0; i< V-1; i++){
        for(int node = 0; node<V; node++){
            for(auto e : graph[node]){
                int adjnode = e.first;
                int weight = e.second;

                if(dist[node] != INT_MAX && dist[node] + weight < dist[adjnode]){
                    dist[adjnode] = dist[node] + weight;
                }
            }
        }
    }
}

int main(){
    int V = 8; // Number of vertices

    // Define the graph as an adjacency matrix
    vector<vector<int>> graph = {
        {0, 2, 1, 3, 0, 0, 0, 0},
        {0, 0, 0, 0, 2, 3, 0, 0},
        {0, 0, 0, 0, 4, 1, 0, 0},
        {0, 0, 0, 0, 0, 2, 3, 0},
        {0, 0, 0, 0, 0, 0, 0, 5},
        {0, 0, 0, 0, 0, 0, 0, 4},
        {0, 0, 0, 0, 0, 0, 0, 2},
        {0, 0, 0, 0, 0, 0, 0, 0}
    };

    multistage(graph, V);
   
    
    return 0;
}