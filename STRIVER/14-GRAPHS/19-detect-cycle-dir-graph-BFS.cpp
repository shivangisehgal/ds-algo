//topo sort is applicable for DAGs
//If we have a cycle in our graph, to enter through any node/push any node in our answer of topo sort, we would need its inDegree to be 0
//Which it can never be, since it is stuck in a cycle
//Hence, if topo sort answer vector's size != n, or after doing all the bfs traversal, we have any nodes with indeg > 0, that means there was a cycle.


//TC: O(N + E)
//SC: O(N)

//M - 1

#include <queue>

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  // Write your code here.

  vector<vector<int>> adjList(n + 1); //question has 1-based nodes

    for(int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;

        adjList[u].push_back(v);
    }

    vector<int> inDegree(n + 1, 0);
    queue<int> q;

    for(int node = 1; node <= n; node++)
    {
        for(int neighbour : adjList[node])
            inDegree[neighbour]++;
    }

    for(int node = 1; node <= n; node++)
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

    if(topoSort.size() < n)
      return 1; //cycle exists
    
    return 0;
}

//M - 2, we don't really need topo sort answer vector, after complete the traversal, we can just check if any node has indeg > 0
#include <queue>

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  // Write your code here.

  vector<vector<int>> adjList(n + 1); //question has 1-based nodes

    for(int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;

        adjList[u].push_back(v);
    }

    vector<int> inDegree(n + 1, 0);
    queue<int> q;

    for(int node = 1; node <= n; node++)
    {
        for(int neighbour : adjList[node])
            inDegree[neighbour]++;
    }

    for(int node = 1; node <= n; node++)
    {
        if(inDegree[node] == 0)
            q.push(node);
    }


    while(!q.empty())
    {
        int node = q.front();
        q.pop();

        for(int neighbour : adjList[node])
        {
            inDegree[neighbour]--;
            
            if(inDegree[neighbour] == 0)
                q.push(neighbour);
        }
    }

    for(int node = 1; node <= n; node++)
    {
        if(inDegree[node] > 0)
            return 1; //cycle exists
    }

    return 0;
}
