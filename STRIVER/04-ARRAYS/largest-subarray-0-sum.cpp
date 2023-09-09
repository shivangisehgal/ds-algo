//BRUTE
//Find all subarrays, calculate their length and return max
//TC: O(N^3)
//SC: O(1)

//BETTER
//Find all subarrays using prefix sums, calculate their length and return max
//TC: O(N^2)
//SC: O(N)

//OPTIMAL
//HASH MAP OF PREFIX SUM / VARIABLE SLIDING WINDOW
/*
calculate prefix sum at each iteration

if there exists a prefix sum in hashmap such that
prefixSum NOW - prefixSum in MAP = 0, (basically prefixSum NOW = prefixSum MAP), get its index and calculate length
we need not add/update prefixSum NOW in our hashmap coz we want to find max length, and its index is obv greater

else
store this prefixsum NOW in hashmap with its index.
*/

//TC: O(N)
//SC: O(N)

class Solution{
    public:
    int maxLen(vector<int>& nums, int n)
    {   
        
        unordered_map<int, int> prefixsumMap;
        int sum = 0;
        int maxlength = 0;
        prefixsumMap[0] = -1;
        for(int i = 0; i < n; i++)
        {
            sum += nums[i];
            
            if(prefixsumMap.find(sum - 0) != prefixsumMap.end())
            {
                int j = prefixsumMap[sum - 0];
                maxlength = max(maxlength, i - (j + 1) + 1);
            }
            
            else
                prefixsumMap[sum] = i;
        }
        
        return maxlength;
    }
};
