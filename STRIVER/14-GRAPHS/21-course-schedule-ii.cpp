//topo sorting (or return empty array if not possible)

//Method 1 - BFS

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<vector<int>> adjList(numCourses);

        for(int i = 0; i < prerequisites.size(); i++)
        {
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];

            adjList[u].push_back(v);
        }

        vector<int> inDegree(numCourses, 0);
        queue<int> q;

        for(int node = 0; node < numCourses; node++)
        {
            for(int neighbour : adjList[node])
                inDegree[neighbour]++;
        }

        for(int node = 0; node < numCourses; node++)
        {
            if(inDegree[node] == 0)
                q.push(node);
        }

        vector<int> topoSort;

        while(!q.empty())
        {
            int node = q.front();
            q.pop();

            topoSort.push_back(node);

            for(int neighbour : adjList[node])
            {
                inDegree[neighbour]--;

                if(inDegree[neighbour] == 0)
                    q.push(neighbour);
            }
        }

        if(topoSort.size() < numCourses)
          return {}; //cycle exists, cannot finish courses

        reverse(topoSort.begin(), topoSort.end()); //if you need to perform b before taking a (a -> b), then b should be completed first, ie, do the most dependent course first.
        
        return topoSort;
    }
};


//Method 2 - topo sorting (or return empty array if not possible), DFS

class Solution {
public:
    
    bool dfs(int node, vector<int>& visPath, vector<int>& ans, vector<vector<int>>& adjList)
    {
        if(visPath[node] == -1)
        {
            visPath[node] = 1;

            for(int neighbour : adjList[node])
            {
                if(dfs(neighbour, visPath, ans, adjList) == true) //cycle exists
                    return true;
            }

            ans.push_back(node); //push the node, after pushing all children
            
            visPath[node] = 0; //backtrack
             
        }
        
        //has been visited AND PATH EXISTS
        else if(visPath[node] == 1)
            return true;

        return false;
    }
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<vector<int>> adjList(numCourses);

        for(int i = 0; i < prerequisites.size(); i++)
        {
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];

            adjList[u].push_back(v);
        }

        vector<int> visPath(numCourses, -1); 
        vector<int> ans; //no need of using stack, since we anyway have to return the reverse order of stack.
        
        for(int i = 0; i < numCourses; i++)
        {
            if(visPath[i] == -1)
            {
                if(dfs(i, visPath, ans, adjList) == true) //cycle exists, cannot finsh courses
                    return {};
            }
        }
        
        return ans;
    }
};
