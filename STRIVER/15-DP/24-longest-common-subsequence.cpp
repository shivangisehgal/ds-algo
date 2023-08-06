//rec

class Solution {
public:
    
    int rec(int ind1, int ind2, string& s1, string& s2)
    {
        if(ind1 < 0 || ind2 < 0)
            return 0;
        
        //match
        if(s1[ind1] == s2[ind2])
            return 1 + rec(ind1 - 1, ind2 - 1, s1, s2);
        
        else //not match
            return 0 + max(rec(ind1, ind2 - 1, s1, s2), rec(ind1 - 1, ind2, s1, s2));
    }
    
    int longestCommonSubsequence(string text1, string text2) 
    {
        return rec(text1.length() - 1, text2.length() - 1, text1, text2);
    }
};

//memo - NOTE: SHOFTED (1-BASED) MEMO: -1 to n1 - 1 => 0 to n1 ~ HELPS IN COVERTION TO TABULATION
class Solution {
public:
    
    int rec(int ind1, int ind2, vector<vector<int>>& dp, string& s1, string& s2)
    {
        if(ind1 == 0 || ind2 == 0)  //since shifted index, edge case changed from -1 to xero
            return 0;
        
        if(dp[ind1][ind2] != -1)
            return dp[ind1][ind2];
      
        //match
        if(s1[ind1 - 1] == s2[ind2 - 1]) //since shifted index (starts from n1, n2)
            return dp[ind1][ind2] = 1 + rec(ind1 - 1, ind2 - 1, dp, s1, s2);
        
        else //not match
            return dp[ind1][ind2] = 0 + max(rec(ind1, ind2 - 1, dp, s1, s2), rec(ind1 - 1, ind2, dp, s1, s2));
    }
    
    int longestCommonSubsequence(string text1, string text2) 
    {
        int n1 = text1.length();
        int n2 = text2.length();
        
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, -1));
        
        return rec(n1, n2, dp, text1, text2);
    }
};

//tabulation
class Solution {
public:
    
    int longestCommonSubsequence(string text1, string text2) 
    {
        int n1 = text1.length();
        int n2 = text2.length();
        
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, -1));
        
        for(int i = 0; i <= n1; i++)
            dp[i][0] = 0;
        
        for(int j = 0; j <= n2; j++)
            dp[0][j] = 0;
        
        
        for(int i = 1; i <= n1; i++)
        {
            for(int j = 1; j <= n2; j++)
            {

                
                if(text1[i - 1] == text2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                
                else
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
        
        return dp[n1][n2];
    }
};

//space opt
class Solution {
public:
    
    int longestCommonSubsequence(string text1, string text2) 
    {
        int n1 = text1.length();
        int n2 = text2.length();
        
        vector<int> prevIndex(n2 + 1, 0);
        vector<int> currIndex(n2 + 1, 0);
        
        
        for(int i = 1; i <= n1; i++)
        {
            for(int j = 1; j <= n2; j++)
            {
                if(text1[i - 1] == text2[j - 1])
                    currIndex[j] = 1 + prevIndex[j - 1];
                
                else
                    currIndex[j] = max(currIndex[j - 1], prevIndex[j]);
            }
            
           prevIndex = currIndex;
        }
        
        return prevIndex[n2];
    }
};
