//use a queue to first store the starting node
//for each front element of the queue, push all its neighbours inside the queue if they havent been visited yet

 //TC: O(N) + O(2E) (queue would run n times, and the for loop will run in for a net of all neighbours (= 2E)
//SC: O(N) 

vector<int> bfsTraversal(int n, vector<vector<int>> &adj){

    vector<int> ans;
    vector<bool> visited(n, false);
    queue<int> q;
    
    q.push(0); //starting vertex is mentioned as 0 in question
    visited[0] = true;
    
    while(!q.empty())
    {
        int v = q.front();
        q.pop();

        ans.push_back(v);
        
        for(int neighbour : adj[v])
        {
            if(!visited[neighbour])
            {   
                visited[neighbour] = true;
                q.push(neighbour);
            } 
        }
    }
    
    return ans;
    
}
