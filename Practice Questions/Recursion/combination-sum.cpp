// Time Complexity: O(2^t * k) where t is the target, k is the average length

// Reason: Assume if you were not allowed to pick a single element multiple times, every element will have a couple of options: pick or not pick which is 2^n different recursion calls, also assuming that the average length of every combination generated is k. (to put length k data structure into another data structure)

// Why not (2^n) but (2^t) (where n is the size of an array)?

// Assume that there is 1 and the target you want to reach is 10 so 10 times you can “pick or not pick” an element.

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
