//Memoization: 
// TC: O(n^2)
// SC: O(n^2) dp + O(n) recursion stack

// isPalindrome(i, j) → whether substring s[i...j] is palindrome.  
// If s[i] == s[j]:
//     If length ≤ 2 → TRUE
//     Else → depends on isPalindrome(i+1, j-1)
// Else → FALSE

// Try all substrings and track the longest.

// class Solution {
// public:
//     vector<vector<int>> dp;

//     bool isPalindrome(int i, int j, string &s) {
//         if (i >= j) 
//             return true;

//         if (dp[i][j] != -1) 
//             return dp[i][j];

//         if (s[i] == s[j]) {
//             return dp[i][j] = isPalindrome(i + 1, j - 1, s);
//         }

//         return dp[i][j] = false;
//     }

//     string longestPalindrome(string s) {
//         int n = s.length();
//         dp.resize(n, vector<int>(n, -1));

//         int maxLen = 0;
//         int start = 0;

//         for (int i = 0; i < n; i++) {
//             for (int j = i; j < n; j++) {
//                 if (isPalindrome(i, j, s)) {
//                     if (j - i + 1 > maxLen) {
//                         maxLen = j - i + 1;
//                         start = i;
//                     }
//                 }
//             }
//         }

//         return s.substr(start, maxLen);
//     }
// };

//METHOD 1: (MEMO -> TAB)
// TC: O(n^2)
// SC: O(n^2)
// class Solution {
// public:
//     string longestPalindrome(string s) {
//         int n = s.length();
//         vector<vector<bool>> dp(n, vector<bool>(n, false));

//         int maxLen = 1;
//         int start = 0;

//         for (int i = n - 1; i >= 0; i--) {
//             for (int j = i; j < n; j++) {

//                 if (s[i] == s[j]) {
//                     if (j - i <= 1) {
//                         dp[i][j] = true;
//                     } else {
//                         dp[i][j] = dp[i + 1][j - 1];
//                     }
//                 } else {
//                     dp[i][j] = false;
//                 }

//                 if (dp[i][j] && (j - i + 1 > maxLen)) {
//                     maxLen = j - i + 1;
//                     start = i;
//                 }
//             }
//         }

//         return s.substr(start, maxLen);
//     }
// };


//METHOD 2: TAB (GAP METHOD)
//Notice how we dont' ever require cases of (j < i) and only ever require the diagonal.
//And we always know the starting cases (i == j) and (i == j + 1),
//and we always fill for bigger lengths..
//rather than writing i & j, we can write length based..
//the crux is
// Whenever DP depends on: (i+1, j-1), use length-based loops (GAP METHOD)

// TC: O(n^2)
// SC: O(n^2)

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        vector<vector<bool>> dp(n, vector<bool>(n, false));

        int start = 0;
        int maxLen = 1;

        // len = length of substring
        //j <= n - 1 => i + len - 1 <= n - 1 => i <= n - len
        for (int len = 1; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;

                if (s[i] == s[j]) {
                    if (len <= 2) {
                        dp[i][j] = true;
                    } else {
                        dp[i][j] = dp[i + 1][j - 1];
                    }
                } else {
                    dp[i][j] = false;
                }

                if (dp[i][j] && len > maxLen) {
                    maxLen = len;
                    start = i;
                }
            }
        }

        return s.substr(start, maxLen);
    }
};
