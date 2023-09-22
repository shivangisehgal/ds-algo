//We have to print the shortest path.
//Now, for printing the shorest path for each node, 
//if we know the shortest path ofthe parent (only that parent with whom it will have the shortest path), 
//then, we can simply back track for each parent node right? || 
//ie. print node -> print its parent with which it had shortest path ->  print its parent's parent with which its parent had shortest path and so on
//thus, we can create a parent array, which eventually will store the parent with whom a node will have the shortest path.

//TC: O(ElogV + V)
//SC: O(V)

//gfg
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        
        vector<vector<pair<int,int>>> adj(n + 1);

        for(int i = 0; i < m; i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
    
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }
    
        vector<int> dist(n + 1, INT_MAX);
        vector<int> parent(n + 1);
    
        for(int i = 0; i < n + 1; i++)
            parent[i] = i;
            
        int source = 1;
        
        dist[source] = 0;
    
        set<pair<int,int>> orderedSet;
    
        orderedSet.insert({0, source});
    
        while(!orderedSet.empty())
        {
            auto it = *(orderedSet.begin());
            orderedSet.erase(it);
    
            int node = it.second;
            int parentDist = it.first;
    
            for(auto adjIt : adj[node])
            {
                int neighbour = adjIt.first;
                int wt = adjIt.second;
    
                if(dist[neighbour] > parentDist + wt)
                {
                    if(dist[neighbour] != INT_MAX)
                        orderedSet.erase({dist[neighbour], neighbour});
                
                    dist[neighbour] = parentDist + wt;
                    orderedSet.insert({parentDist + wt, neighbour});
                    parent[neighbour] = node;
                } 
            }
        }
        
        vector<int> path;
        
        int node = n;
        
        while(parent[node] != node)
        {
            path.push_back(node);
            node = parent[node];
        }
        
        if(node != 1)
            return {-1};
            
        path.push_back(1);
        
        reverse(path.begin(), path.end());
        
        return path;
    }
};

