class Solution 
{
public:
    int threeSumClosest(vector<int>& nums, int target) 
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
    
        
        int ans = nums[0] + nums[1] + nums[2];
        
        for(int i = 0; i < n - 2; i++)
        {
            int low = i + 1;
            int high = n - 1;
            
            while(low < high)
            {
                int sum = nums[i] + nums[low] + nums[high];
                
                if(sum == target)
                {
                    return target;
                }
                else if(sum < target)
                {
                    if(abs(sum - target) < abs(ans - target))
                    {
                        ans = sum;
                    }
                    low++;
                }
                else
                {
                    if(abs(sum - target) < abs(ans - target))
                    {
                        ans = sum;
                    }
                    high--;
                }
            }
        }
        
        return ans;
    }
};
