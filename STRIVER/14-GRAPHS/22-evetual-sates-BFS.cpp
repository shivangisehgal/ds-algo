//refer handwritten notes for exp.

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& adj) {
        int n = adj.size();
        
        vector<vector<int>> adjRev(n);
        vector<int> inDegree(n, 0);
        queue<int> q;
        
        for(int node = 0; node < n; node++)
        {
            for(int neighbour : adj[node])
            {
                adjRev[neighbour].push_back(node);
                inDegree[node]++;
            }
        }
        
        for(int node = 0; node < n; node++)
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

            for(int neighbour : adjRev[node])
            {
                inDegree[neighbour]--;

                if(inDegree[neighbour] == 0)
                    q.push(neighbour);
            }
        }
        
        sort(ans.begin(), ans.end()); //ques wants answer in sorted form
        
        return ans;
    
    }
};
