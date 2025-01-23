//this is using matrix or vector/list
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin>>n>>m;
    
    //?using matrix
    // int adj[n+1][m+1];
    // for(int i = 0; i<m; i++){
    //     int u, v;
    //     cin>> u >> v ; //?inputting the edges
    //     adj[u][v] = 1; //?for weighted graph instead of storing 1 u r storing the weight
    //     adj[v][u] = 1;
    // }

    //using vector to store //?for weighted graph u will store vector<pair<int,int>>
    vector<int> adj[n+1];
    for(int i = 0; i<m; i++){
        int u, v;
        cin>> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }



    return 0;
}
