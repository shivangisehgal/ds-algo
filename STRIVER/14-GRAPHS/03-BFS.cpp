//use a queue to first store the starting node
//for each front element of the queue, push all its neighbours inside the queue if they havent been visited yet

vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    // Write your code here
    int n = vertex;
    int m = edges.size();

    vector<int> adjList[n];

    for(int i = 0; i < m; i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    for(int i = 0; i < n; i++)
        sort(adjList[i].begin(), adjList[i].end());

  /***********************  BFS   *****************************/
  /************************************************************/

    //TC: O(N) + O(2E) (queue would run n times, and the for loop will run in for a net of all neighbours (= 2E)
    //SC: O(N) 
  
    //question states that starting node is 0
    int startVertex = 0;

    vector<int> ans;
    queue<int> q;
    int visited[n] = {0};
    
    q.push(startVertex);
    visited[startVertex] = 1;
    
    while(!q.empty())
    {
        int v = q.front();
        ans.push_back(v);
        q.pop();

        //push all neighbours of v
        for(int i = 0; i < adjList[v].size(); i++)
        {
            if(!visited[adjList[v][i]])
            {
                q.push(adjList[v][i]);
                visited[adjList[v][i]] = 1;
            }
        }
    }

    //unconnected vertices
    for(int i = 0; i < n; i++)
    {
        if(!visited[i])
            ans.push_back(i);
    }

  /************************************************************/
    
    return ans;
}
