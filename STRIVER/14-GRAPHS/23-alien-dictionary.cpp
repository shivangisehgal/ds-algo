//Ques: 
//Words sorted according human disctionary:
// abca
// abcd
// baa
// cab
// cad

// You are given that these words are sorted according to alien dictionary
// baa 
// abcd
// abca
// cab
// cad

//Return how the order of alphabets looks like for aliens
//Here, 
//b should come before a
//d should come before a
//a should come before c
//b should come before d

//Check if linear order of them is possible (hence return the order)

//soln. store edges and do topo sort

vector<int> detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  // Write your code here.

  vector<vector<int>> adjList(n); 

    for(int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;

        adjList[u].push_back(v);
    }

    vector<int> inDegree(n, 0);
    queue<int> q;

    for(int node = 0; node < n; node++)
    {
        for(int neighbour : adjList[node])
            inDegree[neighbour]++;
    }

    for(int node = 0; node < n; node++)
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

    if(topoSort.size() != n)
      return {}; //cycle exists
    
    
    return topoSort;
}


string getAlienLanguage(vector<string> &dictionary, int k)
{
    // Write your code here.
    int n = dictionary.size();
    vector<pair<int, int>> edges;

    for(int i = 0; i < n - 1; i++)
    {
        string s1 = dictionary[i];
        string s2 = dictionary[i + 1];

        int j = 0;

        while(j < min(s1.length(), s2.length()))
        {
            int u = s1[j] - 'a';
            int v = s2[j] - 'a';

            if(u != v)
            {
                edges.push_back({u, v});
                break;
            }

            j++;
        }
    }

    vector<int> ans = detectCycleInDirectedGraph(k, edges);

    string topoString = "";

    for(int node : ans)
    {
        topoString += node + 'a';
    }
    
    return topoString;
}
