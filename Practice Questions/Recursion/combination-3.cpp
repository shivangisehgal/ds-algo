class Solution {
    
    void rec(vector<int> v, int i, int n, int target, vector<vector<int>>& ans)
    {
               
        if(i > 10)
            return;
        
        if(v.size() == n)
        {
            if(target == 0)
            {
                ans.push_back(v);
                return;
            }
        }
        
        //pick
        if(target >= i)
        {
            v.push_back(i);
            rec(v, i + 1, n, target - i, ans);
            v.pop_back();
        }
        
        //not pick
        rec(v, i + 1, n, target, ans);
    }
    
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        
        vector<vector<int>> ans;
        rec({}, 1, k, n, ans);
        return ans;
    }
    
};
