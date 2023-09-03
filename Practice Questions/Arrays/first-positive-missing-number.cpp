//first poitive umber will lie from 1 to n + 1
//also, we don't care about negatives or numbers > n + 1 (technically, n, so in case we find all 1 to n, our answer would obviously be n + 1)
//array of size n, ans we care about [1, n] => negative marking

//so, firstly, make the negative indices as 0, for this to work (since, ind = abs(nums[i]) - 1 => always >=0 for negative numbers)
// now, if index >= 0 and ind < n => a. index is valid, b. nums[i] >= 1 & nums[i] <= n
// if 0, mark it with an out of bound negative number, 

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        int n = nums.size();
        
        for(int i = 0; i < n; i++)
            if(nums[i] < 0)
                nums[i] = 0;
        
        for(int i = 0; i < n; i++)
        {
            int ind = abs(nums[i]) - 1;
            
            if(ind >= 0 && ind < n)
            {
                if(nums[ind] > 0)
                    nums[ind] = -nums[ind];
                
                else if(nums[ind] == 0)
                     nums[ind] = -(n + 1); // such that ind = n => out of bound
            } 
        }
        
        for(int i = 0; i < n; i++)
        {
            if(nums[i] >= 0)
                return (i + 1);  
        }
        
        return (n + 1);
    }
};
