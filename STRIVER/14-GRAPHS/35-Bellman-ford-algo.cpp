// need of adjList.
//Bellman ford algo - can be used for when we have negative edges and we are still looking to calculate shortest path from source to any (or all) node(s).
//Dijkstra's cannot be used for when we have a negative weight -> infinite PQ (less weight waala pehle, uska neighbour baadme, so neighbour will keep on inserted less weight and this will continue)
//We can use bellman for negative weights. 
//If we have a negative cycle in our graph (ie, total path weight of the cycle is negative), then we can't find the shortest path obv.

//TC: O(E * V)
//SC: O(V)

vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {

        vector<int> dist(V, 1e8);
        dist[S] = 0;
        
        bool flag = false;
        
        for(int i = 0; i <= V - 1; i++)
        {
            flag = false;
            
            //Relax all edges
            for(auto edge : edges)
            {
                int u = edge[0];
                int v = edge[1];
                int wt = edge[2];
                
                if(dist[u] + wt < dist[v])
                {
                    dist[v] = dist[u] + wt;
                    flag = true;
                }
            }
            
            if(flag == false)
                return dist;
        }
        
        //if negative cycle, even after (n - 1) iterations, my dist would change
        for(auto edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
                
            if(dist[u] + wt < dist[v])
            {
                dist[v] = dist[u] + wt;
                flag = true;
            }
            
            if(flag == true)
                return {-1};
        }
        
        return dist;
    }
