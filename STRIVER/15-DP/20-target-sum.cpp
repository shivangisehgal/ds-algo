//Q. assign + or - to each element such that addition of all elements = target

//one thing we can do is, make recursion calls in the recursive function for plus and minus and return their sum.
//but it would be lengthy.

//recall what we did in partition sum = k.
//basically, we can group all +nums (S1) and -nums (S2). 
//hence, our S1 - S2 should be equal to target.

//S1 = totsum - S2
//hence, totsum - 2S2 = target
//S2 = (totsum - target ) / 2 => COUNT ALL SUBSEQUENCES WITH SUM = (totsum - target ) / 2




class Solution {
    
    private:
    
    int findWays(vector<int> &arr, int k) 
    {
        int n = arr.size();
        int m = 1e9 + 7;

        vector<int> prevIndex(k + 1, 0);
        vector<int> currIndex(k + 1, 0);

        if(arr[0] == 0)
            prevIndex[0] = 2;
        else
            prevIndex[0] = 1;

        currIndex[0] = 1;

        if(arr[0] <= k && (arr[0] != 0))
            prevIndex[arr[0]] = 1;

        for(int i = 1; i < n; i++)
        {
            for(int target = 0; target <= k; target++)
            {
                int not_pick = 0;
                int pick = 0;

                not_pick = prevIndex[target];

                if(arr[i] <= target)
                    pick = prevIndex[target - arr[i]];

                currIndex[target] = (not_pick + pick) % m;
            }

            prevIndex = currIndex;

        }

        return prevIndex[k] % m;
    }
    
    
public:
    
    int findTargetSumWays(vector<int>& nums, int target) {
        
        int totsum = 0;
        
        for(auto num : nums)
            totsum += num;
        
        if(totsum < target || ((totsum - target) % 2 != 0))
            return 0;
        
        int k = (totsum - target) / 2;
        
        return findWays(nums, k);
    }
};
