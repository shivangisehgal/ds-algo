//OPTIMAL - 1
//If any node in a path is unsafe, its parent would also be unsafe.
//an unsafe node is a node, that does not lead to terminating node, ie, an unsafe node is a node which is part of a cycle.
//also, we are going all of the paths for a node, and only in case all of them return false (ie, don't have a cycle), are we storing the node in our answer and return false.

//TC: O(N + E)
//SC: O(N)
class Solution {
  public:
  
    bool dfs(int node, vector<bool>& visited, vector<bool>& path, vector<bool>& ans, vector<int>* adj)
    {
        if (visited[node] == false)
        {
            visited[node] = true;
            path[node] = true;
    
            for (int neighbour : adj[node])
            {
                if (dfs(neighbour, visited, path, ans, adj))
                    return true;
            }
    
            path[node] = false;
        }
        else if (path[node] == true)
            return true;
    
        ans[node] = true;
        return false;
    }
    
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        
        vector<bool> visited(V, false);
        vector<bool> path(V, false);
        vector<bool> v(V, false);
        vector<int> ans;
        
        for(int i = 0; i < V; i++)
        {
            if(!visited[i])
            {
                bool moveOnPath = dfs(i, visited, path, v, adj);
            }
        }
        
        for(int i = 0; i < V; i++)
        {
            if(v[i])
                ans.push_back(i);
        }
        
        return ans;
    }
};

//OPTIMAL - 2
//If you note that, we are only backtracking (or un-visiting 'path') only if happen to get all false.
//hence, at the end, only those nodes which are part of cycles will be marked as true.
//hence, our answer would be all those nodes for which path[node] = false. no need of extra pointer
class Solution {
public:
    
    bool dfs(int node, vector<bool>& visited, vector<bool>& path, vector<vector<int>>& adj)
    {
        if (visited[node] == false)
        {
            visited[node] = true;
            path[node] = true;
    
            for (int neighbour : adj[node])
            {
                if (dfs(neighbour, visited, path, adj))
                    return true;
            }
    
            path[node] = false;
        }
        else if (path[node] == true)
            return true;
    
        return false;
    }
    
    
    vector<int> eventualSafeNodes(vector<vector<int>>& adj) {
        
        int V = adj.size();
        
        vector<bool> visited(V, false);
        vector<bool> path(V, false);
        vector<int> ans;
        
        for(int i = 0; i < V; i++)
        {
            if(!visited[i])
            {
                bool moveOnPath = dfs(i, visited, path, adj);
            }
        }
        
        for(int i = 0; i < V; i++)
        {
            if(path[i] == false)
                ans.push_back(i);
        }
        
        return ans;
    }
};

//OPTIMAL-3
class Solution {
public:
    
    bool dfs(int node, vector<int>& visited, vector<vector<int>>& adj)
    {
        if (visited[node] == -1) //not visited
        {
            visited[node] = 1; //visited and in path
    
            for (int neighbour : adj[node])
            {
                if (dfs(neighbour, visited, adj))
                    return true;
            }
    
            visited[node] = 0; //visited but not in path
        }
        else if (visited[node] == 1) //visited and in path
            return true;
    
        return false;
    }
    
    
    vector<int> eventualSafeNodes(vector<vector<int>>& adj) {
        
        int V = adj.size();
        
        vector<int> visited(V, -1);
        vector<int> ans;
        
        for(int i = 0; i < V; i++)
        {
            if(visited[i] == -1)
            {
                bool moveOnPath = dfs(i, visited, adj);
            }
        }
        
        for(int i = 0; i < V; i++)
        {
            if(visited[i] == -1 || visited[i] == 0)
                ans.push_back(i);
        }
        
        return ans;
    }
};
