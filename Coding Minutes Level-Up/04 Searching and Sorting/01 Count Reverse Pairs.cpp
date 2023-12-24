class Solution {
public:
    
    int merge(int s, int mid, int e, vector<int>& nums)
    {
        int i = s;
        int j = mid + 1;
        int k = 0;
        
        int count = 0;
        
        vector<int> temp(e - s + 1);
        
        while(i <= mid && j <= e)
        {
            if((long long) nums[i] > (long long) 2 * nums[j])
            {
                count += mid - i + 1;
                j++;
            }
            
            else
                i++;
        }
        
         i = s;
         j = mid + 1;
        
        while(i <= mid && j <= e)
        {
            if(nums[i] <= nums[j])
            {
                temp[k++] = nums[i];
                i++;
            }
            
            else
            {
                temp[k++] = nums[j];
                j++;
            }
        }
        
        while(i <= mid)
        {
            temp[k++] = nums[i];
            i++;
        }
        
         while(j <= e)
         {
             temp[k++] = nums[j];
            j++;
         }
        
  
        
        for(int i = s; i <= e; i++)
        {
            nums[i] = temp[i - s];
        }
        
        return count;
    }
    
    
    
    int customMergeSort(int s, int e, vector<int>& nums)
    {
        if(s >= e)
            return 0;
        
        int mid = s + (e - s) / 2;
        int count = 0;
        
        count += customMergeSort(s, mid, nums);
        count += customMergeSort(mid + 1, e, nums);
        count += merge(s, mid, e, nums);
        
        return count;
    }
    
    
    
    int reversePairs(vector<int>& nums) {
        
        int s = 0;
        int e = nums.size() - 1;
        
        return customMergeSort(s, e, nums);
    }
};
