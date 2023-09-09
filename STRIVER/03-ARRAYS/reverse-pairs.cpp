//Slightly different than Count inversions.
//if nums[i] > 2 * nums[j], the all the element in the left half array will be greater too (since left half array and right half array are assumed sorted in merge sort)
//count = mid - 1 + i - 1, move to next j
//else go to next i

//Difference: You can't sort the array at the same time

//if it were possibe, the algo could've been
//If nums[i] > 2 * nums[j] -> temp[k++] = nums[j++]
//else if nums[i] > nums[j] -> temp[k++] = nums[j++] !!!! HERE i++ cannot be done, but since nums[i] > 2 * nums[j++] is not true, then i should be moved forward to check.
//else (nums[i] < nums[j]) -> temp[k++] = nums[i++]

//TC: O(N log N) + O (N) + O (N) 
//SC: O(N)

class Solution {
public:
    int merge(vector<int>& nums, int s, int mid, int e)
    {
        vector<int> temp(e - s + 1);
        int i = s, j = mid, k = 0;
        int count = 0;
        
        while(i <= mid - 1 and j <= e)
        {
            if((long) nums[i] > (long) 2 * nums[j])
            {
                count += mid - i;
                j++;
            }
            
            else
                i++;
        }
        
        i = s, j = mid, k = 0;
        
        while(i <= mid - 1 and j <= e)
        {
            
            if(nums[i] <= nums[j])
            {
                temp[k++] = nums[i++];
            }
            
            else
                temp[k++] = nums[j++]; 
        }
        
        while(i <= mid - 1)
        {
            temp[k++] = nums[i++];
        }
        
        while(j <= e)
        {
            temp[k++] = nums[j++];
        }
        
        for(int i = s; i <= e; i++)
        {
            nums[i] = temp[i - s];
        }
        
        return count;
    }
    
    
    int mergeSort(vector<int>& nums, int s, int e)
    {
        //base case
        if(s >= e)
            return 0;
        int mid = (s + e) / 2;
        int count_rp = mergeSort(nums, s, mid);
        count_rp += mergeSort(nums, mid + 1, e);
        count_rp += merge(nums, s, mid + 1, e);
        
        return count_rp;
    }
    
    int reversePairs(vector<int>& nums) {
        int s = 0;
        int e = nums.size() - 1;
        return mergeSort(nums, s, e);
        
    }
    
    
};
