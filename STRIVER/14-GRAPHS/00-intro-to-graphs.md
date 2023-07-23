https://takeuforward.org/graph/introduction-to-graph/

Codestudio:

int countingGraphs(int n)
{
    //max edges = nC2
    int maxEdges = (n * (n - 1)) / 2;
    
    //for each edge, we can have two options - euthe have or not have
    //so each edge change, can result in unique graph
    //2*2*2.......maxEdges times

    return pow(2, maxEdges);
}

Connected Components - need for visited array
https://takeuforward.org/graph/connected-components-in-graphs/

for(int i = 0; i < n; i++)
{
    if(!visited[i])
        traversal(i); //traversal is such a function that is designed to traverse through connected nodes, and marking visited[i] in case visited.
}
