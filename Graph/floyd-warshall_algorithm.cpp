//All pair shortest path algorithm
#include<bits/stdc++.h>
using namespace std;

const int INF = INT_MAX;

void floydWarshall(int dist[][], int V) {
    // Apply Floyd-Warshall algorithm
    for (int k = 0; k < V; k++) { // Intermediate vertex
        for (int i = 0; i < V; i++) { // Start vertex
            for (int j = 0; j < V; j++) { // End vertex
                if (dist[i][k] != INF && dist[k][j] != INF) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
}

int main() {
    int V;
    cout << "Enter the number of vertices: ";
    cin >> V;

    // Initialize the distance matrix with INF
    // vector<vector<int>> dist[V];
    int dist[V][V];

    // Input edge weights
    cout << "Enter the adjacency matrix (use " << INF << " for no edge):" << endl;
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cin >> dist[i][j];
        }
    }

    // Apply Floyd-Warshall algorithm
    floydWarshall(dist, V);

    // Output the shortest path distances
    cout << "The shortest path matrix is:" << endl;
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF)
                cout << "INF" << " ";
            else
                cout << dist[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}