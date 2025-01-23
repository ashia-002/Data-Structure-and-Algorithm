// CPP program to find shortest distance
// in a multistage graph.

#include <bits/stdc++.h>
using namespace std;

const int INF = INT_MAX;

// Function to find the shortest path in a multi-stage graph
int shortestPathMultiStageGraph(vector<vector<int>>& graph, int stages) {
    int V = graph.size(); // Number of vertices in the graph
    vector<int> cost(V, INF); // Array to store the minimum cost to reach the sink
    vector<int> path(V, -1);  // Array to store the path from each node

    // Initialize the cost of the sink node (last node) to 0
    cost[V - 1] = 0;

    // Calculate the minimum cost for each node starting from the last node
    for (int i = V - 2; i >= 0; i--) {
        for (int j = i + 1; j < V; j++) {
            if (graph[i][j] != INF && cost[j] != INF) {
                int newCost = graph[i][j] + cost[j];
                if (newCost < cost[i]) {
                    cost[i] = newCost;
                    path[i] = j;
                }
            }
        }
    }

    // Print the shortest path from source (0) to sink (V-1)
    cout << "Shortest path from source to sink: ";
    int node = 0;
    while (node != -1) {
        cout << node << " ";
        node = path[node];
    }
    cout << "\nMinimum cost from source to sink: " << cost[0] << endl;

    return cost[0];
}

int main() {
    int V;
    cout << "Enter the number of vertices in the graph: ";
    cin >> V;

    // Initialize the graph with INF
    vector<vector<int>> graph(V, vector<int>(V, INF));

    int edges;
    cout << "Enter the number of edges: ";
    cin >> edges;
    cout << "Enter each edge in the format 'u v cost':\n";
    for (int i = 0; i < edges; i++) {
        int u, v, cost;
        cin >> u >> v >> cost;
        graph[u][v] = cost; // Set the cost for the directed edge u -> v
    }

    int stages;
    cout << "Enter the number of stages: ";
    cin >> stages;

    shortestPathMultiStageGraph(graph, stages);

    return 0;
}
