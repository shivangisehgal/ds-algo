//Brute
//Generate all subarrays
//TC: O(N^3)
//SC: O(1)

//Better
//Generate all prefix products 
//Generate all subarrays
//TC: O(N^2)
//SC: O(1)

int maxProductSubArray(vector<int>& nums)
{
    int result = nums[0];

    for (int i = 0; i < nums.size() - 1; i++) 
    {
        int p = nums[i];

        for (int j = i + 1; j < nums.size(); j++) 
        {
            result = max(result, p);
            p *= nums[j];
        }

        result = max(result, p); 
    }

    return result;
}

//Optimal
//TC: O(N)
//SC: O(1)

//Prefix and Suffix products
// suppose there's no 0 in the array:

// if number of negative number is 
    //1. odd, Let left most is i and right most is j, then leaving one negative number, we will get even negatives (on either side of it), hence, we can only either keep A[i..t - 1] or A[t + 1....j] to make it max
    //ex. [3 2 -1 4 -6 3 -2 6] => [3 2] -1 [4 -6 3 -2 6]
    
    //2. even, then we just multiply all the numbers.

// If there is 0, we will divide the array to several separated subarrays

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int n = nums.size();
        
        int prefix = 1;
        int suffix = 1;
        
        int maxPrefix = INT_MIN;
        int maxSuffix = INT_MIN;
        
        for(int i = 0; i < n; i++)
        {            
            prefix *= nums[i];
            suffix *= nums[n - 1 - i];
            
            maxPrefix = max(maxPrefix, prefix);
            maxSuffix = max(maxSuffix, suffix);
            
            if(nums[i] == 0)
                prefix = 1;
            
            if(nums[n - 1 - i] == 0)
                suffix = 1;
        }
        
        return max(maxPrefix, maxSuffix);
    }
};

