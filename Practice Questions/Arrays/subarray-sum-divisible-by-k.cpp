//BRUTE
// TC: O(N^3)
// SC: O(1)

//BETTER
// TC: O(N^2)
// SC: O(N)

//OPTIMAL
// TC: O(N)
// SC: O(N)

        
//If S1 gives remainder x ---------- when divided by k
//and S2 gives same remainder x ---------- when divided by k
//then, (S1 - S2) will be divisible by k
        

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {

        unordered_map<int, int> modCount;
        int count = 0;
        int n = nums.size();
        
        modCount[0] = 1;
        
        int prefixSum = 0;
        
        for(int i = 0; i < n; i++)
        {
            prefixSum += nums[i];
            
            int prefixSumMod = prefixSum % k;
            
           if(prefixSumMod < 0)
               prefixSumMod += k;
            
            if(modCount.find(prefixSumMod) != modCount.end())
                count += modCount[prefixSumMod];
            
            modCount[prefixSumMod]++;
        }
        
        return count;
    }
};
