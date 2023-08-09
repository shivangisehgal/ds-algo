//In the space opt. tabulation method: TC: O(N^2) | SC: O(N)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        
        int maxi = 0;
        
        for(int i = 0; i < n; i++)
        {
            for(int prev = 0; prev <= i - 1; prev++)
            {
                if(nums[prev] < nums[i])
                    dp[i] = max(1 + dp[prev], dp[i]);
                
            }
            
            maxi = max(maxi, dp[i]);
        }
        
        return maxi;
    }
};

//Since we know that our LIS will be sorted, we can use binary search in our temp array that is storing LIS.
//i/p: [5 8 3 7 9 1]

//IS can be:
//[5 8 9]
//[5 7 9]
//[3 7 9]
//[1]

//instead of storing them separately, since we just need to calculate the length of the LIS, we can store create only one array.
//0 - [5]
//1 - [5 8]
//2 - now we know another IS can be [3 8]. however, length of LIS will still be same, ie., 2. So we can simply replace the number just greater than 3, with 3, in the current array.
//so, 2 - [3 8]
//3 - similiarly, [3 7], [5 7] would still have len as 2, replace 8,
//so, 3 - [3 7]
//4 - [3 7 9]
//5 - now, [1] can be the only IS, but len of LIS will still be 3.
//so, 5 - [1 7 9]
//=> len(LIS) = len(temp array) = 3.

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> temp;
        
        temp.push_back(nums[0]);
        
        for(int i = 1; i < n; i++)
        {
            int ind = lower_bound(temp.begin(), temp.end(), nums[i]) - temp.begin(); //return index of lower bound of nums[i] in temp
            
            if(ind == temp.size())
                temp.push_back(nums[i]);
            else
                temp[ind] = nums[i];
        }
        
        return temp.size();
    }
};

