/*Adjacency List:
0 -> { 3 }
1 -> { 2 0 }
2 -> { 1 3 4 }
3 -> { 2 }
4 -> { 2 5 }
5 -> { 4 8 }
6 -> { 1 7 9 }
7 -> { 6 8 }
8 -> { 5 7 }
9 -> { 6 }
so first we take an array and fill it with 0s
Initialize vis[]=>0
for(i=1 -> 10){
    if(vis[i]==0){
        traversal(i)
    }
*/

#include <bits/stdc++.h>
using namespace std;

// Time Complexity : O(N) + (2xE)
vector<int> bfsOfGraph(int V, vector<vector<int>>& adj) {
    vector<int> vist(V, 0); // Create a visited array initialized to 0
    vist[0] = 1; // Start BFS from node 0

    queue<int> q;
    q.push(0); // Start BFS from vertex 0

    vector<int> bfs;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        bfs.push_back(node);

        for (auto it : adj[node]) {
            if (!vist[it]) { // If the neighbor is not visited
                vist[it] = 1;
                q.push(it);
            }
        }
    }
    return bfs;
}

int main() {
    int V; // Number of vertices
    cout << "Enter the number of vertices: ";
    cin >> V;

    vector<vector<int>> adjList(V);

    // Taking input for each vertex's adjacency list
    for (int i = 0; i < V; i++) {
        int numEdges;
        cout << "Enter the number of neighbors for vertex " << i << ": ";
        cin >> numEdges;

        cout << "Enter the neighbors of vertex " << i << ": ";
        for (int j = 0; j < numEdges; j++) {
            int neighbor;
            cin >> neighbor;
            adjList[i].push_back(neighbor);
        }
    }

    // Perform BFS traversal
    vector<int> bfs = bfsOfGraph(V, adjList);

    // Print BFS result
    cout << "The BFS traversal list: ";
    for (int i = 0; i < bfs.size(); i++) {
        cout << bfs[i] << " ";
    }

    cout << endl;

    return 0;
}
