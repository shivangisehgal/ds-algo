//BRUTE
//SORT the array, if two adjacent numbers are equal, that is the duplicate number
//TC: O(NlogN), AS: O(1)

//BETTER
//use SET, if number already exists, that is the duplicate number
//TC: O(N), AS: O(N)

//OPTIMAL
//NEGATIVE MARKING
//If a element is encountered, make the element located at this index negative.
//If an element is found negative, yhen the index of this number is the duplicate element
//TC: O(N), AS: O(1)

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        
        int n = nums.size() + 1;
        
        for(int i = 0; i <= n; i++)
        {
            int idx = abs(nums[i]);
            
            if(nums[idx] < 0)
                return idx;
            else
                nums[idx] = -nums[idx];
        }
        
        return 0;
    }
};