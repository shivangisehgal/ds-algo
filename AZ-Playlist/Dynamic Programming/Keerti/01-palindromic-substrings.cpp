//Direct Tabulation method

class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        vector<vector<bool>> dp(n, vector<bool>(n, false));

        // GAP METHOD / INTERVAL DP
        // -----------------------------------------------------------
        // dp[i][j] = true if substring s[i..j] is a palindrome.
        //
        // WHY GAP METHOD?
        // For string/subsequence questions, we only care about conditions
        // where (i >= j). The 2D dp table looks like:
        //
        //        a  b  c  d  a  a
        //     a [.  X  X  X  X  X]   <- we only fill the upper triangle
        //     b [   .  X  X  X  X]      (i <= j), cells marked X are
        //     c [      .  X  X  X]      don't-care (i > j), we don't
        //     d [         .  X  X]      need them.
        //     a [            .  X]
        //     a [               .]
        //          ^
        //          diagonal = base case (single chars)
        //
        // We iterate by LENGTH (gap) so smaller subproblems are always
        // solved before larger ones (bottom-up).
        //
        // TOP-DOWN perspective (memoization):
        //   f(i,j) ──> f(i+1, j-1)   [shrinks inward each call]
        //   notice we always move: bigger length -> smaller length
        //   => if we call all bigger lengths first, smaller lengths
        //      are already cached when we need them.
        //
        // BOUNDS:
        // j <= n-1
        // len = j - i + 1  =>  j = len + i - 1 <= n-1  =>  i <= n - len

        int count = 0;

        for(int len = 1; len <= n; len++){
            // For len=3, filling cells diagonally like:
            //
            //   i: 0  1  2  3  4  5
            //      a  b  c  d  a  a
            //   0  .  
            //   1     .        
            //   2        .           <- len=1: fill main diagonal (base case)
            //   3           .
            //   4              .
            //   5                 .
            //
            //   0  .  F
            //   1     .  F
            //   2        .  F        <- len=2: one step above diagonal
            //   3           .  F
            //   4              .  T  (s[4]='a'==s[5]='a' => T)
            //   5                 .
            //
            //   0  .  F  F
            //   1     .  F  F
            //   2        .  F  F     <- len=3: two steps above diagonal
            //   3           .  F  T  (dp[3][5]: s[3]='d'!=s[5]='a' => F)
            //   ...
            //
            // Each cell (i,j) depends on the cell diagonally inward (i+1,j-1):
            //
            //   (i,j) <──────────── check s[i]==s[j]?
            //      \                      |
            //       \                     v
            //        (i+1,j-1) ──> if equal, inherit this value
            //
            // Arrow diagram of dependency:
            //
            //   dp[i][j]
            //      ^
            //      |  (diagonal jump, len shrinks by 2)
            //   dp[i+1][j-1]
            //
            // So filling by increasing length guarantees dp[i+1][j-1]
            // is already computed when we need dp[i][j].  ✓

            for(int i = 0; i <= n - len; i++){

                int j = len + i - 1;

                // BASE CASE 1 (len=1): single char, always palindrome
                //   . <- diagonal cell, set TRUE
                if(i == j)
                    dp[i][j] = true;

                else if(s[i] == s[j]){
                    // BASE CASE 2 (len=2): "aa" style — adjacent equal chars
                    //   [T] <- set TRUE directly (can't use dp[i+1][j-1], i>j)
                    //   special case noted in notes: i==j => set true, i>j => set true
                    if(j == i + 1)
                        dp[i][j] = true;
                    else
                        // NORMAL TRANSITION:
                        //
                        //  f(0,5)  ──>  f(1,4)  ──>  f(2,3)  ...
                        //    |             |             |
                        //  s[0]?=s[5]   s[1]?=s[4]   s[2]?=s[3]
                        //
                        //  dp table arrow (going inward diagonally):
                        //
                        //    j-1  j
                        //  i  [    ]
                        //      \
                        //  i+1  [dp[i+1][j-1]] <── this was filled in a
                        //                          previous (smaller) len pass
                        dp[i][j] = dp[i + 1][j - 1];
                }
                else
                    // s[i] != s[j] => not a palindrome
                    dp[i][j] = false;

                // Every (i,j) where dp[i][j]==true is a valid palindromic substring
                if(dp[i][j])
                    count++;
            }
        }

        return count;
    }
};
