//
class Solution {
public:
    
    int robBase(vector<int>& nums) {
        
        int n = nums.size();
        
        int prev2 = 0;
        int prev = nums[0];
        int curr;
        
        for(int i = 1; i < n; i++)
        {
            int l = nums[i];
            
            if(i > 1)
                l += prev2;
            
            int r = prev;
            
            curr = max(l, r);
            
            prev2 = prev;
            prev = curr;
        }
        
        return prev;
    }
    
    int rob(vector<int>& nums) 
    {
        
        if(nums.size() == 1){
            return nums[0];
        }
        
        int n = nums.size();
        
        vector<int> temp1;
        vector<int> temp2;
        
        for(int i = 1; i < n; i++)
            temp1.push_back(nums[i]);
        
        for(int i = 0; i < n - 1; i++)
            temp2.push_back(nums[i]);
        
        return max(robBase(temp1), robBase(temp2));
        
    }
};
