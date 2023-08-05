//Question asks, if array is divided into exactly 2 subsets, tell if the subsets can have equal sum?
//we know, S1 + S2 = array sum
//If S1 = S2 => S1 = S2 = sum / 2

//so, we basically have to check, if there exists a subset with sum = ARR_SUM / 2
//IS SUBSET SUM = K? (where k = ARR_SUM / 2)

class Solution {
public:
    
    bool canPartition(vector<int>& nums) {
        
        int n = nums.size();
        int sum = 0;
        int k;
        
        for(int i = 0; i < n; i++)
                sum += nums[i];
        
        if(sum & 1)
            return false;
        
        else
            k = sum / 2;


      
        //SUBSET SUM = K?

      //SPACE OPT
        vector<bool> prevIndex(k + 1, false);
        vector<bool> currIndex(k + 1, false);

        //base cases
        //1. if target = 0, for all elements, answer = true => For All rows, first element is true

        prevIndex[0] = currIndex[0] = true;

        //2. if i = 0, if target = arr[0], answer = true;
        if(k >= nums[0])
            prevIndex[nums[0]] = true; 

        for(int i = 1; i < n; i++)
        {
            for(int target = 0; target <= k; target++)
            {
                bool not_take = prevIndex[target];
                bool take = false;

                if(target >= nums[i])
                    take = prevIndex[target - nums[i]];

                currIndex[target] = not_take || take;
            }

            prevIndex = currIndex;
        }

        return prevIndex[k];
    }
};
