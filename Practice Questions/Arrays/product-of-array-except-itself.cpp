
//BRUTE:
//left and right for each element
//TC: O(N^2)
//SC: O(1) + O(N)

//BETTER
//prefix and suffix array
//TC: O(N)
//SC: O(N) + O(N)


//OPTIMAL
//answer array as suffix array, prefix only variable
//TC: O(N)
//SC: O(1) + O(N)

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int n = nums.size();
        
        vector<int> suffix(n, 1);
        
        for(int i = n - 1; i > 0; i--)
        {
            suffix[i - 1] = suffix[i] * nums[i];
        }
        
        int prefix = 1;
        
        for(int i = 0; i < n; i++)
        {
            suffix[i] = suffix[i] * prefix;
            prefix = prefix * nums[i];
        }
        
        return suffix;
    }
};
