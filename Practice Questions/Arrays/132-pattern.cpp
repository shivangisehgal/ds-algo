//Brute:
//use three loops - for i, for j: check nums[j] > nums[i], for k: check nums[k] < nums[j] & nums[k] > nums[i]
//TC: O(N^3)
//SC: O(1)

//Better:
//we know that we want nums[i] to be minimum (note it is a subsequence, so as minimum as possible) and also i'th index to be minimum.
//so we can keep track of minimum element till each element we encounter.
//so, we only need loops for j and k
//hence, for j: find mini, check nums[j] > mini, for k: check nums[k] < nums[j] & nums[k] > mini
//TC: O(N^2)
//SC: O(1)


//Optimal
//Using a stack (monotonically increasing), we can keep a track of the jth numbers too.
//nums[j] should be as big as possible.
//if nums[k] < stack top, and, nums[k] > mini => 132 pattern.
//else, now, pop and check.
//else, if nums[k] < mini => this is new mini, and push it on the stack.
//TC: O(N)
//SC: O(1)

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        
        stack<pair<int, int>> s;
        int n = nums.size();
        
        int minLeft = nums[0];
         s.push({nums[0], minLeft});
        
        for(int k = 1; k < n; k++)
        {
            while(!s.empty() && nums[k] >= s.top().first)
                s.pop();
            
            if(!s.empty() && nums[k] > s.top().second)
                return true;
            
            s.push({nums[k], minLeft});
            
            minLeft = min(nums[k], minLeft);
        }
        
        return false;
        
    }
};
