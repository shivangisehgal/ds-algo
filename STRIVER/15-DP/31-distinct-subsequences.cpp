//"babgbag", "bag"
//f(n-1, m-1) would give the number of distinct subsequences of s2[0...j] in s1[0...i]
//"bab|g|ba|g|", "ba|g|" -> if j = m - 1, comparing g with the ith, and also the rest of the substring for finding the next g 

// -> f(i - 1, j - 1) -> s1[i] = s2[j], move to i - 1 & j - 1 to compare 'a's 
// -> f(i - 1, j) -> s1[i] = s2[j], move to i - 1 to compare next 'g'

//-> f(i - 1, j) -> s1[i] != s2[j], move to i - 1 to compare 'g'

//once all the chars of s2 have been scanned, that'll mean we have got the subseq. of s2 in s1. return 1.
//once all the chars of s1 have been scanned, and s2 is still left, that'll mean we have not got a char s2[j] anywhere in s1. return 0.

//memo - without index shift
class Solution {
private:
    int rec(int i, int j, vector<vector<int>>& dp, string& s, string& t)
    {
        if(j < 0)
            return 1;
        
         if(i < 0)
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        if(s[i] == t[j])
            return dp[i][j] = rec(i - 1, j - 1, dp, s, t) + rec(i - 1, j, dp, s, t);
        else
            return dp[i][j] = rec(i - 1, j, dp, s, t);
    }
    
public:
    int numDistinct(string s, string t) {
        
        int n = s.length();
        int m = t.length();
        
        vector<vector<int>> dp(n, vector<int>(m, -1));
        
        return rec(n - 1, m - 1, dp, s, t);
    }
};


//memo WITH INDEX SHIFTING
class Solution {
private:
    int rec(int i, int j, vector<vector<int>>& dp, string& s, string& t)
    {
        if(j == 0)
            return 1;
        
         if(i == 0)
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        if(s[i - 1] == t[j - 1])
            return dp[i][j] = rec(i - 1, j - 1, dp, s, t) + rec(i - 1, j, dp, s, t);
        else
            return dp[i][j] = rec(i - 1, j, dp, s, t);
    }
    
public:
    int numDistinct(string s, string t) {
        
        int n = s.length();
        int m = t.length();
        
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1)); //index shifting
        
        return rec(n, m, dp, s, t);
    }
};

//tabulation
class Solution {
public:
    int numDistinct(string s, string t) {
        
        int n = s.length();
        int m = t.length();
        
        vector<vector<double>> dp(n + 1, vector<double>(m + 1, -1)); //index shifting
        
        for(int j = 0; j <= m; j++)
            dp[0][j] = 0;
        
        for(int i = 0; i <= n; i++) //recursion mein pehle -> iterative mein baad
            dp[i][0] = 1;
        
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                if(s[i - 1] == t[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        
        return (int)dp[n][m];
    }
};

//space opt.
class Solution {
public:
    int numDistinct(string s, string t) {
        
        int n = s.length();
        int m = t.length();
        
        vector<double> prevIndex(m + 1, 0);
        vector<double> currIndex(m + 1, 0);
        
        //dp[0][j] = 0: first row should be zero
        //dp[i][0]: first element of each row should be 1.
        
        prevIndex[0] = 1;
        currIndex[0] = 1;
        
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                if(s[i - 1] == t[j - 1])
                    currIndex[j] = prevIndex[j - 1] + prevIndex[j];
                else
                    currIndex[j] = prevIndex[j];
            }
            
            prevIndex = currIndex;
        }
        
        return (int)prevIndex[m];
    }
};
