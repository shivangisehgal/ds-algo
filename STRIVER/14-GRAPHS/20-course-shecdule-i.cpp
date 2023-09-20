//METHOD 1 - cycle detection in directed graph using DFS

class Solution {
public:
    
    bool dfs(int node, vector<int>& visitedPath, vector<vector<int>>& adjList)
    {
        if(visitedPath[node] == -1) //not visited
        {
            visitedPath[node] = 1; //visited and now in path 
            
            for(int neighbour : adjList[node])
            {
                if(dfs(neighbour, visitedPath, adjList) == true) //if cycle exists for neighbour
                    return true; 
            }
            
            visitedPath[node] = 0; //visited and but not in path
        }
        
        else if(visitedPath[node] == 1) //visited and in path already
        {
            return true; //cycle exists
        }
        
        return false;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<vector<int>> adjList(numCourses);
        
        for(int i = 0; i < prerequisites.size(); i++)
        {
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            
            adjList[u].push_back(v);
        }
        
        vector<int> visitedPath(numCourses, -1);
        
        for(int node = 0; node < numCourses; node++)
        {
            if(visitedPath[node] == -1)
            {
                if(dfs(node, visitedPath, adjList) == true)
                    return false; //cannot finish all courses
            }
        }
        
        return true;
    }
};

//Method 2 - Cycle detection in dir cycle using BFS (topo sort)

class Solution {
public:
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<vector<int>> adjList(numCourses);
        
        for(int i = 0; i < prerequisites.size(); i++)
        {
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            
            adjList[u].push_back(v);
        }
        
        vector<int> indegree(numCourses, 0);
        queue<int> q;
        
        for(int node = 0; node < numCourses; node++)
        {
            for(int neighbour : adjList[node])
                indegree[neighbour]++;
        }
        
        for(int node = 0; node < numCourses; node++)
        {
            if(indegree[node] == 0)
            {
                q.push(node);
            }
        }
        
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            
            for(int neighbour : adjList[node])
            {
                indegree[neighbour]--;
                
                if(indegree[neighbour] == 0)
                    q.push(neighbour);
            }
        }
        
         for(int node = 0; node < numCourses; node++)
        {
            if(indegree[node] > 0)
            {
                return false; //cannot finish courses
            }
        }
        
        return true;
    }
};
