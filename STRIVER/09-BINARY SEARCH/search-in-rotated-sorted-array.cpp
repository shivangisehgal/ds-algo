//TC: O(logN)
//SC: O(1)

class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        
        int s = 0;
        int e = nums.size() - 1;
        
        int mid;
        
        while(s <= e)
        {
            mid = (s + e) / 2;
            
            //if left half sorted, do SCANNING in left half
            if(nums[s] <= nums[mid])
            {
                //FINDING POSITION
                
                if(target == nums[mid])
                    return mid;
                //it target < nums[mid], then it should lie in the lefthalf of mid. 
                //But since, array is rotated, there are some elements smaller than nums[s] that are in the right half, 
                //so we need to check that to find in which half target will lie
                
                else if(target < nums[mid] and target >= nums[s]) //target lies in left half
                    e = mid - 1;
                
                
                else
                    s = mid + 1;
            }
            
            else //SCANNING right half
            {
                //FINDING POSITION
                if(target == nums[mid])
                    return mid;
                
                else if(target > mid and target <= nums[e]) //target lies in right half
                    s = mid + 1;
                else
                    e = mid - 1;
                    
            }
            
            
        }
        
        return -1;
    }
};
