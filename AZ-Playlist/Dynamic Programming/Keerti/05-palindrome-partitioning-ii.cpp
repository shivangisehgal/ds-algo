//Memoization
//Find all palindromes via gap method / interval DP
//Try to partition at each index, if palindrome, cut count is increased, and recurse for next partition index.
//If successfully reached end, return 0 cut.
//Minimum of all cases will be answer.
// Palindrome DP precompute:
// TC: O(n^2)
// SC: O(n^2)
// Recursive + Memo:
// States = n (each index)
// Each state tries up to n partitions
// TC: O(n^2)
// SC: O(n)   // memo + recursion stack
// Overall:
// TC: O(n^2)
// SC: O(n^2)

// class Solution {
//     vector<vector<bool>> dp;
//     vector<int> memo;

//     void findAllPal(string& s) {
//         int n = s.length();
//         dp.resize(n, vector<bool>(n, false));

//         for (int len = 1; len <= n; len++) {
//             for (int i = 0; i <= n - len; i++) {
//                 int j = i + len - 1;

//                 if (s[i] == s[j]) {
//                     if (len <= 2)
//                         dp[i][j] = true;
//                     else
//                         dp[i][j] = dp[i + 1][j - 1];
//                 } else
//                     dp[i][j] = false;
//             }
//         }
//     }

//     int addPartition(int ind1, string& s) {
//         if (ind1 == s.length()) return 0;

//         if (memo[ind1] != -1) return memo[ind1];

//         int mini = INT_MAX;

//         for (int ind2 = ind1; ind2 < s.length(); ind2++) {
//             if (dp[ind1][ind2]) {
//                 mini = min(mini, 1 + addPartition(ind2 + 1, s));
//             }
//         }

//         return memo[ind1] = mini;
//     }

// public:
//     int minCut(string s) {
//         int n = s.length();
//         findAllPal(s);
        
//         memo.resize(n, -1);

//         return addPartition(0, s) - 1;
//     }
// };


//TAB
// Palindrome DP precompute:
// TC: O(n^2)
// SC: O(n^2)

// Bottom-up DP:
// Outer loop runs n times
// Inner loop runs up to n times
// TC: O(n^2)
// SC: O(n)   // memo array

// Overall:
// TC: O(n^2)
// SC: O(n^2)
class Solution {
    vector<vector<bool>> dp;
    vector<int> memo;

    void findAllPal(string& s) {
        int n = s.length();
        dp.resize(n, vector<bool>(n, false));

        for (int len = 1; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;

                if (s[i] == s[j]) {
                    if (len <= 2)
                        dp[i][j] = true;
                    else
                        dp[i][j] = dp[i + 1][j - 1];
                } else
                    dp[i][j] = false;
            }
        }
    }

    int addPartition(int ind1, string& s) {
        if (ind1 == s.length()) return 0;

        if (memo[ind1] != -1) return memo[ind1];

        int mini = INT_MAX;

        for (int ind2 = ind1; ind2 < s.length(); ind2++) {
            if (dp[ind1][ind2]) {
                mini = min(mini, 1 + addPartition(ind2 + 1, s));
            }
        }

        return memo[ind1] = mini;
    }

public:
    int minCut(string s) {
        int n = s.length();
        findAllPal(s);

        memo.resize(n + 1, -1);
        memo[n] = 0;

        for(int ind1 = n - 1; ind1 >= 0; ind1--){
            int mini = INT_MAX;

            for(int ind2 = ind1; ind2 < n; ind2++){
                if(dp[ind1][ind2]){ //isPal
                    mini = min(mini, 1 + memo[ind2 + 1]);
                }
            }

            memo[ind1] = mini;
        }

        return memo[0] - 1;;
    }
};
