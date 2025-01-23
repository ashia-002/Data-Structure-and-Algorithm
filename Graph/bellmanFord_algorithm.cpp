#include<bits/stdc++.h>
using namespace std;

void bellmanFord(vector<vector<pair<int, int>>> &graph, int V, int src) {
    // Distance array to store the shortest distance to each vertex
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;

    // Relax all edges (V-1) times
    for (int i = 1; i <= V - 1; i++) {
        for (int node = 0; node < V; node++) {
            for (auto edge : graph[node]) {
                int adjnode = edge.first;
                int weight = edge.second;

                // Relaxation step
                if (dist[node] != INT_MAX && dist[node] + weight < dist[adjnode]) {
                    dist[adjnode] = dist[node] + weight;
                }
            }
        }
    }

    // Check for negative weight cycles
    for (int node = 0; node < V; node++) {
        for (auto edge : graph[node]) {
            int adjnode = edge.first;
            int weight = edge.second;

            if (dist[node] != INT_MAX && dist[node] + weight < dist[adjnode]) {
                cout << "Graph contains a negative weight cycle.\n";
                return;
            }
        }
    }

    // Print the shortest distances
    cout << "Vertex\tDistance from Source\n";
    for (int i = 0; i < V; i++) {
        cout << i << "\t" << dist[i] << "\n";
    }
}


int main() {
    int V = 5; // Number of vertices

    vector<vector<pair<int, int>>> graph(V);
    graph[0].push_back({1, 2});
    graph[0].push_back({3, 6});
    graph[1].push_back({2, 3});
    graph[1].push_back({3, 8});
    graph[1].push_back({4, 5});
    graph[2].push_back({4, 7});

    bellmanFord(graph, V, 0);
    //dijkstra(graph, V, 0);
    //floydWarshall(graph, V);
    //multistageGraph(graph, 4, V);
    //primsAlgorithm(graph, V);

    return 0;
}


// #include <bits/stdc++.h>
// using namespace std;

// #define INF INT_MAX

// // Function to implement the Bellman-Ford algorithm
// tuple<vector<int>, vector<int>> BellmanFord(int V, vector<vector<int>> E, int S) {
//     // Step 2: Initialize distance[] to ∞ for all vertices except source
//     vector<int> distance(V, INF);
//     vector<int> predecessor(V, -1); // Step 3: Initialize predecessor[] to null (-1)
    
//     distance[S] = 0; // Distance from source to itself is always 0

//     // Step 4: Relax edges |V| - 1 times
//     for (int i = 1; i < V; i++) {
//         for (const auto& edge : E) { // Step 5: For each edge (u, v)
//             int u = edge[0]; // Start vertex
//             int v = edge[1]; // End vertex
//             int weight = edge[2]; // Weight of the edge

//             // Step 6: Relaxation condition
//             if (distance[u] != INF && distance[u] + weight < distance[v]) {
//                 distance[v] = distance[u] + weight; // Step 7: Update distance
//                 predecessor[v] = u; // Step 8: Update predecessor
//             }
//         }
//     }

//     // Step 9: Check for negative-weight cycles
//     for (const auto& edge : E) {
//         int u = edge[0];
//         int v = edge[1];
//         int weight = edge[2];
//         if (distance[u] != INF && distance[u] + weight < distance[v]) {
//             cout << "Graph contains a negative-weight cycle" << endl; // Step 11
//             return make_tuple(vector<int>(), vector<int>()); // Return empty vectors on cycle detection
//         }
//     }

//     return make_tuple(distance, predecessor); // Step 13: Return distance[] and predecessor[]
// }

// int main() {
//     int V = 5; // Number of vertices
//     vector<vector<int>> edges = {
//         {0, 1, 4}, // Edge from vertex 0 to 1 with weight 4
//         {0, 2, 5}, // Edge from vertex 0 to 2 with weight 5
//         {1, 2, -3}, // Edge from vertex 1 to 2 with weight -3
//         {1, 3, 6}, // Edge from vertex 1 to 3 with weight 6
//         {2, 4, 2}, // Edge from vertex 2 to 4 with weight 2
//         {3, 4, 1}  // Edge from vertex 3 to 4 with weight 1
//     };

//     int source = 0; // Source vertex

//     auto [distances, predecessors] = BellmanFord(V, edges, source);

//     // Printing the shortest distances from the source
//     for (int i = 0; i < V; i++) {
//         if (distances[i] == INF) {
//             cout << "No path from node " << source << " to node " << i << "." << endl;
//         } else {
//             cout << "Shortest distance from node " << source << " to node " << i << " is " << distances[i] << "." << endl;
//         }
//     }

//     // Printing the predecessors for path reconstruction
//     cout << "Predecessors for the shortest paths:" << endl;
//     for (int i = 0; i < V; i++) {
//         if (predecessors[i] != -1) {
//             cout << "Node " << i << " is reached from node " << predecessors[i] << "." << endl;
//         } else {
//             cout << "Node " << i << " has no predecessor." << endl;
//         }
//     }

//     return 0;
// }
