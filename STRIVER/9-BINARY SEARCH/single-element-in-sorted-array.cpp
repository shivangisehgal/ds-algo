//BRUTE
//adjacent elements check.
//TC: O(N)
//SC: O(1)

//BETTER
//TC: O(N)
//SC: O(1)

//OPTIMAL
//TC: O(logN)
//SC: O(1)

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        
        
        int s = 0;
        int e = nums.size() - 1;
        
        int mid = (s + e) / 2;
        
        while(s <= e)
        {
            mid = (s + e) / 2;
            
            if(mid == 0 || mid == (nums.size() - 1))
                return nums[mid];
            
            if(nums[mid] == nums[mid - 1]) 
            {
                if((mid - s - 1) % 2 != 0) //if left half is odd length-ed: (m - 2) - s + 1 = m - s - 1
                    e = mid - 2;
                
                else
                    s = mid + 1;
            }
            
            else if(nums[mid] == nums[mid + 1])
            {
                if((mid - s) % 2 != 0) //if left half is odd length-ed: (m - 1) - s + 1 = m - s
                    e = mid - 1;
                
                else
                    s = mid + 2;
            }
            
            else
                return nums[mid];
        }
        
        return 0;
    }
};
