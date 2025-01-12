// Time Complexity: O(k * (2^t)) where t is the target, k is the average length
// Assume that there is 1 and the target you want to reach is 10 so 10 times you can “pick or not pick” an element.
//hence, 2^n ki jagah 2^t. and k is for inserting v into ans.

// Space Complexity: O(k*x), k is the average length and x is the no. of combinations

//all elements unique, each can be used any number of times, sum of subset = target
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
    
    
vector<vector<int>> combSum(vector<int> &ARR, int B)
{
    vector<vector<int>> ans;
    sort(ARR.begin(), ARR.end());
    helper(ans, {}, 0, B, ARR);
    return ans;
}
