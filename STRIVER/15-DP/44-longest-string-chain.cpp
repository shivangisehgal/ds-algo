class Solution {
    private:
    bool validate(string s1, string s2) //s1 should be greater from s2 by only 1 element, rest should be same
    {
        int n1 = s1.length();
        int n2 = s2.length();
        
        if(n1 - n2 != 1)
            return false;
        
        int i1 = 0;
        int i2 = 0;
        
        
        while(i1 < n1)
        {
            if(s1[i1] == s2[i2])
            {
                i1++;
                i2++;
            }
            
            else
                i1++;
        }
        
        //i1 is now n1
        if(i2 == n2)
            return true;
        
        return false;
    }
    
public:
    
    static bool comp(string& s1, string& s2)
    {
        return s1.length() < s2.length();
    }
    
    int longestStrChain(vector<string>& words) {
        
        sort(words.begin(), words.end(), comp); //we're actually taking subsets in the vector of strings.
        
        int n = words.size();
        vector<int> dp(n, 1);
        int maxlen = 0;
        for(int i = 0; i < n; i++)
        {
            for(int prev = 0; prev <= i - 1; prev++)
            {
                if(validate(words[i], words[prev]))
                {
                    dp[i] = max(1 + dp[prev], dp[i]);
                }
            }
            
            maxlen = max(maxlen, dp[i]); 
        }
        
        return maxlen;
    }
};
