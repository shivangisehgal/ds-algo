//https://takeuforward.org/graph/graph-representation-in-c/ 

//input is always:
//n (= no. of nodes), m (= no. of edges)
//m lines describing the nodes in between which there is an edge
//for eg,

//n = 5, m = 6
// 2 1
// 1 3
// 2 4
// 3 4
// 2 5
// 4 5

//graph will be: https://lh3.googleusercontent.com/YhQ-8oPpVrlHZ0CuBWTcFLdDptuTmSmtNBhMPMtSfLc3-Z21zD0_rNWN8_M_4pI572jhIIrxLYZTlo8w0PbQEdn-M8HSkKAneSvlG35UW1-KAitO2XrxBp7j2l7fRs3aJtJRF4m6BJM8A7nch5M0keo


//There are two ways to store the graph info
//1. Matrix (Adjacency matrix) or 2. List (Adjacency List)

//1. Adjacency Matrix

//If 1-based nodes, create a matrix adj[n + 1][n + 1].
//Mark the cell having nodes as row,col and col,row = 1;
//https://lh5.googleusercontent.com/8EyiYvV3B3kfRvFjIPoUIsiYfyH6wegQqcjzvhMftBYxfgFrmcPvx5YqfKHuIrSO46XUD6lop9QsaWBwla0GFB5K57ilOgqP5TNs0LAHsPPFI8aVssD-qv_yr_f9dIJHnKlsCtIeq206Qvql923ckCk
//SC: O(N*N) => costly

int main()
{
    int n, m;
    
    cin >> n >> m;
    int adj[n + 1][n + 1];
    
    int u, v;
    
    for(int i = 0; i < m; i++)
    {
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
    return 0;
}


//2. Adjacency List
//create a list containing all nodes. For each node, there is a list associated with it.
//So, it is like, array of vector<int>
//The size of a vector is 0 by default.

//Hence, each element of the list will store all the neighbour nodes associated with it, i.e., form an edge with it.
// https://lh6.googleusercontent.com/4tesls8e58HF6qAqwEf9S-ZmsgmB9l0VcJR9VL0JG9rBzYwuWgW342wWkb7vQm3E6KP5-bGsTgVvAv_Y0hTSu3AA9f4Og76RjXW8W2dM6esXc4aCy6ekmXFe_u5RnwQQMihbqp9J3iJ0MscUlrZFJKg
//for undirected graph: O(2E), for directed graph: O(E)

int main()
{
    int n, m;
    
    cin >> n >> m;
    vector<int> adj[n + 1];
    
    int u, v;
    
    for(int i = 0; i < m; i++)
    {
        cin >> u >> v;
    
        adj[u].push_back(v);
        
        //only for undiirected graph
        adj[v].push_back(u);
    }
    return 0;
}

//For weighted graphs, 
//store the weight instead of 1 in the matrix
//use vector<pair<int, int>> instead of vector<int>  in the list.

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
