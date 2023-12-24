//TC: O(N) | SC: O(1)

int Solution::solve(vector<int> &nums, int k) {
    
    int n = nums.size();
    
    int i = 0;
    int j = 0;
    
    int currSum = 0;
    
    int count = 0;
    
    while(j < n)
    {
        currSum += nums[j];
        j++;
        
        while(currSum >= k && i < j)
        {
            currSum = currSum - nums[i];
            i++;
        }
        
        if(currSum < k)
            count = (j - i) + count; 
            //LESS THAN k: 
                //only j = 1, [j, j - 1] = 2, [j, j - 1, j - 2] = 3....[j, j - 1,..., i] = j - i;
            //👆 this + count for j - 1
    }
    
    return count;
    
}
