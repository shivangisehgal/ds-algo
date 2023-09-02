//TC: O(NlogN)
//SC: O(1) (except answer vector)
class Solution {
public:
    
    bool binSearch(vector<int>& nums, int s, int target)
    {
        int e = nums.size() - 1;
        
        while(s <= e)
        {
            int mid = (e + s) / 2;
            
            if(nums[mid] == target)
                return true;
            
            else if(nums[mid] < target)
                s = mid + 1;
            
            else
                e = mid - 1;
        }
        
        return false;
    }
    
    int findPairs(vector<int>& nums, int k) {
        
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        int count = 0;
        
        for(int i = 0; i < n; i++)
        {
            if(i > 0 && nums[i] == nums[i - 1])
                continue;
            
            //find element such that it is = nums[i] + k
            if(binSearch(nums, i + 1, k + nums[i]))
                count++;
        }
        
        return count;
    }
    
};
