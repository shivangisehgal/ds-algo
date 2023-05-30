//TC: exponential : (2^t) * N
//SC: Variable (depends on the no. of comb): N * numComb

class Solution {
public:
    
void helper(vector<vector<int>>& ans, vector<int> v, int i, int target, vector<int>& candidates)
    {
        //base case
            if(i == candidates.size())
            {
                if(target == 0)
                {
                    ans.push_back(v);
                }
                
                return;
            }
        
        
        
        //pick
        if(target >= candidates[i])
        {
            v.push_back(candidates[i]);
            helper(ans, v, i, target - candidates[i], candidates);
            
            //for not pick
            v.pop_back();
        }
        
        //not pick
        helper(ans, v, i + 1, target, candidates);
        
    }
    
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        vector<vector<int>> ans;
        helper(ans, {}, 0, target, candidates);
        return ans;
    }
};
