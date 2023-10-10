//Refer HW notes
//TC: O(V^3)
//SC: O(V^2)

class Solution {
public:
    
    void bellman_ford(vector<vector<int>>& matrix, int n)
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if (i == j) 
                    matrix[i][j] = 0;
            }
        }
        
        for(int via = 0; via < n; via++)
        {
            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < n; j++)
                {
                    matrix[i][j] = min(matrix[i][j], matrix[i][via] + matrix[via][j]);
                }
            }
        }
        
    }
    
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        
        vector<vector<int>> adjMatrix(n, vector<int>(n, 1e9));
        
        for(auto edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            
            adjMatrix[u][v] = wt;
            adjMatrix[v][u] = wt;
        }
        
        bellman_ford(adjMatrix, n);
        
        int maxReachableCities = n;
        int ansCity = -1;
        
        for(int i = 0; i < n; i++)
        {
            int reachableCityCount = 0;
            
            for(int j = 0; j < n; j++)
            {
                if(j != i && adjMatrix[i][j] <= distanceThreshold)
                    reachableCityCount++;
            }
            
            if(reachableCityCount <= maxReachableCities)
            {
                maxReachableCities = reachableCityCount;
                ansCity = i;
            }
        }
        
        return ansCity;
    }
};
