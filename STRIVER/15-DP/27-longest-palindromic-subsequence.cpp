//basically, find the LCS of s and reverse of s.

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        
        int n = s.length();
        
        string s1 = s;
        string s2 = "";
        
        for(auto ch : s)
            s2 = ch + s2;
        
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        
        for(int i = 0; i <= n; i++)
        {
            dp[0][i] = 0;
            dp[i][0] = 0;
        }
        
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(s1[i - 1] == s2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
        
        return dp[n][n];
    }
};
