class Solution {
public:
    int maxSubArray(vector<int>& nums) 
    {
        int sum = 0;
        int maxsum = 0;
        int x;
        int maxEl = nums[0];
        
        for(int i = 0; i < nums.size(); i++)
        {
            x = nums[i];
            
            maxEl = max(maxEl, x);
            
            sum += x;
            
            if(sum < 0)
                sum = 0;
            
            maxsum = max(maxsum, sum);
            
        }
        
        if(maxEl < 0)
            return maxEl;
        
        return maxsum;
    }
};
