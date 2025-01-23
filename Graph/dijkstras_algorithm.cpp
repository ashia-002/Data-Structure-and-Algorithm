//Can be implemented using three method
/*-->Priority Queue
  -->Queue
  -->Set
  */


//Solving priority Queue bc we always need the shortest distance
#include<bits/stdc++.h>
using namespace std;

vector<int> dijkstra(int V, vector<vector<int>> adj[], int S) {
    // priority_queue to store the (weight, node)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    // array to store the minimum weight for the node (where the index represents the node)
    vector<int> dist(V, INT_MAX);
   

    dist[S] = 0; // setting the source node's weight to 0
    pq.push({0, S}); // pushing into the queue the weight and the node

    while (!pq.empty()) {
        int weight = pq.top().first;//1  // taking the weight of the node from the top
        int node = pq.top().second;//1 // taking the node from the top
        pq.pop();

        // processing all adjacent nodes of the current node
        for (auto it : adj[node]) {
            int adjNode = it[0]; //2
            int adjweight = it[1]; //3

            // if a shorter path to the adjNode is found, update the dist and push it into the queue
            if (weight + adjweight < dist[adjNode]) {
                dist[adjNode] = weight + adjweight;
                pq.push({dist[adjNode], adjNode});
            }
        }
    } 
    return dist;
}

int main() {
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
