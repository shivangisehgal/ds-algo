//Create an indegree array/map
//Push all nodes in the queue with indegree 0, these are the nodes which are not any one's neighbour (child)
//Now, the first in our queue, would come first in our answer,
// once we have stored it in our answer, we will decrease the indegree of all of its children by 1, because their parent is gone.
//If any of the child's indegree becomes 0 now, then it would go first in topo sort, hence push in queue.

//TC: O(N + E)
//SC: O(N)

#include <queue>


vector<int> topologicalSort(vector<vector<int>> &graph, int edges, int nodes) {
    // Write your code here!
    vector<vector<int>> adjList(nodes);

    for(int i = 0; i < edges; i++)
    {
        int u = graph[i][0];
        int v = graph[i][1];

        adjList[u].push_back(v);
    }

    vector<int> inDegree(nodes, 0);
    queue<int> q;

    for(int node = 0; node < nodes; node++)
    {
        for(int neighbour : adjList[node])
            inDegree[neighbour]++;
    }

    for(int node = 0; node < nodes; node++)
    {
        if(inDegree[node] == 0)
            q.push(node);
    }

    vector<int> ans;

    while(!q.empty())
    {
        int node = q.front();
        q.pop();

        ans.push_back(node);

        for(int neighbour : adjList[node])
        {
            inDegree[neighbour]--;
            
            if(inDegree[neighbour] == 0)
                q.push(neighbour);
        }
    }
    
    return ans;
}
