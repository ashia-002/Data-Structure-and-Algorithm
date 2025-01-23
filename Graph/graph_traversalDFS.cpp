#include<bits/stdc++.h>
using namespace std;

vector<int> dfsOfGraph(int V, vector<vector<int>>& adj){
    
}

int main(){
    int V; // Number of vertices
    cout << "Enter the number of vertices: ";
    cin >> V; //8  

    vector<vector<int>> adjList(V);

    // Taking input for each vertex's adjacency list
    for (int i = 1; i <= V; i++) {
        int numEdges;
        cout << "Enter the number of neighbors for vertex " << i << ": ";
        cin >> numEdges;

        cout << "Enter the neighbors of vertex " << i << ": ";
        for (int j = 1; j <= numEdges; j++) {
            int neighbor;
            cin >> neighbor;
            adjList[i].push_back(neighbor);
        }
    }
    return 0;
}