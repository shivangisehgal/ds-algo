//TC: O(N)
//SC: O(N)
//for both

//Method 1 - Stacks
class Solution
{
    public:
    queue<int> rev(queue<int> q)
    {
        // add code here.
        stack<int> s;
        
        while(!q.empty())
        {
            int f = q.front();
            q.pop();
            
            s.push(f);
        }
        
        while(!s.empty())
        {
            int top = s.top();
            s.pop();
            
            q.push(top);
        }
        
        return q;
    }
};

// Method 2 - Recursion
class Solution
{
    public:
    
    void helper(queue<int>& q)
    {
        if(q.empty())
            return;
        
        int f = q.front();
        q.pop();
        
        helper(q);
        
        q.push(f);
    }
    
    queue<int> rev(queue<int> q)
    {
        helper(q);
        return q;
    }
};
