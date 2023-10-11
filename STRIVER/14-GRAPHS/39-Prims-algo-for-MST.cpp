//Intuition: with each node, I'm choosing its minimum edge weight and contnuing.
//Hence, eventually I will have all nodes connected via min. edge wts. possible

// 1. if node has been visited. continue
// 2. else visit this, psuh the parent-node edge is MST edges vector, add edge to sum, 
// and push all neighbours in pq if they haven't been visited

//TODO: WRONG
// TC: O(E) for pq iteration * [inside PQ]
// inside PQ = [ O(logE) for pq insertion (worst case, one node connected to all others, max E insertions in one iter) + O(ElogE) for all neighbours & insertion = logE]
// => inside PQ = O(logE + ElogE) = O(ElogE)
// => TC: E^2logE
  
int spanningTree(int n, vector<vector<int>> adj[])
    {
        // code here
        vector<bool> visited(n, false);
        vector<pair<int, int>> MST;
        int sum = 0;
        
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> minHeap;
        
        minHeap.push({0, {0, -1}});
        
        while(!minHeap.empty())
        {
            auto f = minHeap.top();
            minHeap.pop();
            
            int wt = f.first;
            int node = f.second.first;
            int parent = f.second.second;
            
            if(visited[node] == true)
                continue;
            
            visited[node] = true;
            
            MST.push_back({parent, node});
            
            sum += wt;
            
            for(auto nw : adj[node])
            {
                int neighbour = nw[0];
                int edge_wt = nw[1];
                
                if(visited[neighbour] == false)
                {
                    minHeap.push({edge_wt, {neighbour, node}});
                }
            }
        }
        
        return sum;
    }
