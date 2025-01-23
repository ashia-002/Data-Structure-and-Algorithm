#include<bits/stdc++.h>
using namespace std;

const int INF = INT_MAX; 

void floydWarshall(vector<vector<int>>& dist, int V) {
    // Outer loop: iterate through each vertex as an intermediate point 'k'
    for (int k = 0; k < V; k++) {
        // Loop through each pair of vertices (i, j)
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                // Check if there is a path from 'i' to 'k' and from 'k' to 'j'
                if (dist[i][k] != INF && dist[k][j] != INF) {
                    // Update the distance from 'i' to 'j' to be the minimum of:
                    // 1. The current distance from 'i' to 'j'
                    // 2. The distance from 'i' to 'k' + distance from 'k' to 'j'
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
}

int main() {
    int size, edges;                    // n: number of locations, m: number of connections
    string location;              // Variable to store user input locations
    unordered_map<string, int> locationMap; // Map to store location names with indices
    vector<string> locations;     // Vector to store location names in order

    // Input location names
    cout << "Enter location names (type 'END' to stop):\n";
    while (cin >> location) {     
        if (location == "END") break;          // Stop input when "END" is entered
        locationMap[location] = locations.size(); // Map location to current index
        locations.push_back(location);          // Add location to vector
    }
    size = locations.size();                      // Set number of locations

    // Initialize the distance matrix with infinity (INF)
    vector<vector<int>> dist(size, vector<int>(size, INF));
    for (int i = 0; i < size; i++) {               // Set distance to self as 0
        dist[i][i] = 0;
    }

    // Input the number of connections
    cout << "Enter the number of connections (edges) between locations: ";
    cin >> edges;
    cout << "Enter distance(km) between two location 'start_location end_location distance(km)':\n";

    // Input each connection and its distance
    for (int i = 0; i < edges; i++) {
        string start, end;                      // Start and end locations
        int weight;                             // Distance between them
        cin >> start >> end >> weight;          // Input each connection
        int u = locationMap[start];             // Get index for start location
        int v = locationMap[end];               // Get index for end location
        dist[u][v] = weight;                    // Set the distance in matrix
    }

    // Perform Floyd-Warshall algorithm to find shortest paths
    floydWarshall(dist, size);

    // Query for the shortest path between two specific locations
    string loc1, loc2;
    cout << "\nEnter two locations to find the shortest path between them: ";
    cin >> loc1 >> loc2;

    // Check if both locations exist in the map
    if (locationMap.find(loc1) != locationMap.end() && locationMap.find(loc2) != locationMap.end()) {
        int idx1 = locationMap[loc1];           // Get index for first location
        int idx2 = locationMap[loc2];           // Get index for second location
        int distance = dist[idx1][idx2];        // Get shortest distance from matrix

        // Display the shortest distance
        cout << "\nThe shortest distance between " << loc1 << " and " << loc2 << " is: ";
        if (distance == INF)
            cout << "No path exists.\n";        // No path if distance is infinity
        else
            cout << distance << endl;
    } else {
        cout << "One or both of the locations are not in the list.\n"; // Invalid locations
    }

    return 0;
}