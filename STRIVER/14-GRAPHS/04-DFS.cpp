//not on LC
//TC: O(N + 2E) //N for each dfs function call from main, for loop contributing to the sum of degrees.
//SC: O(N) + O(N) + O(N)

void dfs(int v, vector<int> adjList[], int visited[], vector<int>& componentDFS)
{
    if(!visited[v])
    {
        visited[v] = 1;
        componentDFS.push_back(v);
        
        //call DFS for each neighbour of v
        for(auto neighbour : adjList[v])
            dfs(neighbour, adjList, visited, componentDFS);
    }
}

vector<vector<int>> depthFirstSearch(int n, int m, vector<vector<int>> &edges)
{
    // Write your code here
    vector<int> adjList[n];

    for(int i = 0; i < m; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    vector<vector<int>> ans; //stores dfs of all separated graphs (components)
    int visited[n] = {0};

    for(int i = 0; i < n; i++) //this loop if for unconnected/separated graphs (components)
    {
        if(!visited[i])
        {
            vector<int> componentDFS; //stores the entire dfs of a graph
            dfs(i, adjList, visited, componentDFS);
            ans.push_back(componentDFS);
        }
    }

    return ans;
    
}
