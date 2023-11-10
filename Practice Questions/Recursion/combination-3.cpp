class Solution {
public:
    void rec(int i, int k, int n, vector<int> v, vector<vector<int>>& ans)
    {
        //base case
        if(k == 0 && n == 0)
        {
            ans.push_back(v);
            return;
        }
        
        if(i == 10 || k == 0 || n == 0)
            return;
        
        
        //take
        if(i <= n)
        {
            v.push_back(i);
            rec(i + 1, k - 1, n - i, v, ans);
            v.pop_back();
        }
        
        //not take
        rec(i + 1, k, n, v, ans);
    }
    
    
    
    
    vector<vector<int>> combinationSum3(int k, int n) {
        
        vector<int> v;
        vector<vector<int>> ans;
        rec(1, k, n, v, ans);
        return ans;
    }
};
