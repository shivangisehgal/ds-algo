// The top-down approach is pretty easy after we see the tricks:

// Pad the beginning+end of the array with 1, since the problem defines it this way, it won't affect the final value, and most importantly it eliminates the need to deal with these special cases
// Realize that working backwards will allow us to cleanly divide the array into subproblems ("reverse thinking" as dietpepsi describes above)
// Pop all the 0 balloons first and remove them from the array (since they are worth nothing)

// There are 3 variables in our main equation: the values of the 3 balloons to pop. Again, we use the two 1's we just padded the array with to eliminate two of those variables off the bat
// Now just try all the possible middle balloons to pop (the 3rd variable). For each balloon we choose, use it as the right and left ballon of the next level of recursion, along with the padded 1's, and so forth.
// Base case is when there are no more balloons between the left and right balloon indexes (left+1 == right)

//memo
class Solution {
public:
    int rec(int i, int j, vector<vector<int>>& dp, vector<int>& nums)
    {
        if(i > j)
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int maxi = -1e8;
        
        for(int ind = i; ind <= j; ind++)
        {
            int coins = nums[i - 1] * nums[ind] * nums[j + 1];
            coins += rec(i, ind - 1, dp, nums) + rec(ind + 1, j, dp, nums);
            
            maxi = max(maxi, coins);
        }
        
        return dp[i][j] = maxi;
    }
    
    int maxCoins(vector<int>& nums) {
        
        int n = nums.size();
        
        nums.insert(nums.begin(), 1);
        
        nums.push_back(1);
        
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return rec(1, n, dp, nums);
    }
};

//tabu
class Solution {
public:

    int maxCoins(vector<int>& nums) {
        
        int n = nums.size();
        
        nums.insert(nums.begin(), 1);
        
        nums.push_back(1);
        
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
        
        for(int i = n; i >= 1; i--)
        {
            for(int j = i; j <= n; j++)
            {
                int maxi = -1e8;
        
                for(int ind = i; ind <= j; ind++)
                {
                    int coins = nums[i - 1] * nums[ind] * nums[j + 1];
                    coins += dp[i][ind - 1] + dp[ind + 1][j];

                    maxi = max(maxi, coins);
                }
                
                if(i <= j)
                    dp[i][j] = maxi;
            }
        }
        return dp[1][n];
    }
};
