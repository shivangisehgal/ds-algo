//BRUTE, iterate over all loops
//TC: O(N^3)
//SC: O(N)

//BETTER - 1: Prefix sum array of LOG(nums[i])
//TC: O(N^2) 
//SC: O(N)

//BETTER - 2: Prefix sum array of LOG(nums[i]), where j is searched using Binary Search.
//TC: O(NlogN) 
//SC: O(N)

//OPTIMAL - Sliding Window for product, since no 0, hence, division is possible.
//TC: O(N)
//SC: O(1)

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        
        if(k <= 1)
            return 0;
        
        //no zero, hence, division is possible.
        int i = 0;
        int j = 0;
        
        int n = nums.size();
        
        long long prod = 1;
        int count = 0;
        
        while(j < n)
        {
            prod *= nums[j];
            j++;
            
            while(i < j && prod >= k)
            {
                prod = prod / nums[i];
                i++;
            }
            
            if(prod < k)
                count += (j - i);
        }
        
        return count;
    }
};
