//How is it different that normal search in rotated array?
//Edge case: [1,3,1,1,1] (when start element, is equal to mid, and THUS, is equal to last element)
//target 3
//Earlier there was equality, nums[s] <= nums[mid] - > 1 <= 1 true
//but 3 > 1 && 3 <= 1 IS FALSE -> goes to right half
//but 3 lies in left half!
//hence, reduce search space from left and right, so that s and e are not equal.

//TC: O(N) and Theta(logn)
//SC: O(1)

class Solution {
public:
    
    bool search(vector<int>& nums, int target) {
      
        int low = 0;
        int high = nums.size() - 1;
        
        while(low <= high)
        {
            int mid = low + (high - low) / 2;
            
            if(nums[mid] == target)
                return true;
            
            //case 1. low = mid = high
            if(nums[low] == nums[mid] && nums[mid] == nums[high]) //can lie anywhere
            {
                low++;
                high--;
                continue;
            }
            
            //case 2. left sorted
            else if(nums[mid] >= nums[low])
            {
                if(target >= nums[low] && target < nums[mid])
                    high = mid - 1;
                else
                    low = mid + 1;
            }
            
            else
            {
                if(target > nums[mid] && target <= nums[high])
                    low = mid + 1;
                else
                    high = mid - 1;
            }
        }
        
        return false;
        
    }
};
