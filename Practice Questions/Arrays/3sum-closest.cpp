class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        sort(nums.begin(), nums.end());
        
        int ans = nums[0] + nums[1] + nums[2];
        
        int n = nums.size();
        
        for(int i = 0; i < n - 2; i++)
        {
            int low = i + 1;
            int high = n - 1;
            
            while(low < high)
            {
                int sum = nums[i] + nums[low] + nums[high];
                
                if(abs(target - sum) < abs(target - ans))
                {
                    ans = sum;
                }
                
                if(sum > target)
                    high--;
                else
                    low++;
            }
        }
        
        return ans;
    }
};
