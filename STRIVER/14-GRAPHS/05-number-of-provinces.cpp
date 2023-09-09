//count number of components in graph
class Solution {
public:
    //basically, count number of components (separate graphs) in a graph
    void dfs(int v, vector<vector<int>>& adjList, vector<int>& visited, vector<int>& componentDFS)
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
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        //isConnected is the adjacency matrix
        //perform traversal.
        
        
        int n = isConnected.size();
        vector<vector<int>> adjList(n);
        
        for(int i = 0; i < isConnected.size(); i++)
        {
            for(int j = 0; j < isConnected[0].size(); j++)
            {
                if(isConnected[i][j] == 1 && i != j)
                {
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }
        
        vector<int> visited(n, 0);
        
        int compCount = 0;
        
        for(int i = 0; i < n; i++)
        {
            if(!visited[i])
            {
                compCount++;
                vector<int> componentDFS; //stores the entire dfs of a graph
                dfs(i, adjList, visited, componentDFS);
            }
        }
        
        return compCount;
    }
};
