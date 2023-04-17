//Negative Marking
//TC: O(N)
//SC: O(1)

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        
        int n = nums.size() + 1;
        
        for(int i = 0; i <= n; i++)
        {
            int idx = abs(nums[i]);
            
            if(nums[idx] < 0)
                return idx;
            else
                nums[idx] = -nums[idx];
        }
        
        return 0;
    }
};
