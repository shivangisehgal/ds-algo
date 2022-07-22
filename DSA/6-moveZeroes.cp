//TWO-POINTER

//keep j at start, if we encounter a non-zero number, start filling it from the start,
//if we encounter a zero don't increment j.
//TC: O(N), AS: O(1)

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = 0;
        int n = nums.size();
        
        for(int i = 0; i < n; i++)
        {
            if(nums[i] != 0)
            {
                nums[j] = nums[i];
                j++;
            }
        }
        
        while(j < n)
            nums[j++] = 0;
    }
};