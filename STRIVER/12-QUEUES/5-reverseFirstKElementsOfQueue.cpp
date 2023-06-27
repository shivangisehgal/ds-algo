//push first k elements in stack
//push back them in the queue -> hence, in reverse manner.
//pop and push back remaining elements in queue.

//TC: O(N)
//SC: O(K)

queue<int> modifyQueue(queue<int> q, int k) {
  
    stack<int> s;
    int count = 0;
    int n = q.size();
    
    while(!q.empty() && count < k)
    {
        count++;
        
        s.push(q.front());
        q.pop();
    }
    
    while(!s.empty())
    {
        q.push(s.top());
        s.pop();
    }
    
    while(count < n)
    {
        count++;
        q.push(q.front());
        q.pop();
    }
    
    return q;
}
