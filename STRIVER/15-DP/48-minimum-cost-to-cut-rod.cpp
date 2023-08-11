//refer handwritten notes

//memo
class Solution {
    int rec(int i, int j, vector<vector<int>>& dp, vector<int>& cuts)
    {
        if(j < i)
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int mini = 1e9;
        
        for(int ind = i; ind <= j; ind++)
        {
            int rope_len = cuts[j + 1] - cuts[i - 1];
            
            int cost = rope_len + rec(i, ind - 1, dp, cuts) + rec(ind + 1, j, dp, cuts);
            
            mini = min(mini, cost);
        }
        
        return dp[i][j] = mini;
    }
    
    
public:
    int minCost(int n, vector<int>& cuts) {
       
        sort(cuts.begin(), cuts.end());
        
        int c = cuts.size();
        
        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);
        
        vector<vector<int>> dp(c + 1, vector<int>(c + 1, -1));
        
        return rec(1, c, dp, cuts);
    }
};

//tabu
class Solution {
    
public:
    int minCost(int n, vector<int>& cuts) {
       
        sort(cuts.begin(), cuts.end());
        
        int c = cuts.size();
        
        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);
        
        vector<vector<int>> dp(c + 2, vector<int>(c + 2, 0));
        
        
        for(int i = c; i >= 1; i--)
        {
            for(int j = i; j <= c; j++)
            {
                int mini = 1e9;
                
                for(int ind = i; ind <= j; ind++)
                {
                    int ans = cuts[j + 1] - cuts[i - 1] + dp[i][ind - 1] + dp[ind + 1][j];
        
                     mini = min(mini, ans);
                }
                
                if(j >= i)
                    dp[i][j] = mini;
            }
        }
        
        return dp[1][c];
    }
};
