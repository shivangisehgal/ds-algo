//brute, groot -> bgruoote
//blue, bleed -> blueed

//length of SCS = (n1 - LCS) + (n2 - LCS) + LCS

class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        
        int n1 = str1.length();
        int n2 = str2.length();
        
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, -1));
        
        for(int i = 0; i <= n1; i++)
            dp[i][0] = 0;
        
        for(int j = 0; j <= n2; j++)
            dp[0][j] = 0;
        
        
        for(int i = 1; i <= n1; i++)
        {
            for(int j = 1; j <= n2; j++)
            {

                if(str1[i - 1] == str2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                
                else
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
        
        int lcsLen = dp[n1][n2];
        int different1 = n1 - lcsLen;
        int different2 = n2 - lcsLen;
        
        //sub question:
        int scsLen = different1 + different1 + lcsLen;
        
        string ans = "";
        
      int i = n1, j = n2;
        
       while (i > 0 && j > 0) 
       {
            if (str1[i - 1] == str2[j - 1]) 
            {
                  ans = str1[i-1] + ans;
                  i--;
                  j--;
            } 
           
           else if (dp[i - 1][j] > dp[i][j - 1]) 
           {
                ans = str1[i-1] + ans;
                i--;
            } 
           
           else 
           {
                ans = str2[j-1] + ans;
                j--;
            }
        }
        
        while(i > 0)
        {
              ans = str1[i - 1] + ans;
              i--;
         }
         
        while(j > 0)
         {
              ans = str2[j - 1] + ans;
              j--;
          }

        return ans;
    }
};
