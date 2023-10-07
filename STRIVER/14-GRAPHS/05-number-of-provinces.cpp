//count number of components in graph in adjacency matrix

class Solution {
public:
    //basically, count number of components (separate graphs) in a graph
    
    void dfs(int v, vector<vector<int>>& adjMatrix, vector<int>& visited)
    {
        if(!visited[v])
        {
            visited[v] = 1;
            
            //call DFS for each neighbour of v
            for(int possibleNeighbour = 0; possibleNeighbour < adjMatrix.size(); possibleNeighbour++)
            {
                if(adjMatrix[v][possibleNeighbour] == 1)
                    dfs(possibleNeighbour, adjMatrix, visited);
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int n = isConnected.size();
        
        vector<int> visited(n, 0);
        
        int compCount = 0;
        
        for(int i = 0; i < n; i++)
        {
            if(!visited[i])
            {
                compCount++;
                dfs(i, isConnected, visited);
            }
        }
        
        return compCount;
    }
};
