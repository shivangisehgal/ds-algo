//BRUTE - USE HASH SET
//THE BELOW STYLE IS PICK AND NOT-PICK STYLE OF RECURSION
class Solution {
public:

 void helper(set<vector<int>>& ans, vector<int>& v, int i, int target, vector<int>& candidates)
    {
        //base case
        if(i == candidates.size())
        {
            if(target == 0)
            {
                ans.insert(v);
            }
            return;
        }
        
        
        //pick
        if(target >= candidates[i])
        {
            v.push_back(candidates[i]);
            
            helper(ans, v, i + 1, target - candidates[i], candidates);
        
        //don't pick
        v.pop_back();
        }
        
        
        helper(ans, v, i + 1, target, candidates);
        
    }
    
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
    {
        
        set<vector<int>> ans;
        vector<int> v = {};
        int i = 0;
        sort(candidates.begin(), candidates.end()); //lexicographic
        helper(ans, v, i, target, candidates);
        vector<vector<int>> ans_vector(ans.begin(), ans.end());
        
        return ans_vector;
    }
};

//OPTIMIZED
//THE BELOW STYLE IS ANOTHER METHOD

/*
    
Initially, We start with the index 0, At index 0 we have n – 1 way to pick the first element of our subsequence.

Check if the current index value can be added to v. If yes add it to v and move the index by 1. while moving the index skip the consecutive repeated elements because they will form duplicate sequences.

Reduce the target by arr[i], call the recursive call for f(idx + 1,target – 1,ds,ans) after the call make sure to pop the element from v.(By seeing the example recursive You will understand).

if(arr[i] > target) then terminate the recursive call because there is no use to check as the array is sorted in the next recursive call the index will be moving by 1 all the elements to its right will be in increasing order.

https://lh6.googleusercontent.com/xsb46oCfbNclHzkzuOZqiGDcST0giAlFSAjWC-FcXA4oYidD7n6DHq3qj4oJ4_qqSk4dzrozFM1V1yF5N237h5oo2rbQo3Y752QRDtZhyTGsEAz0_cEafV0V5uVF6kZmRpQbgetd


say candidates = [1,1,1,2,2]
    if in an itermediate step, v has [1]
    so, i'll have the option to include either 1th, 2nd, 3rd or 4th index
    => v = [1,1] or [1,1] or [1,2] or [1,2]
    so, if the element is similar, then the combination thus formed would also be similar.
    so, we should not call for 2nd or 4th index (provided v = [1])
    
    similarly, when v = [],
    we should not call, 1st, 2nd or 4th index, as it would result in same combination.
    
*/

class Solution {
public:
    
    void helper(int i, int target, vector<int>& v, vector<vector<int>>& ans,  vector<int>& candidates)
    {
        //base case
        if(target == 0)
        {
            ans.push_back(v);
            return;
        }
        
        //we will have max n - i ways to select each ith indexed element in v, from candidates
        //but in case, it has repetitions in candidates, we will only consider it once as other would be same combination scenarios
        //also, if target is less than the element to be selected, we would not consider elements lying further than this in candidates either.
        
        for(int ind = i; ind < candidates.size(); ind++)
        {
            if(candidates[ind] > target)
                break;
            
            if(ind > i and candidates[ind] == candidates[ind - 1]) //duplicate elements avoided
                continue;
            
            //else, consider/add this element in v, and move forward
            v.push_back(candidates[ind]);
            helper(ind + 1, target - candidates[ind], v, ans, candidates);
            v.pop_back();
        }
        
    }
    
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> v;
        sort(candidates.begin(), candidates.end());
        helper(0, target, v, ans, candidates);
        return ans;
    }
};
