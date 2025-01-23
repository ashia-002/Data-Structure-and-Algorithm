#include <bits/stdc++.h>
using namespace std;

struct Edges
{
    /* data */
    int src, dest, weight;
};

void bellmanFord(int V, int E, vector<Edges> &edges, int source){
    vector<int> dist(V, INT_MAX);
    dist[source] = 0;

    for(int i = 0; i < V-1; i++){
        for(auto e : edges){
            if(dist[e.src] != INT_MAX && dist[e.dest] > dist[e.src] + e.weight){
                dist[e.dest] = dist[e.src] + e.weight;
            }
        }
    }

    //check for negative cycle
    for(auto e : edges){
        if(dist[e.src] != INT_MAX && dist[e.dest] > dist[e.src] + e.weight){
            cout<<"Negative cycle detected"<<endl;
            return;
        }
    }

    //stortenst distance
    for(int i = 0; i<V; i++){
        cout<<"the distance from "<<source<<" to "<<i<<" : "<<dist[i]<<endl;
    }
}

int main(){
    int E = 8, V = 5, source = 0;

    vector<Edges> edges = {
        {0, 1, -1}, {0, 2, 4}, {1, 2, 3}, {1, 3, 2}, {1, 4, 2},
        {3, 2, 5}, {3, 1, 1}, {4, 3, -3}
    };

    bellmanFord(V, E, edges, source);


    return 0;
}
