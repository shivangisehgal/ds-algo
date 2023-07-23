https://takeuforward.org/graph/introduction-to-graph/

//Codestudio:

int countingGraphs(int n)
{
    //max edges = nC2
    int maxEdges = (n * (n - 1)) / 2;
    
    //for each edge, we can have two options - euthe have or not have
    //so each edge change, can result in unique graph
    //2*2*2.......maxEdges times

    return pow(2, maxEdges);
}
