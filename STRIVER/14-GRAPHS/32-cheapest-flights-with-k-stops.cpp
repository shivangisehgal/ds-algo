//BRUTE
//Use Dijkstra's for{distance, node, stop} and update dist[node] and push in pq ONLY IF, 
//afer pushing, the stop <= k, else if stop = k + 1 and it is destination node.

//TC: O(ElogV)
//SC:  O(|E| + |V|) 

//CN
int savingMoney(int n, int source, int destination, int K, vector<vector<int>> &trains)
{
    vector<vector<pair<int,int>>> adj(n);

    for(int i = 0; i < trains.size(); i++)
    {
        int u = trains[i][0];
        int v = trains[i][1];
        int wt = trains[i][2];

        adj[u].push_back({v, wt});
    }


    vector<int> dist(n, INT_MAX);
    dist[source] = 0;

    priority_queue<pair<pair<int,int>, int>, vector<pair<pair<int,int>, int>>, greater<pair<pair<int,int>, int>>> minHeap;
    minHeap.push({{0, source}, 0});

    while(!minHeap.empty())
    {
        auto p = minHeap.top();
        minHeap.pop();

        int node = p.first.second;
        int parentDist = p.first.first;

        int stop = p.second;

        for(auto it : adj[node])
        {
            int neighbour = it.first;
            int wt = it.second;

            if(dist[neighbour] > parentDist + wt)
            {
                if(stop <= K || (stop == K + 1 && node == destination))
                {
                    dist[neighbour] = parentDist + wt;
                    minHeap.push({{parentDist + wt, neighbour}, stop + 1});
                }
            } 
        }
    }
    
    if(dist[destination] == INT_MAX)
        return -1;
    return dist[destination];

}

//OPTIMAL
//We can save up on time complexity if we prioritize stops first.
//we know that we anyway don't need to go beyong k.
//for all neighbours of the node, if node_dist + wt < dist[neigbour] & stop <= k, i'll push it and its stop as stop + 1.
//queue will be emptied once we finish all nodes with stops = k + 1
//return dist[destination]
//TC: O(E + V) //simple bfs
//SC: O(E + V)

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<vector<pair<int,int>>> adj(n);

        for(int i = 0; i < flights.size(); i++)
        {
            int u = flights[i][0];
            int v = flights[i][1];
            int wt = flights[i][2];

            adj[u].push_back({v, wt});
        }
        
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {src, 0}}); //{stop, node, dist}
        
        while(!q.empty())
        {
            auto p = q.front();
            q.pop();
            
            int stop = p.first;
            int node = p.second.first;
            int node_dist_from_src = p.second.second;
            
            if(stop > k)
                continue;
            
            for(auto nw : adj[node])
            {
                int neighbour = nw.first;
                int wt = nw.second;
                
                if(node_dist_from_src + wt < dist[neighbour] && stop <= k)
                {
                    dist[neighbour] = node_dist_from_src + wt;
                    q.push({stop + 1, {neighbour, dist[neighbour]}});
                }
            }
        }
        
        if(dist[dst] == INT_MAX)
            return -1;
        
        return dist[dst];
        
    }
};


