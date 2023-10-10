//LC: Number of ways to reach destination
//Agar pehli baar neighbour ayega path mein, then ways[neighbour] = ways[node]
//else, jitne agar pehli baar nahi aa raha, then jitne path neighbour se already banre thhe + joh ways[node] hain already, dono add ho jaayenge.

//TC: O(ElogV)
//SC: O(E + V)

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        
        vector<vector<pair<int, int>>> adj(n);
        
        int mod = 1e9 + 7;
        for(auto edge : roads)
        {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }
        
       
        vector<long long> dist(n, LLONG_MAX);
        vector<int> ways(n, 0);
        
        dist[0] = 0;
        ways[0] = 1;
        
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> minHeap; //dist, node
        
        minHeap.push({0, 0});
        
        while(!minHeap.empty())
        {
            auto p = minHeap.top();
            minHeap.pop();
            
            long long node_dist = p.first;
            int node = p.second;
            
            for(auto nw : adj[node])
            {
                int neighbour = nw.first;
                long long wt = nw.second;
                
                if(node_dist + wt < dist[neighbour])
                {
                    dist[neighbour] = node_dist + wt;
                    ways[neighbour] = ways[node];
                    minHeap.push({node_dist + wt, neighbour});
                }
                
                else if(node_dist + wt == dist[neighbour])
                {
                    ways[neighbour] = (ways[node] + ways[neighbour]) % mod;
                }
            }
        }
        
        if(dist[n - 1] == LLONG_MAX)
            return 0;
        
        return ways[n - 1];
    }
};
