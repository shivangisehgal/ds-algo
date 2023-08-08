//memo
class Solution {
private:
    int rec(int i, int j, vector<vector<int>>& dp, string s1, string s2)
    {
        if(i < 0)
            return j + 1; //j + 1 elements still remaining to be formed.
        
        if(j < 0)
            return i + 1; //i + 1 elements still remaining to be deleted.
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        if(s1[i] == s2[j])
            return dp[i][j] = rec(i - 1, j - 1, dp, s1, s2);
        
        else
        {
            int insertion = 1 + rec(i, j - 1, dp, s1, s2); //if s2[j] is inserted at i + 1
            int deletion = 1 + rec(i - 1, j, dp, s1, s2); //if s1[i] is deleted
            int replacement = 1 + rec(i - 1, j - 1, dp, s1, s2); // if s1[i] is replaced by s2[j]
                
            return dp[i][j] = min(replacement, min(insertion, deletion));
        }
    }
    
public:
    int minDistance(string word1, string word2) {
        
        int n = word1.length();
        int m = word2.length();
        
        vector<vector<int>> dp(n, vector<int>(m, -1));
        
        return rec(n - 1, m - 1, dp, word1, word2);
    }
};

//memo with shifted index 
class Solution {
private:
    int rec(int i, int j, vector<vector<int>>& dp, string s1, string s2)
    {
        if(i == 0)
            return j; //j + 1 elements still remaining to be formed.
        
        if(j == 0)
            return i; //i + 1 elements still remaining to be deleted.
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        if(s1[i - 1] == s2[j - 1])
            return dp[i][j] = rec(i - 1, j - 1, dp, s1, s2);
        
        else
        {
            int insertion = 1 + rec(i, j - 1, dp, s1, s2); //if s2[j] is inserted at i + 1
            int deletion = 1 + rec(i - 1, j, dp, s1, s2); //if s1[i] is deleted
            int replacement = 1 + rec(i - 1, j - 1, dp, s1, s2); // if s1[i] is replaced by s2[j]
                
            return dp[i][j] = min(replacement, min(insertion, deletion));
        }
    }
    
public:
    int minDistance(string word1, string word2) {
        
        int n = word1.length();
        int m = word2.length();
        
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        
        return rec(n, m, dp, word1, word2);
    }
};

//tabu
class Solution {
public:
    int minDistance(string word1, string word2) {
        
        int n = word1.length();
        int m = word2.length();
        
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        
        for(int i = 0; i <= n; i++)
            dp[i][0] = i;
        
        for(int j = 0; j <= m; j++)
            dp[0][j] = j;
        
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                if(word1[i - 1] == word2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                
                else
                {
                    int insertion = 1 + dp[i][j - 1];
                    int deletion = 1 + dp[i - 1][j];
                    int replacement = 1 + dp[i - 1][j - 1];
                    
                   dp[i][j] = min(replacement, min(insertion, deletion));
                }
            }
        }
        
        return dp[n][m];
    }
};

//space opt.
class Solution {
public:
    int minDistance(string word1, string word2) {
        
        int n = word1.length();
        int m = word2.length();
        
        //vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        
        vector<int> prevIndex(m + 1, 0);
        vector<int> currIndex(m + 1, 0);
        
        //dp[0][j] = j; -> every element of first row = j.
        //dp[i][0] = i; -> first element of every row = i
        
        for(int j = 0; j <= m; j++)
        {
            prevIndex[j] = j;
            currIndex[j] = j;
        }
        
        for(int i = 1; i <= n; i++)
        {
            for(int j = 0; j <= m; j++)
            {
                
                if(j == 0)
                    currIndex[j] = i;
                
                else if(word1[i - 1] == word2[j - 1])
                    currIndex[j] = prevIndex[j - 1];
                
                else
                {
                    int insertion = 1 + currIndex[j - 1];
                    int deletion = 1 + prevIndex[j];
                    int replacement = 1 + prevIndex[j - 1];
                    
                   currIndex[j] = min(replacement, min(insertion, deletion));
                }
            }
            
            prevIndex = currIndex;
        }
        
        return prevIndex[m];
    }
};
