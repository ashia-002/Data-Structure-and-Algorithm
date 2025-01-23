#include <stdio.h>
#include <limits.h>

// Number of vertices in the graph
#define V 4

// Function to find the shortest path in a multistage graph
void multistageGraph(int graph[V][V], int stages) {
    int cost[V];         // Minimum cost from each vertex to the destination
    int path[V];         // Path to reconstruct the solution
    int destination = V -1 ; // Destination vertex (last stage)

    // Initialize cost of the destination vertex to 0
    cost[destination] = 0;
    path[destination] = destination;

    // Compute the cost for all vertices from (V-2) to 0
    for (int i = V - 2; i >= 0; i--) {
        int minCost = INT_MAX;

        // Check all possible vertices connected to vertex i
        for (int j = i + 1; j < V; j++) {
            if (graph[i][j] != 0 && cost[j] + graph[i][j] < minCost) {
                minCost = cost[j] + graph[i][j];
                path[i] = j;
            }
        }

        cost[i] = minCost;
    }

    // Print the shortest cost and path
    printf("Minimum cost: %d\n", cost[0]);

    printf("Path: ");
    int current = 0;
    while (current != destination) {
        printf("%d -> ", current);
        current = path[current];
    }
    printf("%d\n", destination);
}

// Main function
int main() {
    // Multistage graph represented as an adjacency matrix
    // 0 indicates no direct edge
    int graph[V][V] = {
        {0, 2, 1, 0},
        {0, 0, 0, 3},
        {0, 0, 0, 1},
        {0, 0, 0, 0}
    };

    int stages = 3; // Number of stages in the graph

    multistageGraph(graph, 4);

    return 0;
}