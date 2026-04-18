// Subseq => not necessarily contig.=> dp can store length as well.
    //   - If s[i] == s[j], both characters contribute to the palindrome:
    //       dp[i][j] = 2 + dp[i+1][j-1]
    //   - If s[i] != s[j], skip one end and take the best:
    //       dp[i][j] = max(dp[i][j-1], dp[i+1][j])
    //
    // ANSWER: dp[0][n-1] = LPS of the entire string.
    //
    // TC: O(n^2)
    // SC: O(n^2)
    
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.length();

        vector<vector<int>> dp(n, vector<int>(n, 0));

        for(int len = 1; len <= n; len++){
            for(int i = 0; i <= n - len; i++){
                
                int j = len + i - 1;

                if(i == j)
                    dp[i][j] = 1;

                else if(s[i] == s[j]){
                    dp[i][j] = 2 + dp[i + 1][j - 1];
                }
                else {
                    dp[i][j] = max(dp[i][j - 1], dp[i + 1][j]);
                }
            }
        }

        return dp[0][n - 1];

    }
};
