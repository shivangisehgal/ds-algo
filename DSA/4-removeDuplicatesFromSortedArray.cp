//Basic TWO-POINTER approach
//if same, keep incrementing incrementing
//once the adjacent element is different, save the first one, in j and increment it       
//last number would be the last element of the resulant array 
//TC: O(N), AS: O(1)

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int n = nums.size();
        int j = 0;
        for(int i = 0; i < n - 1;)
        {
            if(nums[i] == nums[i + 1])
            {
                i++;
            }
            else
            {
                nums[j] = nums[i];
                j++;
                i++;
            }
            
        }
        
        nums[j] = nums[n - 1];
        return (j + 1); //number of unique elements
    }
    
};