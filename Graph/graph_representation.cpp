#include<bits/stdc++.h>
using namespace std;

int main() {
    // n --> number of nodes, m --> number of edges
    int n, m;
    cout << "Enter number of nodes and edges: ";
    cin >> n >> m;

    // Initialize adjacency list of size n+1 (for 1-based indexing)
    vector<vector<int>> ArrayList(n+1);

    // Input the edges
    cout << "Enter the edges (u v) pairs: " << endl;
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        // Adding the edge to both nodes, since it's an undirected graph
        ArrayList[u].push_back(v);
        ArrayList[v].push_back(u);
    }

    // Print the adjacency list
    cout << "Printing the adjacency list: " << endl;
    for(int i = 1; i <= n; i++) {
        cout << "Node " << i << ": ";
        for (int j = 0; j < ArrayList[i].size(); j++) {
            cout << ArrayList[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
