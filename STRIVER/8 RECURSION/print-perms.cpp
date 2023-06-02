//BRUTE
//for selecting one from n nums, you have n options
//use a visited map or vector, to know that you have visisted this element
//TC: O(N! X N)
//SC: O(N)

class Solution {
public:
    
    void helper(vector<bool>& visited, vector<int>& v, vector<vector<int>>& ans, vector<int>& nums)
    {
        if(v.size() == nums.size())
        {
            ans.push_back(v);
            return;
        }
        
        
        for(int ind = 0; ind < nums.size(); ind++)
        {
            if(visited[ind] != true)
            {
                visited[ind] = true;
                v.push_back(nums[ind]);
                helper(visited, v, ans, nums);
                v.pop_back();
                visited[ind] = false;
            }
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> v;
        vector<bool> visited(nums.size(), false);
        helper(visited, v, ans, nums);
        return ans;
    }
};


//OPTIMAL
//NO EXTRA SPACE FOR STORING USED
//[1 2 3] 
//swapping each further element, will give us the permutations


https://lh4.googleusercontent.com/rT5kZ2p2oZJIoSa2DcjQ2NTyUUVGEeOCCDtcdvZi1lTyIjnXuAFaQ4tI7TxHqLqdR4Xig4ncX37p2SBmT5hfihQWGpiFL_foQl2kGwVnvz6VGlfHqS_bbc-8VGsJDeb0CfiC7aSN

//TC: O(N! X N)
//SC: O(1) //if not considering stack space
class Solution {
public:
    
    void helper(int i, vector<vector<int>>& ans, vector<int>& nums)
    {
        
        if(i == nums.size())
        {
            ans.push_back(nums);
            return;
        }
        
        for(int ind = i; ind < nums.size(); ind++)
        {
            swap(nums[ind], nums[i]);
            helper(i + 1, ans, nums);
            swap(nums[ind], nums[i]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        helper(0, ans, nums);
        return ans;
    }
};

