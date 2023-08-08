//Refer HW notes for detailed explanation.
//rec
class Solution {
    
    private:
    
    bool isAllAsteriskTillIndex(string s, int ind)
    {
        for(int i = 0; i <= ind; i++)
            if(s[i] != '*')
                return false;
        
        return true;
    }
    
    bool rec(int i, int j, string& s1, string& s2)
    {
      //Base cases  
      if(j < 0)
        {
            if(i < 0) //1. both strings scanned completetly.
                return true; 
            else
                return isAllAsteriskTillIndex(s1, i); //2. s2 scanned completely. If s1 doesn't contain anything except '*', answer will be true.
        }
        
        if(i < 0) //3. if s2 is still left and s1 has been scanned, answer will be false.
            return false;
        
        if(s1[i] == s2[j] || s1[i] == '?') //if matching or '?'
            return rec(i - 1, j - 1, s1, s2);
        
        else if(s1[i] == '*')
            return (rec(i, j - 1, s1, s2) || rec(i - 1, j, s1, s2)); //either further scan s2 while i is still at '*' or if '*' is considered = 0, scann s1[i - 1] and s2[j]
        
        else //two different characters.
            return false;
    }
    
public:
    
    bool isMatch(string s, string p) {
        string s1 = p;
        string s2 = s;
        
        int n = s1.length();
        int m = s2.length();
        
        //vector<vector<int>> dp(n - 1)
        return rec(n - 1, m - 1, s1, s2);
    }
};


//memo
class Solution {
    
    private:
    
    bool isAllAsteriskTillIndex(string s, int ind)
    {
        for(int i = 0; i <= ind; i++)
            if(s[i] != '*')
                return false;
        
        return true;
    }
    
    bool rec(int i, int j, vector<vector<int>>& dp, string& s1, string& s2)
    {
        if(j < 0)
        {
            if(i < 0)
                return true;
            else
                return isAllAsteriskTillIndex(s1, i);
        }
        
        if(i < 0)
            return false;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        if(s1[i] == s2[j] || s1[i] == '?')
            return dp[i][j] = rec(i - 1, j - 1, dp, s1, s2);
        
        else if(s1[i] == '*')
            return dp[i][j] = (rec(i, j - 1, dp, s1, s2) || rec(i - 1, j, dp, s1, s2));
        
        else
            return false;
    }
    
public:
    
    bool isMatch(string s, string p) {
        string s1 = p;
        string s2 = s;
        
        int n = s1.length();
        int m = s2.length();
        
        vector<vector<int>> dp(n, vector<int>(m, -1));
        
        return rec(n - 1, m - 1, dp, s1, s2);
    }
};

//memo with shifted index
class Solution {
    
    private:
    
    bool isAllAsteriskTillIndex(string s, int ind)
    {
        for(int i = 0; i <= ind; i++)
            if(s[i] != '*')
                return false;
        
        return true;
    }
    
    bool rec(int i, int j, vector<vector<int>>& dp, string& s1, string& s2)
    {
        if(j == 0)
        {
            if(i == 0)
                return true;
            else
                return isAllAsteriskTillIndex(s1, i - 1);
        }
        
        if(i == 0)
            return false;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        if(s1[i - 1] == s2[j - 1] || s1[i - 1] == '?')
            return dp[i][j] = rec(i - 1, j - 1, dp, s1, s2);
        
        else if(s1[i - 1] == '*')
            return dp[i][j] = (rec(i, j - 1, dp, s1, s2) || rec(i - 1, j, dp, s1, s2));
        
        else
            return false;
    }
    
public:
    
    bool isMatch(string s, string p) {
        string s1 = p;
        string s2 = s;
        
        int n = s1.length();
        int m = s2.length();
        
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        
        return rec(n, m, dp, s1, s2);
    }
};

//tabu
class Solution {
    
    private:
    
    bool isAllAsteriskTillIndex(string s, int ind)
    {
        for(int i = 0; i <= ind; i++)
            if(s[i] != '*')
                return false;
        
        return true;
    }
    
public:
    
    bool isMatch(string s, string p) {
        
        string s1 = p;
        string s2 = s;
        
        int n = s1.length();
        int m = s2.length();
        
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
        
        // i = 0, j != 0 -> false
        // i = 0, j = 0 -> true
        // i != 0, j = 0 -> isAllaster
        
        dp[0][0] = true; //base case 1
        
        for(int j = 1; j <= m; j++)
            dp[0][j] = false;        //base case 3
        
        for(int i = 1; i <= n; i++)
        {
            dp[i][0] = isAllAsteriskTillIndex(s1, i - 1); //base case 2
            
            for(int j = 1; j <= m; j++)
            {
                if(s1[i - 1] == s2[j - 1] || s1[i - 1] == '?')
                    dp[i][j] = dp[i - 1][j - 1];

                else if(s1[i - 1] == '*')
                    dp[i][j] = (dp[i][j - 1] || dp[i - 1][j]);

                else
                    dp[i][j] = false;
            }
        }
        
        return dp[n][m];
    }
};

//space opt.
class Solution {
    
    private:
    
    bool isAllAsteriskTillIndex(string s, int ind)
    {
        for(int i = 0; i <= ind; i++)
            if(s[i] != '*')
                return false;
        
        return true;
    }
    
public:
    
    bool isMatch(string s, string p) {
        
        string s1 = p;
        string s2 = s;
        
        int n = s1.length();
        int m = s2.length();
        
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
        
        vector<bool> prevIndex(m + 1, false); //i = 0
        vector<bool> currIndex(m + 1, false);
        
        // i = 0, j != 0 -> false
        // i = 0, j = 0 -> true
        // i != 0, j = 0 -> isAllaster
        
        prevIndex[0] = true; //base case 1
        
        for(int j = 1; j <= m; j++)
            prevIndex[j] = false;        //base case 3
        
        for(int i = 1; i <= n; i++)
        {
            currIndex[0] = isAllAsteriskTillIndex(s1, i - 1); //base case 2
            
            for(int j = 1; j <= m; j++)
            {
                if(s1[i - 1] == s2[j - 1] || s1[i - 1] == '?')
                    currIndex[j] = prevIndex[j - 1];

                else if(s1[i - 1] == '*')
                    currIndex[j] = (currIndex[j - 1] || prevIndex[j]);

                else
                    currIndex[j] = false;
            }
            
            prevIndex = currIndex;
        }
        
        return prevIndex[m];
    }
};
