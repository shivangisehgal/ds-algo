//BRUTE: NESTED LOOPS
//TC: O(N^2)
//SC: O(1)

//BETTER: PREFIX ARRAY
//TC: O(N)
//SC: O(N)

//OPTIMAL: SPACE OPT. PREFIX SUM
//TC: O(N)
//SC: O(1)

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        
        int arrSum = 0;
        
        for(int num : nums)
            arrSum += num;
        
       int leftSum = 0;
        
       
       for(int i = 0; i < nums.size(); i++)
       {
           if(leftSum == arrSum - leftSum - nums[i])
               return i;
           
           leftSum += nums[i];
       }
        
      return -1;
        
    }
};
