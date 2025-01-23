/*lets say a graph is given that have 10 nodes and three components
1,2,3,4  5,6,7 8,9  10
now if we start traversal we cant traverse the whole graph from a single
point. so first we take an array and fill it with 0s
Initialize vis[]=>0
for(i=1 -> 10){
    if(vis[i]==0){
        traversal(i)
    }
}*/