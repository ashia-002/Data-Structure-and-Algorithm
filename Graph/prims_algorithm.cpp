#include <bits/stdc++.h>
using namespace std;

void prims( vector<vector<pair<int, int>>> &graph, int V){
//?Format: (weight, vertex)
    priority_queue< pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;

    vector<bool> inMST(V, false); // To keep track of vertices included in the MST
    vector<int> key(V, INT_MAX); // Stores the minimum edge weights for vertices (initialized to infinity)
    vector<int> parent(V, -1);  // To store the parent of each vertex in the MST

    key[0] = 0;  // Start with vertex 0, setting its key to 0
    pq.push({0, 0});  // Push (weight, vertex) for the starting vertex

    //?key[startVertex] = 0; // Start with the specified startVertex
    //?pq.push({0, startVertex}); // Push (weight, vertex)

    while(!pq.empty()){
        int currentnode = pq.top().second;
        pq.pop();

        if(inMST[currentnode]) continue; // If the vertex is already included in the MST, skip it

        inMST[currentnode] = true;// Mark the vertex as included in the MST
    // Iterate through the adjacent vertices of current vertex
        for(auto e : graph[currentnode]){
            int adjnode = e.first;
            int weight = e.second;
// If the vertex `v` is not in the MST AND edge weight is smaller than the current key
            if(!inMST[adjnode] && weight < key[adjnode]){
                key[adjnode] = weight;            // Update the key of vertex `adjvertex
                pq.push({key[adjnode], adjnode}); // Push the updated vertex into the priority queue
                parent[adjnode] = currentnode;// Update the parent of curr to adj`
            }
        }
    }

    printf("Edge \tWeight\n");
    int totalWeight = 0; // Initialize sum of weights
    for (int i = 1; i < V; i++) {
        if (parent[i] != -1) { // Include all edges in the MST
            cout<< parent[i] << " - "<<  i << " \t"<< key[i]<<endl;
            totalWeight += key[i]; // Add weight to the total
        }
    }

    // Print the total weight of the MST
    printf("Total weight of MST: %d\n", totalWeight);


}

int main() {
    int V = 5; // Number of vertices

    // Define the graph as an adjacency list
    // Each vertex has a list of pairs (adjacent_vertex, weight)
    vector<vector<pair<int, int>>> graph(V);

    // Add edges to the graph
    graph[0].push_back({1, 2});
    graph[0].push_back({3, 6});
    graph[1].push_back({0, 2});
    graph[1].push_back({2, 3});
    graph[1].push_back({3, 8});
    graph[1].push_back({4, 5});
    graph[2].push_back({1, 3});
    graph[2].push_back({4, 7});
    graph[3].push_back({0, 6});
    graph[3].push_back({1, 8});
    graph[4].push_back({1, 5});
    graph[4].push_back({2, 7});

    // Call Prim's Algorithm
    prims(graph, V);

    return 0;
}